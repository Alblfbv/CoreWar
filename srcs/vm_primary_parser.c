/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_primary_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:33:55 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/30 13:33:57 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// static int          vm_verify_magic(int *fd)
// {
//     unsigned char   magic;

//     if ((read(*fd, &magic, sizeof(unsigned int))) < 0)
//         return (0);
//     magic = vm_endian_conversion(magic);
//     // if (magic == COREWAR_EXEC_MAGIC)
//     //     return (magic);
//     return (magic);
// }

static int          vm_pri_processor(int pv_number, t_champ *champ, t_game *game)
{
    if (game->pl_state && game->pl_number < MAX_PLAYERS)
    {
        champ->id = game->pl_number;
        champ->prcs_c = 0;
        champ->live_c = 0;
        game->champs[game->pl_number] = *champ;
        (game->nbr_champs)++;
        game->pv_number = game->pl_number;
        game->pl_state = 0;
        game->pl_number = 0;
        return (1);
    }
    if (!game->pl_state)
    {
        champ->id = pv_number + 1;
        champ->prcs_c = 0;
        champ->live_c = 0;
        game->champs[pv_number + 1] = *champ;
        (game->nbr_champs)++;
        (game->pv_number)++;
        return (1);
    }
    return (0);
}

int                 vm_primary_parser(int fd, t_game *game)
{
    unsigned int    magic;
    unsigned char   *str;
    unsigned int	prog_size;
    int             play_num;
    t_champ         *new;

    play_num = game->pv_number;
    // ft_printf("Bingo number %d\n", play_num);
    if (play_num < MAX_PLAYERS && (play_num + 1 < MAX_PLAYERS))
    {
        if (!(new = (t_champ *)malloc(sizeof(t_champ))))
            return (-2);
        if ((read(fd, &magic, sizeof(unsigned int))) < 0)
            return (-2);
        magic = vm_endian_conversion(magic);
        // if (!(magic = vm_verify_magic(&fd)))
        //     return (-1);
        ft_printf("Bingo here %x\n", magic);
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
        if ((lseek(fd, 2192, SEEK_SET)) < 0)
            return (-2);
        if ((read(fd, str, sizeof(unsigned char) * prog_size)) < 0)
            return (-2);
        new->prog_size = prog_size;
        new->instr = str;
        if (!vm_pri_processor(play_num, new, game))
        {
            ft_printf("Bingo number %d\n", play_num);
            //ft_strdel(&str);
            free(new);
            return (-3);
        }
        //ft_strdel(&str);
        free(new);
        return (1);
    }
    return (-4);
}