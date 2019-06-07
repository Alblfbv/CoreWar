/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 07:45:15 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 17:40:57 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_put_sign(intmax_t nbr, t_flags *flags)
{
	if (nbr < 0)
		ft_write_main("-", 1, flags);
	if (flags->plus && nbr >= 0)
		ft_write_main("+", 1, flags);
	else if (flags->space && nbr >= 0)
		ft_write_main(" ", 1, flags);
}

double				ft_div_factor(double nbr, int *size)
{
	double			index;

	index = 1;
	while ((int)(nbr /= 10) != 0 && (*size)++)
		index *= 10;
	return (index);
}

int					ft_put_dec(t_flags *flags, int size,
					int prec, intmax_t nbr)
{
	int				width_size;
	int				width;

	width = 0;
	width_size = 0;
	if (!flags->minus)
	{
		if (flags->width && flags->zero)
			ft_put_sign(nbr, flags);
		width_size = ft_padding(flags, size) - size;
	}
	if ((flags->width && (flags->minus || !flags->zero))
			|| !flags->width)
		ft_put_sign(nbr, flags);
	while (width++ < prec)
		ft_write_main("0", 1, flags);
	if (size > 0)
		ft_putnbr_base_intmax_t_u((uintmax_t)(
					nbr < 0 ? -nbr : nbr),
			"0123456789", 10, flags);
	return (size + width_size);
}
