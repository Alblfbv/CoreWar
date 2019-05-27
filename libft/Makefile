# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 16:48:32 by mndhlovu          #+#    #+#              #
#    Updated: 2019/03/25 17:00:53 by mndhlovu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAKEFLAGS	+=	--no-print-directory

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBDIR = 
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

SRC = list_utils/ft_lstadd.c list_utils/ft_lstdel.c list_utils/ft_lstdelone.c \
	  list_utils/ft_lstiter.c list_utils/ft_lstmap.c list_utils/ft_lstnew.c \
	  \
	  basic_utils/ft_isalnum.c basic_utils/ft_isalpha.c basic_utils/ft_isascii.c \
	  basic_utils/ft_isdigit.c basic_utils/ft_isprint.c basic_utils/ft_putchar_fd.c \
	  basic_utils/ft_putchar.c basic_utils/ft_putendl_fd.c basic_utils/ft_putnbr_fd.c \
	  basic_utils/ft_putnbr.c basic_utils/ft_putstr_fd.c basic_utils/ft_putstr.c \
	  \
	  memory_utils/ft_bzero.c memory_utils/ft_memalloc.c memory_utils/ft_memchr.c \
	  memory_utils/ft_memccpy.c memory_utils/ft_memcmp.c memory_utils/ft_memcpy.c \
	  memory_utils/ft_memmove.c memory_utils/ft_memset.c \
	  \
	  num_utils/ft_atoi.c num_utils/ft_itoa.c \
	  \
	  str_utils/ft_strbdel.c str_utils/ft_strcat.c str_utils/ft_strchr.c \
	  str_utils/ft_strclr.c str_utils/ft_strcmp.c str_utils/ft_strcpy.c \
	  str_utils/ft_strdel.c str_utils/ft_strdup.c str_utils/ft_strequ.c \
	  str_utils/ft_striter.c str_utils/ft_striteri.c str_utils/ft_strjoin.c \
	  str_utils/ft_strlcat.c str_utils/ft_strlen.c str_utils/ft_strmap.c \
	  str_utils/ft_strmapi.c str_utils/ft_strncat.c str_utils/ft_strncmp.c \
	  str_utils/ft_strncpy.c str_utils/ft_strnequ.c str_utils/ft_strnew.c \
	  str_utils/ft_strnstr.c str_utils/ft_strrchr.c str_utils/ft_strsplit.c \
	  str_utils/ft_strstr.c str_utils/ft_strsub.c str_utils/ft_strtrim.c \
	  str_utils/ft_tolower.c str_utils/ft_toupper.c \
	  gnl/get_next_line.c \
	  \
	  ft_printf/ft_base_utils.c ft_printf/ft_float_handlers.c ft_printf/ft_gen_utils.c \
	  ft_printf/ft_handlers.c ft_printf/ft_m_handler_util.c ft_printf/ft_nbr_utils.c \
	  ft_printf/ft_padding_utils.c ft_printf/ft_printf.c ft_printf/ft_putnbr_mod.c \
	  ft_printf/ft_putnbr_utils.c ft_printf/ft_type_dec.c \
	  ft_printf/ft_type_f.c ft_printf/ft_type_d_cap.c ft_printf/ft_type_char.c \
	  ft_printf/ft_type_o_cap.c ft_printf/ft_type_o.c ft_printf/ft_type_p.c \
	  ft_printf/ft_type_perc.c ft_printf/ft_type_s.c ft_printf/ft_type_u_cap.c \
	  ft_printf/ft_type_xux.c ft_printf/ft_write_utils.c \

OBJ		=	$(SRC:.c=.o)

LIB		=

#	Prefixes
OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP 		=	$(foreach dir, $(INCDIR), -I$(dir))
OBJS_DIRS	=	$(sort $(dir $(OBJP)))
#	Default Rule
DRULE	=	all

default :
		@echo -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) START RULE : $(DRULE) <===$(DEF)"
		@make $(DRULE)
		@echo -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) END RULE : $(DRULE) <===$(DEF)"

all   : $(NAME)

re    : fclean default

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
		$(CC) $(FLAGS) -c -o $@ $^ -I$(INCDIR)

$(OBJDIR):
		@echo -e "$(YEL)===> $(GRE)$(NAME) : $(YEL) Objects Compilation <===$(DEF)"
		@mkdir -p $(OBJDIR)
		@mkdir -p $(OBJS_DIRS)

$(NAME)	:	$(OBJDIR) $(OBJP)
		@echo -e "$(YEL)===> $(GRE)$(NAME) : $(YEL) Binary Compilation <===$(DEF)"
		ar rc $(NAME) $(OBJP)
		ranlib $(NAME)

clean:
		@rm -rf $(OBJDIR)
		@echo "clean    [DONE]"

fclean: clean
		@rm -f $(NAME)
		@echo "fclean    [DONE]"

.PHONY	=	default all re clean fclean $(OBJDIR) $(NAME)

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
