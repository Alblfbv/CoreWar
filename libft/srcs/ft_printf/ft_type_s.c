/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:55:31 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 19:16:15 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_type_s(va_list list, t_flags *flags)
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
			ft_write_main(str, size, flags);
		width = 0;
		while (width++ < flags->width - size)
			ft_write_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_write_main((str) ? str : "(null)", size, flags);
	return (size + (flags->width - size > 0 ? flags->width - size : 0));
}
