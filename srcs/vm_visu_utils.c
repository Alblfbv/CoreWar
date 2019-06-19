/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_visu_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:05:17 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/14 21:28:20 by lironkei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void                vm_init_visu(t_game *game, t_visu *visu)
{
    initscr();
    noecho();
	keypad(stdscr, TRUE);
    start_color();
    init_color(COLOR_WHITE, 220, 220, 220);
	init_pair(0, COLOR_GREEN, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_WHITE);
    init_pair(8, COLOR_GREEN, COLOR_WHITE);
	visu->raw_win = newwin(35, 80, 6, 100);
	visu->out_win = newwin(35, 80, 6, 15);
    visu->menu_win = newwin(5, 20, 5, 70);
	curs_set(FALSE);
	visu_launcher(game, game->visu, 1);
}

void			end_visu(t_visu *visu)
{
	delwin(visu->raw_win);
	delwin(visu->menu_win);
    delwin(visu->out_win);
	endwin();
}

static int		restart_all(t_game *game, int p_num)
{
	end_visu(game->visu);
	vm_init_visu(game, game->visu);
	p_num = 1;
	return (1);
}

int			   dis_output(t_game *game, int p_num)
{
	// int			c;

	// c = getch();
	// if (c == 32)
	// {
	// 	// p_num = (p_num) ? 0 : 1;
	// 	game->pause = 0;
	// }
	// else if (c == KEY_ENTER)
	// 	return (0);
	// else if (c == KEY_RESIZE)
	// 	return (restart_all(game, p_num));
	ft_printf("bingo man\n");
	visu_launcher(game, game->visu, p_num);
	return (1);
}
