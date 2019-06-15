/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:56:12 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/14 18:45:25 by lironkei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int              dis_is_vfile(char *str)
{
    char                *tmp;  

    if (ft_strlen(str) > 4)
    {
        if(ft_strstr(str, ".cor"))
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

int                     dis_file_reader(char *file, t_game *game)
{
    int                 fd;
    int                 ret;

    if (dis_is_vfile(file))
    {
        if ((fd = open(file, O_RDONLY)) < 0)
            return (dis_catch_error(IO_ERROR, file));
        ret = dis_source_parser(fd, file,  game);
        if (ret == -1)
            return (dis_catch_error(ret, NULL));
        if (ret == -2)
            return (dis_catch_error(ret, NULL));
        if (ret == -3)
            return (dis_catch_error(ret, NULL));
        if (ret == -4)
            return (dis_catch_error(ret, NULL));
        return (1);
    }
    return (1);
}
