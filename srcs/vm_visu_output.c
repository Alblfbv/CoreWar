/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_visu_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:49:23 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/14 21:23:15 by lironkei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void            dis_menu(t_game *game, t_visu *wind, int p_num)
{
	wattron(wind->menu_win, (COLOR_PAIR(8) | A_BOLD | A_UNDERLINE));
	mvwprintw(wind->menu_win, 2, 25, "DISASSEMBLER");
	wattroff(wind->menu_win, (COLOR_PAIR(8) | A_BOLD | A_UNDERLINE));
    wattron(wind->menu_win, (COLOR_PAIR(1)));
    mvwprintw(wind->menu_win, 3, 0, "FID %i, Size %i bytes\n",game->champs[p_num]->id, game->champs[p_num]->prog_size);
    wattroff(wind->menu_win, (COLOR_PAIR(1)));
	wattron(wind->menu_win, (COLOR_PAIR(8)));
	mvwprintw(wind->menu_win, 4, 0, "mnishimo, mndhlovu, sunakim, allefebv\n");
	wattroff(wind->menu_win, (COLOR_PAIR(8)));
    wattron(wind->raw_win, (COLOR_PAIR(8) | A_BOLD | A_UNDERLINE));
    mvwprintw(wind->raw_win, 1, 40, "Corewar File\n");
    wattroff(wind->raw_win, (COLOR_PAIR(8) | A_BOLD | A_UNDERLINE));
    wattron(wind->raw_win, (COLOR_PAIR(1)));
    mvwprintw(wind->raw_win, 3, 1, "Player Name: %s, Comment: %s\n", game->champs[p_num]->name, game->champs[p_num]->comment);
    wattroff(wind->raw_win, (COLOR_PAIR(1)));
}

static void	        dis_visu_raw(t_game *game, t_visu *win, int p_num)
{
	int         index;
    int         size;

	index = 0;
    size = game->champs[p_num]->prog_size;
	while (index < size)
	{
		wattron(win->raw_win, COLOR_PAIR(game->champs[p_num]->col) | A_BOLD);
		mvwprintw(win->raw_win, 5, 1, "%.2hhX", game->champs[p_num]->instr[index]);
		wattroff(win->raw_win, COLOR_PAIR(game->champs[p_num]->col) | A_BOLD);
		index++;
	}	
}

void	        dis_visu_out(t_game *game, t_visu *win, int p_num)
{
    wattron(win->out_win, (COLOR_PAIR(8) | A_BOLD | A_UNDERLINE));
    mvwprintw(win->out_win, 1, 40, "Source File");
    wattroff(win->out_win, (COLOR_PAIR(8) | A_BOLD | A_UNDERLINE));
    wattron(win->out_win, COLOR_PAIR(1));
    mvwprintw(win->out_win, 3, 1, ".name %s\n", game->champs[p_num]->name);
    mvwprintw(win->out_win, 4, 1, ".comment %s\n", game->champs[p_num]->comment);
    wattroff(win->out_win, COLOR_PAIR(1));
}

void	        visu_launcher(t_game *game, t_visu *visu, int p_num)
{
	werase(visu->menu_win);
	werase(visu->raw_win);
    werase(visu->out_win);
	dis_menu(game, visu, p_num);
	dis_visu_raw(game, visu, p_num);
    dis_visu_out(game, visu, p_num);
    box(visu->out_win, '#', '#');
	box(visu->raw_win, '*' , '*');
	box(visu->menu_win, '*' , '*');
	refresh();
	wnoutrefresh(visu->menu_win);
	wnoutrefresh(visu->raw_win);
    wnoutrefresh(visu->out_win);
	doupdate();
}




