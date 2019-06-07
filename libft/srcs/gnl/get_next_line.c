/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:29:34 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/03/25 16:25:23 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t			smart_copy(char **s1, char *s2)
{
	char	*tmp;

	if (*s1 == NULL)
	{
		if (!(*s1 = ft_strdup(s2)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(*s1, s2)))
			return (0);
		ft_strdel(s1);
		*s1 = tmp;
	}
	return (1);
}

t_buffer		*get_fd_buffer(const int fd, t_buffer **buff_lst)
{
	t_buffer	*tmp_lst;

	tmp_lst = *buff_lst;
	while (tmp_lst && tmp_lst->fd != fd)
		tmp_lst = tmp_lst->next;
	if (tmp_lst && tmp_lst->fd == fd)
		return (tmp_lst);
	else
	{
		if (!(tmp_lst = (t_buffer *)malloc(sizeof(t_buffer))))
			return (NULL);
		tmp_lst->fd = fd;
		ft_bzero(tmp_lst->buff, BUF_SIZE + 1);
		tmp_lst->next = *buff_lst;
		*buff_lst = tmp_lst;
		return (*buff_lst);
	}
}

ssize_t			read_from_fd(const int fd, t_buffer *fd_lst, char **line)
{
	char		buffer[BUF_SIZE + 1];
	ssize_t		nb_read;
	char		*ind;

	ft_bzero(buffer, BUF_SIZE + 1);
	while ((nb_read = read(fd, buffer, BUF_SIZE)) > 0)
	{
		if (!(ind = ft_strchr(buffer, '\n')))
		{
			if (!(smart_copy(line, buffer)))
				return (-1);
			ft_bzero(buffer, BUF_SIZE + 1);
		}
		else
		{
			ft_strcpy(fd_lst->buff, ind + 1);
			*ind = '\0';
			if (!(smart_copy(line, buffer)))
				return (-1);
			return (nb_read);
		}
	}
	return (nb_read);
}

ssize_t			read_from_buffer(t_buffer *fd_lst, char **line)
{
	char	*ind;
	char	tmp[BUF_SIZE + 1];

	if (ft_strlen(fd_lst->buff) == 0)
		return (0);
	else if (!(ind = ft_strchr(fd_lst->buff, '\n')))
	{
		if (!(smart_copy(line, fd_lst->buff)))
			return (-1);
		ft_bzero(fd_lst->buff, BUF_SIZE + 1);
		return (0);
	}
	else
	{
		ft_bzero(tmp, BUF_SIZE + 1);
		ft_strcpy(tmp, ind + 1);
		*ind = '\0';
		if (!(smart_copy(line, fd_lst->buff)))
			return (-1);
		ft_bzero(fd_lst->buff, BUF_SIZE + 1);
		ft_strcpy(fd_lst->buff, tmp);
		return (1);
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_buffer	*buff_lst;
	ssize_t			nb_read;
	t_buffer		*fd_lst;
	char			buff[BUF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(fd_lst = get_fd_buffer(fd, &buff_lst)))
		return (-1);
	*line = NULL;
	if ((nb_read = read_from_buffer(fd_lst, line)) == -1)
		return (-1);
	else if (nb_read == 1)
		return (1);
	else
	{
		if ((nb_read = read_from_fd(fd, fd_lst, line)) == -1)
			return (-1);
		if (nb_read == 0 && ft_strlen(*line) == 0)
			return (0);
		return (1);
	}
}
