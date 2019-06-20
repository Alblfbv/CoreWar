/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:06:40 by mnishimo          #+#    #+#             */
/*   Updated: 2019/06/12 22:13:05 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


t_op    g_op_tab[17] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0}
};

t_uc		dis_sub_extract(size_t bytes, t_ocp *pc, int endian_mode)
{
	t_ocp value[4];
	size_t	index;
	
	index = -1;
	while (++index < bytes)
		value[index] = pc[index];
	if (1 == bytes)
		return (value[0]);
	if (2 == bytes)
	{
		if (IS_BIG_ENDIAN == endian_mode)
			return (*(t_uc *)value);
		return (vm_endian_conversion(*(unsigned int)value));
	}
}

static void				dis_extract_bcode(t_single_instr *instr, t_ocp *pc, t_din *bcode)
{
	instr->op = g_op_tab + *pc;
	if (0 != instr->op->param_byte)
	{
		*bcode = pc[1];
		instr->new_pc = pc + 2;
	}
	else
	{
		*bcode = DIR_CODE << 6;
		instr->new_pc = pc + 1;
	}
}

int		dis_extract_instr_data(t_single_instr *instr, t_din bcode, int index)
{
	instr->args[index].type = (bcode >> 6) & 0x3;

	if (REG_CODE == instr->args[index].type)
		instr->args[index].size = 1;
	else if (DIR_CODE == instr->args[index].type)
		instr->args[index].size = (!instr->op->has_index) ? 4 : 2;
	else if (IND_CODE == instr->args[i].type)
		instr->args[index].size = 2;
	else
		return (0);
	instr->args[index].data = dis_sub_extract(instr->args[index].size,
												 instr->new_pc,
												 IS_BIG_ENDIAN);
	if (REG_CODE == instr->args[index].type && !REG_IS_VALID(instr->args[index].data))
		return (0);
	return (1);
}

static int			dis_instr_parser(t_single_instr *instr, t_din bcode)
{
	int			index;

	index = 0;
	while (index < instr->op->nb_args)
	{
		if (!dis_extract_instr_data(instr, bcode, index))
			return (0) ;
		bcode <<= 2;
		instr->new_pc = this->new_pc + this->args[index].size;
		++index;
	}
	return (1);
}

t_single_instr		*dis_decode_handler(t_ocp *pc)
{
	t_din 			bcode;
	t_single_instr	*instr;

	if (!OPCODE_IS_VALID(*pc))
		return (0);
	if (!(instr = (t_single_instr *)malloc(sizeof(*instr))))
		return (0);
	dis_extract_bcode(instr, pc, &bcode)
	if (0 == dis_instr_parser((instr, bcode))
		return (NULL);
	return (instr);
}