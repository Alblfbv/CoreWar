/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst0c_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:44:18 by mnishimo          #+#    #+#             */
/*   Updated: 2019/06/11 02:40:07 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	inst_fork(t_game *game, t_process *caller, t_inst *inst)
{
	t_list	*new;
	t_uc	*addr;

	if (!game || !caller || !inst)
		return ;
	if (!(new = prcs_new(caller->c_id)))
		return ;
	addr = access_ptr(game->memdump, caller->pc, (int)(short)(inst->args[0].value.u_dir_val % IDX_MOD));
	prcs_cpy((t_process *)(new->content), caller, addr);
	ft_lstadd(&(game->prcs), new);
	if (!(game->deb_state))
		return ;
	inst->args[0].value.u_dir_val = addr - game->memdump;
	get_debug(game, inst, caller, NULL);
}