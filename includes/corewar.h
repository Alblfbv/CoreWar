/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:51:52 by mnishimo          #+#    #+#             */
/*   Updated: 2019/06/23 18:55:37 by mndhlovu         ###   ########.fr       */
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

typedef struct			s_instr_dec
{
	t_arg_type			type;
	int32_t				data_dump; //data dump
	size_t				size;
}						t_instr_dec;

typedef struct			s_op
{
	char				*name;
	int					nb_args;
	t_arg_type			arg_types[MAX_ARGS_NUMBER];
	int					num_value;
	int					nb_cycles;
	char				*description;
	int					param_byte;
	int					index_status;
}						t_op;

typedef struct			s_single_instr
{
	t_op				*op;
	t_ocp				*new_pc;
	t_instr_dec			args[4];
}						t_single_instr;

typedef struct			s_instr_node
{
	t_uc				pos; //position of the byte
	t_single_instr		*instr;
	struct s_instr_node	*next;
}						t_instr_node;

typedef struct			s_file
{
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	int					dis_state;
	int					col;
	t_instr_node		*instr_nodes;
	unsigned char		*raw_dump;
	int 				fd;
	unsigned int		prog_size;
	char				*file_name;
	char				*output_file;
}						t_file;

typedef struct 			s_inst_store
{
	int 				size;
	char 				*instr;
	struct s_inst_store	*next;	
}						t_inst_store;

typedef struct			s_game
{
	t_file				*file[MAX_PLAYERS + 1]; // the last ptr is NULL
	t_visu				*visu;
	t_inst_store		*store;
	int 				length;
	int 				visu_state;
	int 				deb_state;
	int					nbr_champs;
	int 				pv_number;
	t_uc				memdump[CHAMP_MAX_SIZE];
}						t_game;


int                 	dis_source_parser(int fd, char *file, t_game *game);
int                     dis_catch_error(int flag, char *av);
int						dis_multi_util(t_game *game, int p_num);
int16_t                 vm_endian_convert_16(int16_t val);
int32_t                 vm_endian_convert_32(int32_t val);
int                     vm_check_endianness(int value);
void                    dis_print_node(t_visu *win, t_game *game);
t_single_instr			*dis_decode_handler(t_ocp *pc);
void                    dis_sub_handler(t_game *game, int p_num);
int			            dis_write_output(t_game *game, int p_num);
int                     vm_load_player(t_game *game);
void                    dis_debug(t_game *game, int p_num);
int                     dis_file_reader(char *file, t_game *game);
int	    				vm_get_instr(t_game *game, t_instr_node *node);
unsigned int			vm_endian_conversion(unsigned int val);



/*
 * visu
*/
void	end_visu(t_visu *visu);
int		dis_output(t_game *game, int p_num, int *flag);
void	visu_launcher(t_game *game, t_visu *visu, int p_num);
void    vm_init_visu(t_game *game, t_visu *visu, int pl_num);

#endif
