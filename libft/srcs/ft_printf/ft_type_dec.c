/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:16:38 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 17:52:23 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_type_dec(va_list list, t_flags *flags)
{
	int						size;
	intmax_t				nbr;
	int						precision;

	if (flags->precision != 0)
		flags->zero = 0;
	nbr = ft_get_nbr(list, flags);
	size = 0;
	ft_get_nbr_size_u((uintmax_t)(nbr < 0 ? -nbr : nbr), 10, &size);
	precision = flags->precision - size;
	size = (flags->precision > size) ? flags->precision : size;
	size = (flags->precision == -1 && nbr == 0) ? 0 : size;
	size += (nbr >= 0 && (flags->plus || flags->space)) ? 1 : 0;
	if (nbr < 0)
		size += 1;
	size = ft_put_dec(flags, size, precision, nbr);
	size = (flags->minus) ? ft_padding(flags, size) : size;
	return (size);
}
