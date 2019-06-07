/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 06:19:33 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 18:30:03 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_type_perc(va_list list, t_flags *flags)
{
	int				width;

	(void)list;
	if (flags->width)
	{
		if (flags->minus)
			ft_write_main("%", 1, flags);
		width = 0;
		while (width++ < flags->width - 1)
			ft_write_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_write_main("%", 1, flags);
	return ((flags->width) ? flags->width : 1);
}
