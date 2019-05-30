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

t_option                g_options[6] = {
    {"-dump", vm_opt_dump}, {"-n", vm_opt_n}, {"-d", vm_opt_dump}
    , {"-debug", vm_opt_debug}, {"-a", vm_opt_aff}, {"-s", vm_opt_soption}};

int                     vm_opt_dump(int ac, int index, char *av, t_game *game)
{
    t_ull               value;

    if (index < ac && *av + 1)
    {
        if ((value = vm_get_value(av[index + 1])) == (t_ull) -1)
            return (-1);
        if (!game->flags.d_state)
        {
            game->flags.d_state = '1';
            game->nbr_cycle = value;
        }
    }
    return (index + 2);
}

int                     vm_opt_soption(int ac, int index, char **av, t_game *game)
{
    t_ull               value;

    if (index < ac && av[index + 1])
    {
        if ((value = vm_get_value(av[index + 1])) == (t_ull) -1)
            return (-1);
        if (!game->flags.s_state)
        {
            game->flags.s_state = 1;
            game->nbr_s_cycle = value;
        }
    }
    return (index + 2);
}


int                     vm_opt_n(int ac, int index, char **av, t_game *game)
{
    t_ull               value;

    if (index < ac && av[index + 1])
    {
        if ((value = vm_get_value(av[index + 1])) == (t_ull) -1)
            return (-1);
        if (!game->flags.n_state)
        {
            game->flags.n_state = 1;
            game->n_prog_num = value;
        }
    }
    return (index + 2);
}

int                     vm_opt_debug(int ac, int index, char **av, t_game *game)
{
    if (index < ac)
    {
        ft_printf("error %s \n", av[index]);
        if (!game->flags.deb_state)
            game->flags.deb_state = 1;
    }
    return (index++);
}

int                     vm_opt_aff(int ac, int index, char **av, t_game *game)
{

    if (index < ac)
    {
         ft_printf("error %s \n", av[index]);
        if (!game->flags.a_state)
            game->flags.a_state = 1;
    }
    return (index++);
}

int                    vm_opt_reader(int ac, char **av, t_game *game)
{
    int                 index;
    int                 count;
    int                 cou;

    index = 0;
    count = 1;
    game->nbr_cycle = 1;
    while (index < 6 && count < ac)
    {
        //ft_printf("Bingo %s\n", av[count++]);
        if (!(ft_strcmp(av[count], g_options[index].option)))
        {
            cou = g_options[index].f(ac, count, av[count], game);
            // if (count == -1)
            //     vm_opt_error(av[count], game);
            ft_printf("cou %d\n", cou);
            ft_printf("Bingo %s\n", av[count++]);
        }
        index++;
    }
    return (count);
}