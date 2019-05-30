
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
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
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
	char		option[6];
	int			(*f)();
}				t_option;

typedef struct	s_er_hand
{
	char		*error_descr;
	int			impact;
	struct s_er_hand	*next;
}				t_er_hand;

typedef struct	s_optflag
{
	char		d_state;
	char		n_state;
	char		a_state;
	char		s_state;
	char		deb_state;
	char		pl_state;	
}				t_optflags;
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
	t_ull		n_prog_num;
	t_ull		cycle;
	t_ull		cycle_d;
	t_ull		c_checked;
	t_ull		cycle_to_die;
	t_uc		memdump[MEM_SIZE];
	t_optflags	flags;
	t_er_hand	*error;
}				t_game;

/*
*Parser utility function
*/s

void            		vm_opt_error(char *str, t_game *game);
void            		vm_init_flags(t_game *game);
//unsigned int				vm_endian_conversion(unsigned int val);
int	                    vm_opt_reader(int ac, char **av, t_game *game);
int                     vm_opt_dump(int ac, int index, char **av, t_game *game);
int                     vm_opt_debug(int ac, int index, char **av, t_game *game);
int                     vm_opt_aff(int ac, int index, char **av, t_game *game);
int                     vm_opt_n(int ac, int index, char **av, t_game *game);
int                     vm_opt_soption(int ac, int index, char **av, t_game *game);
t_ull               	vm_get_value(char *sval);

/*
*MODEL FUNCTIONS
*/
int						vm_init_corewar(t_game *game, int ac, char **av);
#endif