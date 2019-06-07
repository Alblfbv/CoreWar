# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 20:42:30 by mndhlovu          #+#    #+#              #
#    Updated: 2019/05/30 11:55:06 by mndhlovu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = gcc
FLAGS = -Wall -Werror -Wextra -g -O0 -fsanitize=address
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes \
		 libft/includes

SRC = vm_mem_utils.c vm_parser_model.c vm_option_utils.c\
	  main.c vm_error_utils.c vm_file_reader.c \
	  vm_primary_parser.c \

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
		@echo -e "$(YEL)===> $(GRE)$(NAME) : $(YEL) COREWAR COMPILATION <===$(DEF)"
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
