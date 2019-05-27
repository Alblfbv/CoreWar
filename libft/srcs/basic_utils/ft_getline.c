/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:12:59 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/19 17:30:24 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_last_ind(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	return (i);
}

static int	flush_buff(char **line, char *buff)
{
	char	*tmp;
	int		i;

	i = get_last_ind(buff);
	if (*line == NULL)
	{
		if ((*line = ft_strndup(buff, i)) == NULL)
			return (-1);
	}
	else if (*line != NULL)
	{
		if ((tmp = ft_strnew(ft_strlen(*line) + i)) != NULL)
		{
			ft_strcpy(tmp, *line);
			ft_strncat(tmp, buff, i);
			ft_strdel(line);
			*line = tmp;
		}
		else
		{
			ft_strdel(line);
			return (-1);
		}
	}
	return (i);
}

static void	init_getline(char **line, int *check, int *ret)
{
	*line = NULL;
	*check = BUFF_SIZE;
	*ret = -2;
}

int			ft_getline(char **line)
{
	static char	buff[BUFF_SIZE] = "\0";
	int			check;
	int			ret;
	int			i;

	if (line == NULL || BUFF_SIZE < 1)
		return (-1);
	init_getline(line, &check, &ret);
	while (check == BUFF_SIZE)
	{
		if (buff[0] == '\0')
		{
			if ((ret = read(0, buff, BUFF_SIZE)) == -1)
				return (-1);
			if (ret == 0 && *line == NULL)
				return (0);
		}
		if ((i = flush_buff(line, buff)) == -1)
			return (-1);
		check = (buff[i] != '\n' && ret != 0) ? BUFF_SIZE : i;
		ft_memmove(buff, buff + i + 1, BUFF_SIZE - i);
		ft_memset(buff + BUFF_SIZE - i, '\0', i);
	}
	return (1);
}
