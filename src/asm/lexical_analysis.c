/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:48:45 by allefebv          #+#    #+#             */
/*   Updated: 2019/06/19 14:05:55 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_state_l(t_pos *pos, t_tkn **tkn)
{
	if (pos->state_l != 24)
	{
		if (!(*tkn = (t_tkn*)ft_memalloc(sizeof(t_tkn))))
			return (ft_error(pos, e_malloc_error, NULL));
		pos->state_l = 0;
		(*tkn)->buff_start = pos->buf_pos;
		(*tkn)->col_start = pos->file_col;
	}
	return (1);
}

static int	final_state(t_pos *pos, t_tkn *tkn, char *buf, t_list **lbls)
{
	if (lex_sm[pos->state_l][0] == -2 || lex_sm[pos->state_l][0] == -3)
	{
		pos->multiple_line = 0;
		if (lex_sm[pos->state_l][0] == -3)
		{
			pos->buf_pos--;
			pos->file_col--;
		}
		else
			pos->tab_counter++;
		if (pos->tab_counter == 8)
			pos->tab_counter = 0;
		tkn->buff_end = pos->buf_pos;
		tkn->col_end = pos->file_col;
		if (!(tkn_create(buf, pos, lbls, tkn)))
			return (ft_error(NULL, e_no_print, NULL));
		pos->file_col++;
		pos->buf_pos++;
		return (1);
	}
	return (2);
}

static void		ft_move_positions(t_pos *pos, t_tkn *tkn)
{
		if (pos->state_l == 0)
		{
			tkn->buff_start++;
			if (pos->tmp_buf[pos->buf_pos] == '\t')
			{
				tkn->col_start = tkn->col_start + 8 - pos->tab_counter;
				pos->file_col = pos->file_col + 8 - pos->tab_counter;
				pos->nb_tab++;
				pos->tab_counter = 0;
			}
			else
			{
				tkn->col_start++;
				pos->file_col++;
			}
		}
		else
			pos->file_col++;
		if (pos->tmp_buf[pos->buf_pos] != '\t')
			pos->tab_counter++;
		if (pos->tab_counter == 8)
			pos->tab_counter = 0;
		pos->buf_pos++;
}

int			lexical_analysis(t_pos *pos, t_tkn **tkn, t_list **lbls)
{
	int	i;
	int	ret;

	if (check_state_l(pos, tkn) == 0)
			return (ft_error(NULL, e_no_print, NULL));
	while (pos->state_l != -1 && pos->buf_pos < pos->size_buf)
	{
		i = 0;
		while (i < NB_LSM_COL && !ft_strchr(lsm_col[i], pos->tmp_buf[pos->buf_pos]))
			i++;
		pos->state_l = lex_sm[pos->state_l][i];
		if (pos->state_l == -1)
			break;
		if ((ret = final_state(pos, *tkn, pos->tmp_buf, lbls)) == 1)
			return (1);
		else if (!ret)
			return (ft_error(NULL, e_no_print, NULL));
		ft_move_positions(pos, *tkn);
	}
	if (pos->state_l == 24)
	{
		pos->multiple_line = 1;
		return (1);
	}
	return (ft_error(pos, e_lexical_error, *tkn));
}