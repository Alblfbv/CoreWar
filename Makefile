# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
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
=======
#    By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 13:41:26 by mnishimo          #+#    #+#              #
#    Updated: 2019/06/04 18:56:25 by mnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM_NAME = corewar
LIBFT = libftprintf.a
OBJ_DIR = obj

CC = gcc -g
#CFLAGS = -Wall -Werror -Wextra
#CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
CFLAGS = -g -fsanitize=address

RM = rm -rf
LDIR = -L libftprintf/ -lftprintf
INCLUDES = -I includes/  -I libftprintf/includes

HEADER =  $(addprefix includes/, corewar.h op.h)

VM_SRC = $(addprefix src/vm/, main.c init_corewar.c process.c instructions.c \
		 decode.c ocp.c free.c lst_util.c util.c memory_util.c prcs_util.c) 
VM_INST_SRC = $(addprefix src/vm/instructions/, inst01_live.c inst02_ld.c \
		inst03_st.c inst04_add.c inst05_sub.c inst06_and.c inst07_or.c \
		inst08_xor.c inst09_zjmp.c inst0a_ldi.c inst0b_sti.c inst0c_fork.c \
		inst0d_lld.c inst0e_lldi.c inst0f_lfork.c inst10_aff.c)

VM_OBJ = $(VM_SRC:src/vm/%.c=obj/%.o)
VM_INST_OBJ = $(VM_INST_SRC:src/vm/instruction/%.c=obj/%.o)

.PHONY: all fclean clean re

all: $(VM_NAME)

$(LIBFT):
	make -C libftprintf/

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

obj/%.o: src/vm/%.c $(HEADER) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(VM_NAME): $(LIBFT) $(VM_OBJ) $(VM_INST_OBJ)
	$(CC) $(CFLAGS)  -o $(VM_NAME) $(VM_OBJ) $(VM_INST_OBJ) $(LDIR) $(INCLUDES)

clean:
	$(RM) $(OBJ_DIR)
	make -C libftprintf/ clean

fclean: clean
	$(RM) $(VM_NAME)
	make -C libftprintf/ fclean

re: fclean all
>>>>>>> vm
