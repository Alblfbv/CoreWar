/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:18:12 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/07 04:18:21 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int          dis_init_state(t_game *game)
{
    game->deb_state = 0;
    game->nbr_champs = 0;
    game->nbr_fout = 0;
    game->err_state = 0;
}

static int          dis_init_parser(int ac, char **av, t_game *game)
{
    int             index;

    index = 0;
    while (index < ac)
	{
		if (!ft_strcmp(av[index], "-debug"))
        {
            game->deb_state = 1;
            index++;
        }
		if (!dis_file_reader(av[index], game))
			return (0);
		index++;
	}
	if (game->deb_state)
		dis_debug(1, ac, av, game);
	return (1);
}

int                 main(int ac, char **av)
{
    t_game          game;

    if (ac < 2)
        return (dis_catch_error(US_ERROR, NULL));
    dis_init_state;
    if (!dis_init_parser(ac, av, &game))
        return (0);
    
}