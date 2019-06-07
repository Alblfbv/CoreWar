/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:56:12 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/07 04:56:23 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int              dis_is_vfile(char *str)
{
    char                *tmp;  

    if (ft_strlen(str) > 4)
    {
        tmp = ft_strstr(str, ".cor");
        if (tmp != NULL)
            return (1);
    }
    return (0);
}

unsigned int			vm_endian_conversion(unsigned int value)
{
	return (((value>>24) & 0x0ff)
			| ((value<<8) & 0xff0000)
			| ((value>>8) & 0xff00)
			| ((value<<24) & 0xff000000));
}

static void             dis_disp_players(t_game *game)
{
    int             index;

    index = 0;
    while (index < game->nbr_champs)
    {
        ft_printf("Player Name: %s\t\tPlayer id: %d\t\tPlayer Comment: %s\n", game->champs[index]->name, game->champs[index]->id, game->champs[index]->comment);
        index++;
    }
}


void                dis_debug(int flag, int ac, char **av, t_game *game)
{
    int             index;

    index = 0;
    ft_printf("\n%s############ DEBUG ###############\n", COLOR_GREEN);
    if (flag == 0)
    {
        ft_printf("Number of arguments parsed: %d\n", ac);
        while (++index < ac)
            ft_printf("ARG Number %d: %s\n", index, av[index]);
    }
    else if (flag == 1)
    {
        // ft_printf("%sInitial Parsing Done\n", COLOR_GREEN);
        // ft_printf("-d option status: %d, -s option status: %d, -n option status: %d, -a option status: %d\n", game->d_state, game->s_state, game->n_state, game->a_state);
        // ft_printf("Memory Dumped after %d cycles\nNumber of cycles to run before dump %d\nNumber of players %d\n", game->nbr_cycle, game->nbr_s_cycle, game->nbr_champs);
        dis_disp_players(game);
    }
}

int                     dis_file_reader(char *file, t_game *game)
{
    int                 fd;
    int                 ret;

    if (dis_is_vfile(file))
    {
        if ((fd = open(file, O_RDONLY)) < 0)
            return (dis_catch_error(IO_ERROR, file));
        ret = dis_source_parser(fd, game);
        if (ret == -1)
            return (dis_catch_error(ret, NULL));
        if (ret == -2)
            return (dis_catch_error(ret, NULL));
        if (ret == -3)
            return (dis_catch_error(ret, NULL));
        if (ret == -4)
            return (diss_catch_error(ret, NULL));
        return (1);
    }
    return (1);
}