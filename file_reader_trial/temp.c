#include "temp.h"

unsigned int			vm_endian_conversion(unsigned int value)
{
	return (((value>>24) & 0x0ff)
			| ((value<<8) & 0xff0000)
			| ((value>>8) & 0xff00)
			| ((value<<24) & 0xff000000));
}

static int          vm_pri_processor(int pv_number, t_champ *champ, t_game *game)
{
    if (pv_number == 0)
    {
        champ->id = pv_number;
        champ->prcs_c = 0;
        champ->live_c = 0;
        game->champs[pv_number] = *champ;
        (game->nbr_champs)++;
        (game->pv_number)++;
        return (1);
    }
    if (pv_number > 0)
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

void                init_game(t_game *game)
{
    game->pv_number = 0;
    game->nbr_champs = 0;
}

void                vm_print_instr(unsigned char *str, unsigned int size)
{
    int             index;

    index = -1;
    printf("Start of the instruction\n");
    while (++index < size)
        printf("%02x ", str[index]);
    printf("\nEnd of the instruction\n");
}

void                vm_print(t_game *game)
{
    int             index;
    int             count;
    int             i;

    index = game->nbr_champs;
    count = 0;
    i = -1;
    while (count < index)
    {
        printf("Name of Champion: %s\n", game->champs[count].name);
        printf("Comment: %s\n", game->champs[count].comment);
        printf("Id : %d\n", game->champs[count].id);
        vm_print_instr(game->champs[count].instr, game->champs[count].prog_size);
        // printf("\n");
        // printf("%01x\n", game->champs[count].instr);
        count++;
    }
    printf("number of champs %d\n", index);
}

int                 main(int ac, char **av)
{
    int             index;
    int				fd;
    unsigned int    magic;
    unsigned char   *str;
    unsigned int	prog_size;
    int             play_num;
    t_game          game;
    t_champ         *new;

    index = 1;
    init_game(&game);
    while (index < ac)
    {
        fd = open(av[index], O_RDONLY);
        play_num = game.pv_number;
        if (!(new = (t_champ *)malloc(sizeof(t_champ))))
            return (1);
        if ((read(fd, &magic, sizeof(unsigned int)) < 0))
		    return (1);
        magic = vm_endian_conversion(magic);
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
        vm_pri_processor(play_num, new, &game);
        index++;
    }
    vm_print(&game);
}