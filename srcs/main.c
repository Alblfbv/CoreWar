/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:18:12 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/14 21:30:31 by lironkei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void          dis_init_state(t_game *game)
{
    game->deb_state = 0;
    game->nbr_champs = 0;
    game->nbr_fout = 0;
    game->er_state = 0;
    game->visu_state = 0;
    game->deb_state = 0;
    game->pv_number = 0;
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

static int          dis_init_disa(t_game *game, t_visu *visu)
{
    int             nbr_champs;
    int             index;
    int             state;

    nbr_champs = game->nbr_champs;
    while (nbr_champs > 0)
    {
        if (!game->champs[nbr_champs]->dis_state)
        {
            if (!dis_multi_utils(game))
                return (0);
        }
    }
}

int                 main(int ac, char **av)
{
    t_game          game;

    if (ac < 2)
        return (dis_catch_error(US_ERROR, NULL));
    dis_init_state(&game);
    if (!dis_init_parser(ac, av, &game))
        return (0);

    if (game.visu_state || game.deb_state)
    {
        ft_printf("Bingo\n");
        vm_init_visu(&game, game.visu);
        //dis_output(&game, 1);
    }
    // getch();
    // end_visu(game.visu);
    return (0);
}
