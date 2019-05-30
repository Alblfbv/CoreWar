/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:55 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/30 15:37:07 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void            vm_init_flags(t_game *game)
{
    game->nbr_cycle = 0;
    game->nbr_s_cycle = 0;
    game->nbr_champs = 0;
    game->n_prog_num = 0;
    game->cycle = 0;
    game->cycle_d = 0;
    game->c_checked = 0;
    game->cycle_to_die = 0;
    game->flags.d_state = 0;
    game->flags.n_state = 0;
    game->flags.a_state = 0;
    game->flags.s_state = 0;
    game->flags.deb_state = 0;
    game->flags.pl_state = 0;
    game->error = NULL;
}

void            vm_opt_error(char *str, t_game *game)
{
    t_er_hand   *tmp;
    t_er_hand   *new;

    if ((new = (t_er_hand *)malloc(sizeof(t_er_hand))))
        return ;
    if ((new->error_descr = ft_strnew(ft_strlen(str))))
        return ;
    new->error_descr = ft_strdup(str);
    new->impact = 1;
    new->next = NULL;
    if (game->error == NULL)
        game->error = new;
    else
    {
        tmp = game->error;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}
