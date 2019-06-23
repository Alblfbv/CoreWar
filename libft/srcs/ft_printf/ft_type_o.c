/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:45:03 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 09:57:44 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_type_o(va_list list, t_flags *flags)
{
	int			size;
	int			nbr_size;
	uintmax_t	nb;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = ft_get_nbr_u(list, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_get_nbr_size_u(nb, 8, &size);
	if (flags->hash && (nb > 0 || flags->precision < 0))
		size += 1;
	nbr_size = size;
	size = (flags->precision > size) ? flags->precision : size;
	if (flags->width && !flags->minus)
		size = ft_padding(flags, size);
	if (flags->hash && (nb > 0 || flags->precision < 0))
		ft_write_main("0", 1, flags);
	while (nbr_size++ < flags->precision)
		ft_write_main("0", 1, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_putnbr_base_intmax_t_u(nb, "01234567", 8, flags);
	if (flags->width && flags->minus)
		size = ft_padding(flags, size);
	return (size);
}
