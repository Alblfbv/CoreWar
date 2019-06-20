#include "corewar.h"

int					dis_init_disa(t_game *game, int p_num)
{
	t_file			*new;
	t_din			raw_dump;
	t_instr_node	*new_node;
	t_din			cp_dump;
	t_uc			pos;
	int 			fd;

	fd = game->champs[p_num]->fd;
	if (!(new = (t_file *)malloc(sizeof(t_file)))
		|| !(new_node = (t_instr_node *)ft_memalloc(sizeof(t_instr_node))))
		return (0);
	if (!(new->name = ft_strjoin(".name ", game->champs[p_num]->name))
		|| !(new->comment = ft_strjoin(".comment ", game->champs[p_num]->comment)))
		return (0);
	if(!(dump = (t_din *)ft_memalloc(game->champs[p_num]->prog_size))
		|| ((lseek(fd, 2192, SEEK_SET)) < 0)
		|| (read(fd, dump, prog_size)) < 0)
		return (0);
	cp_dump = dump;
	while(game->champs[p_num]->prog_size < (pos = cp_dump - dump))
	{
		new_node->pos = new_pos;
		new_node->instr = 
	}
}