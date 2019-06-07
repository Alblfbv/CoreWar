/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:51:52 by mnishimo          #+#    #+#             */
/*   Updated: 2019/06/06 21:43:23 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "libft.h"
#include "op.h"
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
# define IO_ERROR 1
# define OPT_ERROR 2
# define ML_ERROR 3
# define US_ERROR 0
# define COLOR_RED  "\x1b[31m"
# define COLOR_GREEN  "\x1b[32m"
# define COLOR_YEL  "\x1b[33m"

typedef	unsigned long long	t_ull;
typedef	unsigned long long	t_uc;
typedef	uint8_t				t_reg_type;
typedef uint16_t			t_ind_type;
typedef uint32_t			t_dir_type;
typedef	uint8_t				t_ocp;

typedef struct	s_file
{
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	unsigned char	*instr;
	unsigned int	prog_size;
	char		*file_name;
}				t_file;

typedef struct	s_process
{
	int			c_id;
	int			p_id; // this might be useless
	t_dir_type	regs[REG_NUMBER];
	int			wait_c;
	int			is_alive;
	t_uc		*pc;
	int			carry;
}				t_process;

typedef enum	e_argtype
{
	// if we want to represent this by 3 bit, change to defined T_DIR/T_IND/T_REG
	e_reg = T_REG,
	e_dir = T_DIR,
	e_ind = T_IND,
}				t_argtype;

typedef enum	e_argtype
{
	// if we want to represent this by 3 bit, change to defined T_DIR/T_IND/T_REG
	e_reg = T_REG,
	e_dir = T_DIR,
	e_ind = T_IND,
}				t_argtype;

typedef union	u_argval
{
	t_reg_type	u_reg_val;
	t_ind_type	u_ind_val;
	t_dir_type	u_dir_val;
}				t_argval;

typedef enum	e_opcode
{
	e_err,
	e_live,
	e_ld,
	e_st,
	e_add,
	e_sub,
	e_and,
	e_or,
	e_xor,
	e_zjmp,
	e_ldi,
	e_sti,
	e_fork,
	e_lld,
	e_lldi,
	e_lfork,
	e_aff,
}				t_opcode;

typedef struct	s_arg
{
	t_argtype	type;
	t_argval	value;
}				t_arg;

typedef struct	s_game
{
	t_file		*file[MAX_PLAYERS + 1]; // the last ptr is NULL
	int			nbr_champs;
	int			nbr_fout;
	int			er_state;
}				t_game;

typedef struct	s_inst
{
	void	*op;
	t_arg	args[MAX_ARGS_NUMBER];
}				t_inst;

typedef	void (*t_inst_func)(t_game *, t_process *, t_inst *);

typedef struct	s_op
{
	t_opcode	opcode;
	int			n_args; //nbr of args
	int			args[MAX_ARGS_NUMBER];
	int			wait;
	int			ocp;
	int			rstrct; //if %mod should be aplied or not, memory restriction
	int			carry; //can modify the carry or not
	int			dir_bytes;
	t_inst_func	function;
}				t_op;

/*
 * decode.c
 * */
t_uc	*decode(t_uc *dump, t_uc *pc, t_inst *inst);


/*
 * ocp.c
 * */
int		decode_ocp(t_uc *addr, t_inst *inst);

/*
 * free.c
 * */
void	free_game(t_game *game);

/*
 * util.c
 * */
t_op	*get_op(t_inst *inst);

/*
 * memory_utils.c
 * */
t_uc	*access_ptr(t_uc *dump, t_uc *pc, size_t offset);
void	read_dump(t_uc *dump, t_uc *src, void *dst, size_t size);
void	write_dump(t_uc *dump, void *src, t_uc *dst, size_t size);
t_dir_type	*get_arg(t_process *caller, t_uc *dump, t_arg *arg, int rstr);

/*
 * lst_util.c
 * */
void	del_lstprcs(void *cnt, size_t size);

/*
 *	Parser utility functions
 * */
int                 	dis_source_parser(int fd, char *file, t_game *game);
int                     dis_catch_error(int flag, char *av);
int                     dis_file_reader(char *file, t_game *game);
void                	dis_debug(int flag, int ac, char **av, t_game *game);
unsigned int			vm_endian_conversion(unsigned int val);
int                 	dis_source_parser(int fd, t_game *game);
#endif
