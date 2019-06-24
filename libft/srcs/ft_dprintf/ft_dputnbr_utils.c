/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:41:10 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:41:14 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void				ft_dput_sign(intmax_t nbr, t_dflags *flags)
{
	if (nbr < 0)
		ft_dwrite_main("-", 1, flags);
	if (flags->plus && nbr >= 0)
		ft_dwrite_main("+", 1, flags);
	else if (flags->space && nbr >= 0)
		ft_dwrite_main(" ", 1, flags);
}

double				ft_ddiv_factor(double nbr, int *size)
{
	double			index;

	index = 1;
	while ((int)(nbr /= 10) != 0 && (*size)++)
		index *= 10;
	return (index);
}

int					ft_dput_dec(t_dflags *flags, int size,
					int prec, intmax_t nbr)
{
	int				width_size;
	int				width;

	width = 0;
	width_size = 0;
	if (!flags->minus)
	{
		if (flags->width && flags->zero)
			ft_dput_sign(nbr, flags);
		width_size = ft_dpadding(flags, size) - size;
	}
	if ((flags->width && (flags->minus || !flags->zero))
			|| !flags->width)
		ft_dput_sign(nbr, flags);
	while (width++ < prec)
		ft_dwrite_main("0", 1, flags);
	if (size > 0)
		ft_dputnbr_base_intmax_t_u((uintmax_t)(
					nbr < 0 ? -nbr : nbr),
			"0123456789", 10, flags);
	return (size + width_size);
}
