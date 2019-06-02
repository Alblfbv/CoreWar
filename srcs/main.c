/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:14:40 by mnishimo          #+#    #+#             */
/*   Updated: 2019/05/30 11:32:36 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char const	*g_header[] =
{
	"#######  ######### #######  #########  ##    ####    ###      ##     #######",
	"###      ##     ## #######  ###        ###   ####   ####     ####    #######",
	"###      ##     ## ###      #######    ####  ####  #####    ##  ##   ###",
	"###      ##     ## ###      ###        #################   ########  ###",
	"######## ######### ###      #########  #################  ########## ###"
};


static int				vm_init_parser(int ac, char **av, t_game *game)
{
	int			index;
	int			count;

	index = 1;
	count = 0;
	while (count < (int)(sizeof(g_header) / sizeof(g_header[0])))
        ft_printf("%s%s\n", COLOR_GREEN, g_header[count++]);
	if (ac < 2)
		return (vm_catch_error(US_ERROR, NULL));
	vm_init_flags(game);
	vm_debug (0, ac, av, game);
	// if (!vm_opt_reader(ac, av, game))
		// 	return (0);
	// vm_debug(1, ac, av, game);
	while (index < ac)
	{
		if (!vm_file_reader(av[index], game))
		{
			return (vm_catch_error(IO_ERROR, av[index]));
		}
		//ft_printf("%s\n", av[index]);
		index++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_game		game;
	//int			end;

	
	if (!vm_init_parser(ac, av, &game))
		return (0);
	//vm_display(&game);
/*	while (!game->end)
	{
		process(&game);
	}
	//some output in the end of the game
	output();
	free_game(&game);*/
	return (0);
}
