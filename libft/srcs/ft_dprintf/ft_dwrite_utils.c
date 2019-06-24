/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dwrite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:46:09 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:46:14 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int				ft_dwrite_bfp(char **str, t_dflags *flags)
{
	int			index;

	if (ft_strchr(*str, '%'))
		index = (int)(ft_strchr(*str, '%') - *str);
	else
		index = (int)ft_strlen(*str);
	ft_dwrite_main(*str, index, flags);
	*str += index;
	return (index);
}

int				ft_dputchar_f(char c, t_dflags *flags)
{
	return (ft_dwrite_main(&c, 1, flags));
}

int				ft_dwrite_main(void *s, int size, t_dflags *flags)
{
	int			i;
	char		*str;

	if (flags->bytes + size > BUFF_SIZE)
	{
		write(flags->fd, flags->buffer, (size_t)flags->bytes);
		flags->bytes = 0;
		if (size > BUFF_SIZE)
		{
			write(flags->fd, s, (size_t)size);
			return (size);
		}
	}
	i = 0;
	str = s;
	while (i < size)
		flags->buffer[flags->bytes++] = str[i++];
	flags->t_bytes += size;
	return (size);
}
