/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:40:43 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:40:47 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int						ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list				list;
	char				*str;
	t_dflags			flags;
	int					bytes;

	bytes = 0;
	flags.bytes = 0;
	flags.t_bytes = 0;
	va_start(list, format);
	str = (char*)format;
	while (*str)
		if (*str == '%')
		{
			str++;
			bytes += ft_dmulti_handler(&str, list, &flags, fd);
		}
		else
			bytes += ft_dwrite_bfp(&str, &flags);
	va_end(list);
	if (flags.bytes > 0)
		write(fd, flags.buffer, (size_t)flags.bytes);
	return (bytes);
}
