/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:42:47 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:43:09 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int							ft_dtype_dec(va_list list, t_dflags *flags)
{
	int						size;
	intmax_t				nbr;
	int						precision;

	if (flags->precision != 0)
		flags->zero = 0;
	nbr = ft_dget_nbr(list, flags);
	size = 0;
	ft_dget_nbr_size_u((uintmax_t)(nbr < 0 ? -nbr : nbr), 10, &size);
	precision = flags->precision - size;
	size = (flags->precision > size) ? flags->precision : size;
	size = (flags->precision == -1 && nbr == 0) ? 0 : size;
	size += (nbr >= 0 && (flags->plus || flags->space)) ? 1 : 0;
	if (nbr < 0)
		size += 1;
	size = ft_dput_dec(flags, size, precision, nbr);
	size = (flags->minus) ? ft_dpadding(flags, size) : size;
	return (size);
}
