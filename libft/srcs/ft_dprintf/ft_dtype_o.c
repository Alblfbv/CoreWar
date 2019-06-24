/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:43:39 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:43:43 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int				ft_dtype_o(va_list list, t_dflags *flags)
{
	int			size;
	int			nbr_size;
	uintmax_t	nb;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = ft_dget_nbr_u(list, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_dget_nbr_size_u(nb, 8, &size);
	if (flags->hash && (nb > 0 || flags->precision < 0))
		size += 1;
	nbr_size = size;
	size = (flags->precision > size) ? flags->precision : size;
	if (flags->width && !flags->minus)
		size = ft_dpadding(flags, size);
	if (flags->hash && (nb > 0 || flags->precision < 0))
		ft_dwrite_main("0", 1, flags);
	while (nbr_size++ < flags->precision)
		ft_dwrite_main("0", 1, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_dputnbr_base_intmax_t_u(nb, "01234567", 8, flags);
	if (flags->width && flags->minus)
		size = ft_dpadding(flags, size);
	return (size);
}
