/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:56:12 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/23 18:49:32 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int              dis_is_vfile(char *str)
{
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

int                     vm_check_endianness(int value)
{
    char                *str;

    str = (char *) &value;
    return ((*str == 1) ? 1 : 0);
}

int16_t                 vm_endian_convert_16(int16_t val)
{
    return ((val << 8) | ((val >> 8) & 0xff));
}

int32_t                 vm_endian_convert_32(int32_t val)
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | ((val >> 16) & 0xFFFF);
}

int                     vm_load_player(t_game *game)
{
    int             nbr_champs;
    int             index;
    int             fd;
    int             state;

    nbr_champs = game->nbr_champs;
    index = 0;
    while (index < nbr_champs)
    {
        if (!game->file[index]->dis_state)
        {
            fd = game->file[index]->fd;
            if (lseek(fd, 2192, SEEK_SET) < 0 
                || read(fd, &(game->memdump[0]), game->file[index]->prog_size) < 0)
                return (-1);
            return (index);
        }
        index++;
    }
    return (-1);
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
