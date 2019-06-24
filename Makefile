# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 20:42:30 by mndhlovu          #+#    #+#              #
#    Updated: 2019/06/23 18:19:04 by mndhlovu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = disassembly
CC = gcc
FLAGS = -g -O0 -fsanitize=address -lncurses
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes \
		 libft/includes

SRC = dis_error_utils.c vm_visu_utils.c vm_visu_output.c\
	  main.c dis_parser_utils.c dis_source_parser.c dis_multi_utils.c\
	  decode.c dis_decode_utils.c dis_visu_extr.c dis_gen_utils.c

OBJ = $(SRC:.c=.o)

LIB	= ft

OBJP	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP 	=	$(foreach dir, $(INCDIR), -I$(dir))
LLIBP =		$(addprefix -l, $(LIB))
LIBNAME =	$(addprefix lib, $(LIB))
LIBP =		$(addprefix -L, $(LIBNAME)/)

DRULE	=	all

#	Main rules
default	:
		@echo -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) START RULE : $(DRULE) <===$(DEF)"
		@make $(DRULE)
		@echo -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) END RULE : $(DRULE) <===$(DEF)"

all		:	libcomp $(OBJDIR) $(NAME)

re		:	fclean default

#	Compilation rules
libcomp	:
		@echo -e "$(YEL)===> $(GRE)lib$(LIB)$(YEL) Compilation <===$(DEF)"
		@make all -C lib$(LIB)
		@echo -e "$(YEL)===> $(GRE)$(NAME) : $(YEL) Objects Compilation <===$(DEF)"

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
		$(CC) $(FLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR)	:
		@mkdir -p $(OBJDIR)

$(NAME)	:	$(OBJP)
		@echo -e "$(YEL)===> $(GRE)$(NAME) : $(YEL) DISASSEMBLY COMPILATION <===$(DEF)"
		$(CC) $(FLAGS) -o $@ $^ $(INCP) $(LIBP) $(LLIBP)

#	Cleaner rules
clean	:
		@echo -e "$(RED)===> $(GRE)$(NAME) : $(RED) Deleting Object Files <===$(DEF)"
		@rm -rf $(OBJDIR)

fclean	:	clean
		@echo -e "$(RED)===> $(GRE)$(NAME) : $(RED) Deleting Binary File <===$(DEF)"
		@rm -f $(NAME)
		@echo -e "$(RED)===> Delete $(GRE)lib$(LIB)$(RED) <===$(DEF)"
		@make fclean -C lib$(LIB)

#	Phony
.PHONY	=	default all re clean fclean libcomp $(OBJDIR) $(NAME)
#	Color
DEF		=	\033[0m
BLA		=	\033[30m
BLI		=	\033[5m
BLU		=	\033[34m
CYA		=	\033[36m
GRA		=	\033[1m
GRE		=	\033[32m
PUR		=	\033[35m
RED		=	\033[31m
SOU		=	\033[4m
WHI		=	\033[37m
YEL		=	\033[33m
