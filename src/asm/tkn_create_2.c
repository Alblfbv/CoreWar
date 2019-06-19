/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_create_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:32:41 by allefebv          #+#    #+#             */
/*   Updated: 2019/06/19 15:29:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	tkn_label(char *buff, t_pos *pos, t_list **lbls, t_tkn *tkn)
{
	char	*name;
	t_list	*tmp_l;
	t_lbl	*new;

	tkn->type = e_lbl;
	tmp_l = *lbls;
	if (!(name = ft_strndup(buff + tkn->buff_start, tkn->buff_end - tkn->buff_start)))
		return (ft_error(NULL, e_malloc_error, NULL));
	while (tmp_l != NULL && !ft_strequ(((t_lbl*)(tmp_l->content))->name, name))
		tmp_l = tmp_l->next;
	if (tmp_l != NULL)
	{
		free(name);
		if (((t_lbl*)(tmp_l->content))->type == 'D')
			return (ft_error(pos, e_double_label, tkn));
		else
		{
			tkn->value = tmp_l->content;
			((t_lbl*)(tmp_l->content))->lc_lbl_inst = pos->lc_tkn;
		}
	}
	else
	{
		if (!(new = (t_lbl*)ft_memalloc(sizeof(t_lbl))))
		{
			free(name);
			return (ft_error(NULL, e_malloc_error, NULL));
		}
		tkn->value = new;
		new->name = name;
		new->type = 'D';
		new->lc_lbl_inst = pos->lc_tkn;
		new->frwd = NULL;
		if (!(ft_lstadd(lbls, ft_lstnew(new, sizeof(t_lbl)))))
		{
			free(name);
			return (ft_error(NULL, e_malloc_error, NULL));
		}
	}
	return (1);
}

int	tkn_dir_label(char *buff, t_pos *pos, t_list **lbls, t_tkn *tkn)
{
	char	*name;
	t_list	*tmp_l;
	t_lbl	*new;

	tkn->type = e_dir_label;
	tkn->mem_size = pos->dir_bytes;
	tmp_l = *lbls;
	if (!(name = ft_strndup(buff + tkn->buff_start + 2, tkn->buff_end - tkn->buff_start - 1)))
		return (ft_error(NULL, e_malloc_error, NULL));
	while (tmp_l != NULL && !ft_strequ(((t_lbl*)(tmp_l->content))->name, name))
		tmp_l = tmp_l->next;
	if (tmp_l != NULL)
	{
		free(name);
		if (((t_lbl*)(tmp_l->content))->type == 'D')
		{
			if (pos->dir_bytes == 2)
			{
				if (!(tkn->value = (short*)malloc(sizeof(short))))
					return (ft_error(NULL, e_malloc_error, NULL));
				*((short*)tkn->value) = ((t_lbl*)(tmp_l->content))->lc_lbl_inst - pos->lc_instruction;
			}
			else
			{
				if (!(tkn->value = (int*)malloc(sizeof(int))))
					return (ft_error(NULL, e_malloc_error, NULL));
				*((int*)tkn->value) = ((t_lbl*)(tmp_l->content))->lc_lbl_inst - pos->lc_instruction;
			}
		}
		else
		{
			tkn->lc_instruction = pos->lc_instruction;
			tkn->lc_tkn = pos->lc_tkn;
			tkn->line = pos->file_line;
			if (!(ft_lstadd(&((t_lbl*)(tmp_l->content))->frwd, ft_lstnew(tkn, sizeof(t_tkn)))))
				return (ft_error(NULL, e_malloc_error, NULL));
		}
	}
	else
	{
		tkn->lc_instruction = pos->lc_instruction;
		tkn->lc_tkn = pos->lc_tkn;
		tkn->line = pos->file_line;
		if (!(new = (t_lbl*)ft_memalloc(sizeof(t_lbl))))
			return (ft_error(NULL, e_malloc_error, NULL));
		new->name = name;
		new->type = 'U';
		if (!(ft_lstadd(lbls, ft_lstnew(new, sizeof(t_lbl)))))
			return (ft_error(NULL, e_malloc_error, NULL));
		if (!(ft_lstadd(&((t_lbl*)((*lbls)->content))->frwd, ft_lstnew(tkn, sizeof(t_tkn)))))
			return (ft_error(NULL, e_malloc_error, NULL));
	}
	return (1);
}

int	tkn_ind_label(char *buff, t_pos *pos, t_list **lbls, t_tkn *tkn)
{
	char	*name;
	t_list	*tmp_l;
	t_lbl	*new;

	tkn->type = e_ind_label;
	tkn->mem_size = 2;
	tmp_l = *lbls;
	if (!(name = ft_strndup(buff + tkn->buff_start + 1, tkn->buff_end - tkn->buff_start)))
		return (ft_error(NULL, e_malloc_error, NULL));
	while (tmp_l != NULL && !ft_strequ(((t_lbl*)(tmp_l->content))->name, name))
		tmp_l = tmp_l->next;
	if (tmp_l != NULL)
	{
		free(name);
		if (((t_lbl*)(tmp_l->content))->type == 'D')
		{
			if (pos->dir_bytes == 2)
			{
				if (!(tkn->value = (short*)malloc(sizeof(short))))
					return (ft_error(NULL, e_malloc_error, NULL));
				*((short*)tkn->value) = ((t_lbl*)(tmp_l->content))->lc_lbl_inst - pos->lc_instruction;
			}
			else
			{
				if (!(tkn->value = (int*)malloc(sizeof(int))))
					return (ft_error(NULL, e_malloc_error, NULL));
				*((int*)tkn->value) = ((t_lbl*)(tmp_l->content))->lc_lbl_inst - pos->lc_instruction;
			}
		}
		else
		{
			tkn->lc_instruction = pos->lc_instruction;
			tkn->lc_tkn = pos->lc_tkn;
			tkn->line = pos->file_line;
			if (!(ft_lstadd(&((t_lbl*)(tmp_l->content))->frwd, ft_lstnew(tkn, sizeof(t_tkn)))))
				return (ft_error(NULL, e_malloc_error, NULL));
		}
	}
	else
	{
		tkn->lc_instruction = pos->lc_instruction;
		tkn->lc_tkn = pos->lc_tkn;
		tkn->line = pos->file_line;
		if (!(new = (t_lbl*)ft_memalloc(sizeof(t_lbl))))
			return (ft_error(NULL, e_malloc_error, NULL));
		new->name = name;
		new->type = 'U';
		if (!(ft_lstadd(lbls, ft_lstnew(new, sizeof(t_lbl)))))
			return (ft_error(NULL, e_malloc_error, NULL));
		if (!(ft_lstadd(&((t_lbl*)((*lbls)->content))->frwd, ft_lstnew(tkn, sizeof(t_tkn)))))
			return (ft_error(NULL, e_malloc_error, NULL));
	}
	return (1);
}