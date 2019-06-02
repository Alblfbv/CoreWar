/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:43:17 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/30 13:43:19 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int              vm_is_player(char *str)
{
    char                s1[5];
    char                *tmp;
    int                 ret;   

    if (ft_strlen(str) > 4)
    {
        if (!(tmp = ft_strnew(ft_strlen(str))))
            return (0);
        tmp = ft_strdup(str);
        ft_strrev(tmp);
        ft_strncpy(s1, tmp, 4);
        ret = ft_strcmp(s1, "roc.");
        ft_strdel(&tmp);
        return (ret);
    }
    return (1);
}

int                     vm_file_reader(char *file, t_game *game)
{
    int                 fd;
    int                 ret;

    if (!vm_is_player(file))
    {
        if ((fd = open(file, O_RDONLY)) < 0)
            return (0);
        //ft_printf("Bingo here too %d\n", fd);
        ret = vm_primary_parser(fd, game);
        if (ret == -1)
            return (vm_catch_error(ret, NULL));
        if (ret == -2)
            return (vm_catch_error(ret, NULL));
        if (ret == -3)
            return (vm_catch_error(ret, NULL));
        if (ret == -4)
            return (vm_catch_error(ret, NULL));
       // ft_printf("Bingo %s\n", file);
        return (1);
    }
    ft_printf("Bingo here to %s\n", file);
    return (1);
}