/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:18:12 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/23 18:56:25 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void          dis_init_state(t_game *game)
{
    game->deb_state = 0;
    game->nbr_champs = 0;
    game->visu_state = 0;
    game->deb_state = 0;
    game->pv_number = 0;
    game->length = 0;
    game->store = NULL;
    if (!(game->visu = (t_visu *)malloc(sizeof(t_visu))))
        return ;
	ft_bzero(game->visu, sizeof(t_visu));
    ft_bzero(&(game->memdump[0]), CHAMP_MAX_SIZE * sizeof(t_uc));
}

static int          dis_init_parser(int ac, char **av, t_game *game)
{
    int             index;

    index = 0;
    while (index < ac)
	{
		if (ft_strequ(av[index], "-debug"))
        {
            game->deb_state = 1;
            index++;
        }
        if (ft_strequ(av[index], "-v"))
        {
            game->visu_state = 1;
            index++;
        }
		if (!dis_file_reader(av[index], game))
			return (0);
		index++;
	}
	return (1);
}

void                    dis_sub_handler(t_game *game, int p_num)
{
    t_instr_node      *node;
    int                index;

    node = game->file[p_num]->instr_nodes;
    index = 0;
    if (node != NULL)
    {
        while (node)
        {
            vm_get_instr(game, node);
            node = node->next;
            index++;
        }
    }
    game->file[p_num]->dis_state = 1;
}

int                 main(int ac, char **av)
{
    t_game          game;
    int             pl_num;

    if (ac < 2)
        return (dis_catch_error(US_ERROR, NULL));
    dis_init_state(&game);
    if (!dis_init_parser(ac, av, &game))
        return (0);
    if (game.deb_state && !game.visu_state)
    {
        ft_printf("\t\tDEBUG MODE\t\t\n");
        while ((pl_num = vm_load_player(&game)) != -1)
        {
            if (!dis_multi_util(&game, pl_num))
                return (dis_catch_error(-2, NULL));
            dis_sub_handler(&game, pl_num);
            dis_debug(&game, pl_num);
        }
    }
    if (game.visu_state && !game.deb_state)
    {
        pl_num = vm_load_player(&game);
        if (!dis_multi_util(&game, pl_num))
            return (dis_catch_error(-2, NULL));
        dis_sub_handler(&game, pl_num);
        dis_output(&game, pl_num);
    }
    end_visu(game.visu);
    return (0);
}
