/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:45:23 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:45:27 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int					ft_dtype_s(va_list list, t_dflags *flags)
{
	char			*str;
	int				width;
	int				size;

	str = va_arg(list, char*);
	size = (str) ? ft_strlen(str) : 6;
	size = (flags->precision == -1) ? 0 : size;
	if (flags->precision > 0 && flags->precision < size && size > 0)
		size = size - (size - flags->precision);
	if (flags->width)
	{
		if (flags->minus)
			ft_dwrite_main(str, size, flags);
		width = 0;
		while (width++ < flags->width - size)
			ft_dwrite_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_dwrite_main((str) ? str : "(null)", size, flags);
	return (size + (flags->width - size > 0 ? flags->width - size : 0));
}
