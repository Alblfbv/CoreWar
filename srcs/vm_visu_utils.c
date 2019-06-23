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

void                vm_init_visu(t_game *game, t_visu *visu, int pl_num)
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
	init_pair(5, COLOR_WHITE, COLOR_WHITE);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_WHITE);
    init_pair(8, COLOR_GREEN, COLOR_WHITE);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	visu->raw_win = newwin(CHAMP_MAX_SIZE / 64 + 6, 64 * 3 + 9, 0, 0);
	visu->out_win = newwin(game->length + 8, 64 * 3 + 9, 12, 0);
	visu->menu_win = newwin(CHAMP_MAX_SIZE / 64 + 3, 100, 0, 64 * 3 + 9);
	curs_set(FALSE);
	visu_launcher(game, game->visu, pl_num);
}

void			end_visu(t_visu *visu)
{
	delwin(visu->raw_win);
	delwin(visu->menu_win);
    delwin(visu->out_win);
	endwin();
}

static void		restart_all(t_game *game, int p_num)
{
	end_visu(game->visu);
	ft_bzero(&(game->memdump[0]), CHAMP_MAX_SIZE * sizeof(t_uc));
	vm_init_visu(game, game->visu, p_num);
}

int			   dis_output(t_game *game, int p_num)
{
	int			c;

	if (c == KEY_RIGHT)
	{
		p_num = vm_load_player(game);
		if (!dis_multi_util(game, p_num))
			return (dis_catch_error(-2, NULL));
		dis_sub_handler(game, p_num);
		restart_all(game, p_num);
	}
	vm_init_visu(game, game->visu, p_num);
	c = getch();
	return (1);
}
