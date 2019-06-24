/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:41:26 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:41:30 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int						ft_dtype_char(va_list list, t_dflags *flags)
{
	int					c;
	int					width;

	c = va_arg(list, int);
	width = 0;
	if (flags->width)
	{
		if (flags->minus)
			ft_dwrite_main(&c, 1, flags);
		while (width++ < flags->width - 1)
			ft_dwrite_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_dwrite_main(&c, 1, flags);
	return ((flags->width) ? width : 1);
}
