#include "corewar.h"

int				dis_init_disa(t_game *game, int p_num)
{
	t_file		*new;
	char		*tmp_name;
	char		*tmp_comment;
	t_uc		dump;


	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (0);
	if (!(new->name = ft_strjoin(".name ", game->champs[p_num]->name))
		|| !(new->comment = ft_strjoin(".comment ", game->champs[p_num]->comment)))
		return (0);
	ft_memcpy(dump, )

}