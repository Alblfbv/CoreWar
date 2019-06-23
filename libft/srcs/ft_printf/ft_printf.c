/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:37:42 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 15:52:06 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *restrict format, ...)
{
	va_list				list;
	char				*str;
	t_flags				flags;
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
			bytes += ft_multi_handler(&str, list, &flags);
		}
		else
			bytes += ft_write_bfp(&str, &flags);
	va_end(list);
	if (flags.bytes > 0)
		write(1, flags.buffer, (size_t)flags.bytes);
	return (bytes);
}
