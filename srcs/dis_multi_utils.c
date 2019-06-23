/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_multi_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 07:06:46 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/23 18:49:26 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void				dis_append_instr(t_game *game, t_instr_node *node, int p_num)
{
	t_instr_node	*old;

	if (game->file[p_num]->instr_nodes == NULL)
		game->file[p_num]->instr_nodes = node;
	else
	{
		old = game->file[p_num]->instr_nodes;
		while (old->next)
			old = old->next;
		old->next = node;
	}
}

int					dis_multi_util(t_game *game, int p_num)
{
	t_din			*raw_dump;
	t_instr_node	*new_node;
	t_ocp			*cp_dump;
	t_uc			pos;
	int 			fd;

	fd = game->file[p_num]->fd;
	if (!(new_node = (t_instr_node *)malloc(sizeof(t_instr_node))))
		return (0);
	if(!(raw_dump = (t_din *)malloc(sizeof(t_din) * game->file[p_num]->prog_size))
		|| ((lseek(fd, 2192, SEEK_SET)) < 0)
		|| (read(fd, raw_dump, game->file[p_num]->prog_size)) < 0)
		return (0);
	cp_dump = raw_dump;
	while(game->file[p_num]->prog_size > (pos = cp_dump - raw_dump))
	{
		if (!(new_node = (t_instr_node *)malloc(sizeof(t_instr_node))))
			return (0);
		new_node->pos = pos;
		if (!(new_node->instr = dis_decode_handler(cp_dump)))
			return (0);
		new_node->next = NULL;
		cp_dump = new_node->instr->new_pc;
		dis_append_instr(game, new_node, p_num);	
	}
	return (1);
}