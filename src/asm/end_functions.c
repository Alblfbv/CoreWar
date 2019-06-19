/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:17:39 by allefebv          #+#    #+#             */
/*   Updated: 2019/06/19 16:00:32 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

static void	free_tkn_end(t_list *tmp_l)
{
	t_list	*tmp_t2;
	t_list	*tmp_t;

	tmp_t = ((t_lbl*)(tmp_l->content))->frwd;
	while (tmp_t)
	{
		tmp_t2 = tmp_t;
		tmp_t = tmp_t->next;
		free(((t_tkn*)(tmp_t2->content))->value);
		free(tmp_t2->content);
		free(tmp_t2);
	}
}

static void	print_error_lbl(t_list *tmp_l, t_pos *pos, int *flag)
{
	t_list	*tmp_t2;
	t_list	*tmp_t;
	t_tkn	*tkn;

	tmp_t = ((t_lbl*)(tmp_l->content))->frwd;
	while (tmp_t)
	{
		tkn = (t_tkn*)(tmp_t->content);
		ft_printf(WHT "%s:%d:%d: " RED BLD "error: " RESET "label " WHT BLD "`%s`" RESET " used as ",
			pos->file_name, tkn->line, tkn->col_start, ((t_lbl*)(tmp_l->content))->name);
		ft_printf(WHT BLD "`%s`" RESET " at address " WHT BLD "`%#x`" RESET " has never been declared;\n\n",
			get_tkn_type_name(((t_tkn*)(tmp_t->content))->type), ((t_tkn*)(tmp_t->content))->lc_instruction);
		tmp_t2 = tmp_t;
		tmp_t = tmp_t->next;
		free(((t_tkn*)(tmp_t2->content))->value);
		free(tmp_t2->content);
		free(tmp_t2);
	}
	*flag = 0;
}

int		end_lbl(t_list *lbls, t_pos *pos)
{
	t_list 	*tmp_l;
	t_list	*tmp_l2;
	int		flag;

	tmp_l = lbls;
	flag = 1;
	while (tmp_l)
	{
		if (((t_lbl*)(tmp_l->content))->type == 'U')
			print_error_lbl(tmp_l, pos, &flag);
		else
			free_tkn_end(tmp_l);
		tmp_l2 = tmp_l;
		tmp_l = tmp_l->next;
		free(((t_lbl*)(tmp_l2->content))->name);
		free(tmp_l2->content);
		free(tmp_l2);
	}
	//ft_lstdel(&lbls, &del_lbls);
	return (flag);
}

static int	fill_bytebf(t_bytebf *bytebf, t_pos *pos)
{
	bytebf->hd_size = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	if (!(bytebf->header = (char *)ft_memalloc(bytebf->hd_size)))
		return (ft_error(NULL, e_malloc_error, NULL));
	ft_memcpy(bytebf->header, bytebf->magic, 4);
	ft_memcpy(bytebf->header + 4, bytebf->name, PROG_NAME_LENGTH);
	ft_memcpy(bytebf->header + 4 + PROG_NAME_LENGTH, bytebf->offset1, 4);
	ft_memcpy(bytebf->prog_size, &pos->lc_tkn, 4);
	ft_memrev(bytebf->prog_size, 4);
	ft_memcpy(bytebf->header + 8 + PROG_NAME_LENGTH, bytebf->prog_size, 4); // change program size
	ft_memcpy(bytebf->header +  12 + PROG_NAME_LENGTH, bytebf->comment, COMMENT_LENGTH);
	ft_memcpy(bytebf->header + 12 + PROG_NAME_LENGTH + COMMENT_LENGTH, bytebf->offset2, 4);
	if (!(bytebf->bytebuf = (char *)ft_memalloc(bytebf->hd_size + pos->lc_tkn)))
		return (ft_error(NULL, e_malloc_error, NULL));
	ft_memcpy(bytebf->bytebuf, bytebf->header, bytebf->hd_size);
	ft_memcpy(bytebf->bytebuf + bytebf->hd_size, bytebf->inst, pos->lc_tkn);
	return (1);
}

int			ft_write_output(t_bytebf *bytebf, t_pos *pos, char *name)
{
	int		fd;
	char	*tmp;    //malloc
	char	*f_name;  // malloc
	int		errno;
	int		i;

    errno = 0;
    tmp = ft_strndup(name, ft_strlen(name) - 2);
    if (!(f_name = ft_strjoin(tmp, ".cor")))
		return (ft_error(NULL, e_malloc_error, NULL));
    ft_strdel(&tmp);
    if ((fd = open(f_name, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0) //0644 = chmod
        return (ft_error(NULL, e_open_error, NULL));
    else
    {
        fill_bytebf(bytebf, pos);
        if ((i = write(fd, bytebf->bytebuf, pos->lc_tkn + bytebf->hd_size)) == -1)
            return (ft_error(NULL, e_write_error, NULL));
        else
            ft_printf(WHT BLD "Write output to %s\n" RESET, f_name);
    }
	ft_strdel(&f_name);
	return (1);
}