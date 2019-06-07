/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 05:55:34 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 19:16:48 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_write_bfp(char **str, t_flags *flags)
{
	int			index;

	if (ft_strchr(*str, '%'))
		index = (int)(ft_strchr(*str, '%') - *str);
	else
		index = (int)ft_strlen(*str);
	ft_write_main(*str, index, flags);
	*str += index;
	return (index);
}

int				ft_putchar_f(char c, t_flags *flags)
{
	return (ft_write_main(&c, 1, flags));
}

int				ft_write_main(void *s, int size, t_flags *flags)
{
	int			i;
	char		*str;

	if (flags->bytes + size > BUFF_SIZE)
	{
		write(1, flags->buffer, (size_t)flags->bytes);
		flags->bytes = 0;
		if (size > BUFF_SIZE)
		{
			write(1, s, (size_t)size);
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
