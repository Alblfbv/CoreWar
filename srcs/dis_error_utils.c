/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:19:07 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/07 04:20:04 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char const	*g_usage[] =
{
	"Usage:./disassembly -debug <champion1.cor> <...>",
	"### CONTESTANT ######################################################",
	"your_champion.cor: Champion compiled with the asm",
	"### TEXT OUTPUT MODE ################################################",
    "-debug:            Start in debug mode",
	"#####################################################################"
};

int                     dis_catch_error(int flag, char *av)
{
    int                 index;

    index = 0;
    if (flag == US_ERROR)
    {
        while (index < (int)(sizeof(g_usage) / sizeof(g_usage[0])))
            ft_printf("%s%s\n", CLR_GREEN, g_usage[index++]);
        return (0);
    }
    else if (flag == IO_ERROR)
    {
        ft_printf("%sCannot read file %s\n", CLR_RED, av);
        return (0);
    }
    else if (flag == OPT_ERROR)
    {
        ft_printf("%sError found around the option params of %s\n", CLR_YEL, av);
        return (0);
    }
    else if (flag == -1)
    {
        ft_printf("%sInvalid magic number found on one of the players\n", CLR_RED);
        return (0);
    }
    else if (flag == -2)
    {
        ft_printf("%sFile processing and memory allocation failed\n", CLR_RED);
        return (0);
    }
    else if (flag == -3)
    {
        ft_printf("%sError while saving player to memory\n", CLR_RED);
        return (0);
    }
    else if (flag == -4)
    {
        ft_printf("%sPlease adhere to the limit of 4 players\n", CLR_RED);
        return (0);
    }
    return (1);
}