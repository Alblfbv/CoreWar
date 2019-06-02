/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_option_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:33:28 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/30 13:33:31 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_option                g_options[] = {
    {"-n", vm_opt_n}, {"-d", vm_opt_dump}
    , {"-de", vm_opt_debug}, {"-a", vm_opt_aff}, {"-s", vm_opt_soption}};

int                     vm_opt_dump(int count
                , char **av, t_game *game)
{
    t_ull               value;

    if (av[count + 1] && !game->d_state)
    {
        if ((value = vm_get_value(av[count + 1])) == (t_ull) -1)
            return (0);
        game->d_state = 1;
        game->nbr_cycle = value;
    }
    return (1);
}

int                     vm_opt_soption(int count, char **av, t_game *game)
{
    t_ull               value;

    if (av[count + 1] && !game->s_state)
    {
        if ((value = vm_get_value(av[count + 1])) == (t_ull) -1)
            return (0);
        ft_printf("S flag present\n");
        game->s_state = 1;
        game->nbr_s_cycle = value;
    }
    return (1);
}


int                     vm_opt_n(int count
                , char **av, t_game *game)
{
    t_ull               value;

    if (!game->n_state && av[count + 1])
    {
        if ((value = vm_get_value(av[count + 1])) == (t_ull) -1)
            return (0);
        ft_printf("N flag present\n");
        game->n_state = 1;
        game->n_prog_num = value;
    }
    return (1);
}

int                     vm_opt_debug(int count
                , char **av, t_game *game)
{
    if (av[count] && !game->deb_state)
         game->deb_state = 1;
    return (1);
}

int                     vm_opt_aff(int count
                , char **av, t_game *game)
{
    if (av[count] && !game->a_state)
         game->a_state = 1;
    return (1);
}

int                     vm_opt_reader(int ac, char **av, t_game *game)
{
    int                 index;
    int                 count;

    index = 0;
    count = 1;
    while (index < (int)(sizeof(g_options) / sizeof(g_options[0]))
                    && count < ac)
    {
        ft_printf("opt reader: %s\nchecker: %d\n", av[count], ft_strcmp(av[count], g_options[index].option));
        if (!ft_strcmp(av[count], g_options[index].option))
        {
            if (!g_options[index].f(count, av, game))
                return (vm_catch_error(OPT_ERROR, av[index]));
        }
        index++;
        count++;
    }
    return (1);
}