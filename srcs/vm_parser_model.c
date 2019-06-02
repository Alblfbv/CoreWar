/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parser_model.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:34:26 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/30 13:34:27 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_ull               vm_get_value(char *sval)
{
    t_ull            value;
    t_ull            min;
    t_ull            max;

    min = (t_ull)INT_MIN;
    max = (t_ull)INT_MAX;
    if (!sval || !ft_isnumeric(sval))
        return (-1);
    value = ft_atoill(sval);
    if (value > min || value < max)
        return (value);
    return (-1);
}

// static int				vm_is_little_endian(unsigned int value)
// {
// 	char				*temp;

// 	temp = (char*)&value;
// 	return ((*temp) ? 1 : 0);
// }

unsigned int			vm_endian_conversion(unsigned int value)
{
	return (((value>>24) & 0x0ff)
			| ((value<<8) & 0xff0000)
			| ((value>>8) & 0xff00)
			| ((value<<24) & 0xff000000));
}


void                vm_debug(int flag, int ac, char **av, t_game *game)
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
        ft_printf("%sOption parsing Done\n", COLOR_GREEN);
        ft_printf("Dump option status: %d, -s option status: %d, -n option status: %d, -a option status: %d\n", game->d_state, game->s_state, game->n_state, game->a_state);
        ft_printf("Memory Dumped after %d cycles\nNumber of cycles to run before dump %d\n", game->nbr_cycle, game->nbr_s_cycle);
    }
}