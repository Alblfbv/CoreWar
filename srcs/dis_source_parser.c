/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_source_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 04:18:40 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/20 07:07:39 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int          dis_verify_magic(int fd, unsigned int *magic)
{
    if ((read(fd, magic, sizeof(unsigned int))) < 0)
        return (0);
    *magic = vm_endian_conversion(*magic);
    if (*magic == (unsigned int)COREWAR_EXEC_MAGIC)
        return (fd);
    return (0);
}

static void          dis_pri_processor(char *file, int pv_number
                , t_file *champ, t_game *game)
{
    champ->file_name = file;
    champ->instr_nodes = NULL;
    champ->dis_state = 0;
    champ->col = pv_number;
    game->file[pv_number] = champ;
    (game->pv_number)++;
    (game->nbr_champs)++;
}

int                 dis_source_parser(int fd, char *file, t_game *game)
{
    unsigned int    magic;
    unsigned char   *str;
    unsigned int	prog_size;
    int             play_num;
    t_file          *new;

    play_num = game->pv_number;
    if (play_num < MAX_PLAYERS && (play_num + 1 < MAX_PLAYERS))
    {
        if (!(new = (t_file *)malloc(sizeof(t_file))))
            return (-2);
        if (!(fd = dis_verify_magic(fd, &magic)))
            return (-1);
        if ((read(fd, new->name, sizeof(unsigned char) * PROG_NAME_LENGTH)) < 0)
            return (-2);
        if ((lseek(fd, 136, SEEK_SET)) < 0)
            return (-2);
        if ((read(fd, &prog_size, sizeof(unsigned int))) < 0)
            return (-2);
        prog_size = vm_endian_conversion(prog_size);
        if ((read(fd, new->comment, sizeof(unsigned char) * COMMENT_LENGTH)) < 0)
            return (-2);
        if (!(str = (unsigned char *)malloc(sizeof(unsigned char *) * prog_size)))
            return (-2);
        new->fd = fd;
        if (((lseek(fd, 2192, SEEK_SET)) < 0)
                || (read(fd, str, sizeof(unsigned char) * prog_size)) < 0)
            return (-2);
        new->raw_dump = str;
        new->prog_size = prog_size;
        dis_pri_processor(file, play_num, new, game);
        return (1);
    }
    return (-4);
}
