
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:51:52 by mnishimo          #+#    #+#             */
/*   Updated: 2019/05/30 00:39:20 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define IO_ERROR 1
# define OPT_ERROR 2
# define ML_ERROR 3
# define US_ERROR 0
# define COLOR_RED  "\x1b[31m"
# define COLOR_GREEN  "\x1b[32m"
# define COLOR_YEL  "\x1b[33m"

#include "libft.h"
#include "op.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef	unsigned long long	t_ull;
typedef	unsigned long long	t_uc;
typedef	uint8_t				t_reg_type;
typedef uint16_t			t_ind_type;
typedef uint32_t			t_dir_type;
typedef	uint8_t				t_ocp;
//typedef	void (*func)(t_game *, t_process *, t_inst *)	t_inst_func;

typedef struct	s_champ
{
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	unsigned char	*instr;
	unsigned int	prog_size;
	int		id; // this should be created in init and copied in r0
	int		prcs_c;
	int		live_c;
}				t_champ;

typedef struct	s_process
{
	int		id;
	int		prcs_id;
	t_uc	*regs[REG_NUMBER];
	int		wait_c;
	int		is_alive;
	t_uc	*pc;
	int		carry;
}				t_process;

typedef enum	e_argtype
{
	// if we want to represent this by 3 bit, change to defined T_DIR/T_IND/T_REG
	e_reg = T_REG,
	e_dir = T_DIR,
	e_ind = T_IND,
}				t_argtype;

typedef union	u_argval
{
	t_reg_type	reg_val;
	t_ind_type	ind_val;
	t_dir_type	dir_val;
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

typedef struct	s_op
{
	t_opcode	opcode;
	int			n_args; //nbr of args
	int			*args; 
	int			wait;
	int			ocp;
	int			rstrct; //if %mod should be aplied or not, memory restriction
	int			carry; //can modify the carry or not
	int			dir_bytes;
	//t_inst_func	function;
}				t_op;

typedef struct	s_inst
{
	t_op	*op;
	t_arg	*arg[MAX_ARGS_NUMBER];
}				t_inst;

/*
PARSER STRUCTS AND UTILITIES
*/
typedef struct 	s_option
{
	char		option[3];
	int			(*f)();
}				t_option;

/*
*END OF PARSER STRUCTS AND UTILITIES
*/

typedef struct	s_game
{
	t_champ	champs[MAX_PLAYERS + 1]; // the last ptr is NULL
	t_list		*prcs; //cache coherence and use t_list? young prcs is top
	t_ull		nbr_cycle; //-dump option
	t_ull		nbr_s_cycle; //-s option
	int			nbr_champs;
	int			d_state;
	int			n_state;
	int			s_state;
	int			a_state;
	int			pl_state;
	int			pl_number;
	int			deb_state;
	int			v_state;
	int			pv_number;
	int			fl_error;	
	t_ull		n_prog_num;
	t_ull		cycle;
	t_ull		cycle_d;
	t_ull		c_checked;
	t_ull		cycle_to_die;
	t_uc		memdump[MEM_SIZE];
}				t_game;

/*
*Parser utility function
*/


void            		vm_init_flags(t_game *game);
t_ull               	vm_get_value(char *sval);
int                     vm_catch_error(int flag, char *av);
int                     vm_file_reader(char *file, t_game *game);
void                	vm_debug(int flag, int ac, char **av, t_game *game);
unsigned int			vm_endian_conversion(unsigned int val);
int	                    vm_opt_reader(int ac, char **av, t_game *game);
int                     vm_opt_dump(int index, char **av, t_game *game);
int                     vm_opt_debug(int index, char **av, t_game *game);
int                     vm_opt_aff(int index, char **av, t_game *game);
int                     vm_opt_n(int index, char **av, t_game *game);
int                     vm_opt_soption(int index, char **av, t_game *game);
int                 	vm_primary_parser(int fd, t_game *game);

/*
*MODEL FUNCTIONS
*/
//int						vm_init_corewar(t_game *game, int ac, char **av);
#endif