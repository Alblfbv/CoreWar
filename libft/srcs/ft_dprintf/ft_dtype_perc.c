/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:45:06 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:45:10 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int					ft_dtype_perc(va_list list, t_dflags *flags)
{
	int				width;

	(void)list;
	if (flags->width)
	{
		if (flags->minus)
			ft_dwrite_main("%", 1, flags);
		width = 0;
		while (width++ < flags->width - 1)
			ft_dwrite_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_dwrite_main("%", 1, flags);
	return ((flags->width) ? flags->width : 1);
}
