/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 06:09:00 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 17:47:48 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_type_char(va_list list, t_flags *flags)
{
	int					c;
	int					width;

	c = va_arg(list, int);
	width = 0;
	if (flags->width)
	{
		if (flags->minus)
			ft_write_main(&c, 1, flags);
		while (width++ < flags->width - 1)
			ft_write_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_write_main(&c, 1, flags);
	return ((flags->width) ? width : 1);
}
