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
#include "visu.h"
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
# define IO_ERROR 1
# define OPT_ERROR 2
# define ML_ERROR 3
# define US_ERROR 0
# define CLR_RED  "\x1b[31m"
# define CLR_GREEN  "\x1b[32m"
# define CLR_YEL  "\x1b[33m"
# define OPCODE_IS_VALID(x)		(16 > (uint32_t)((x) - 1))
# define REG_IS_VALID(x)		(REG_NUMBER > (uint32_t)((x) - 1))
typedef	unsigned long long	t_ull;
typedef	uint32_t			t_uc;
typedef uint8_t 			t_din;
typedef	uint8_t				t_reg_type;
typedef uint16_t			t_ind_type;
typedef	uint8_t				t_ocp;

typedef struct		s_file
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned char	*raw_dump;
	int 			fd;
	unsigned int	prog_size;
	char			*file_name;
}					t_file;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned char	*instr;
	char			*file_name;
	int				fd;
	unsigned int	prog_size;
	int				col;
	int 			dis_state;
	int			id;
}				t_champ;


//disassembler structs

typedef struct		s_instr_dec
{
	t_arg_type		type;
	t_uc			data_dump; //date dump
	size_t			size;
}					t_instr_dec;

typedef struct		s_single_instr
{
	t_op			*op;
	t_ocp			*new_pc;
	t_instr_dec		args[4];
}					t_single_instr;


typedef struct		s_label
{
	int				name;
	t_uc			pos; //byte_pos
	t_list			list;
}					t_label;

/*
 * Label container_of
 */
# define C_LABEL(it)	CONTAINEROF(it, t_label, list)

/*
 * brief	Instruction structure
 * 
 * param	byte_pos	Position of the instruction in the file.cor (without header)
 * param	instr		Instruction (common/instruction.h)
 * param	label_ref	instr->args[i] label reference
 * param	list		list_node
 */
typedef struct			s_instr_node
{
	t_uc				pos; //byte_pos
	t_single_instr		*instr;
	t_label				*label_ref[3];
	t_list				list;
}						t_instr_node;

typedef struct		s_op
{
	char			*name;
	int				nb_args;
	t_arg_type		arg_types[MAX_ARGS_NUMBER];
	int				numero;
	int				nb_cycles;
	char			*description;
	int				param_byte;
	int				has_index;
}					t_op;



//end of disassembler structs


typedef struct	s_game
{
	t_file		*file[MAX_PLAYERS + 1]; // the last ptr is NULL
	t_champ		*champs[MAX_PLAYERS + 1];
	t_visu		*visu;
	int 		visu_state;
	int 		deb_state;
	int			nbr_champs;
	int 		pv_number;
	int 		pause;
	int			nbr_fout;
	int			er_state;
}				t_game;


int                 	dis_source_parser(int fd, char *file, t_game *game);
int                     dis_catch_error(int flag, char *av);
int                     dis_file_reader(char *file, t_game *game);
void                	dis_debug(int flag, int ac, char **av, t_game *game);
unsigned int			vm_endian_conversion(unsigned int val);



/*
 * visu
*/
void	end_visu(t_visu *visu);
int		dis_output(t_game *game, int p_num);
void	visu_launcher(t_game *game, t_visu *visu, int p_num);
void    vm_init_visu(t_game *game, t_visu *visu);

#endif
