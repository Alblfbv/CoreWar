/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:59:18 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/03/08 10:36:33 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 42
# include "libft.h"

typedef struct			s_buffer
{
	int					fd;
	char				buff[BUF_SIZE + 1];
	struct s_buffer		*next;
}						t_buffer;

int						get_next_line(const int fd, char **line);

#endif
