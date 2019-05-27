/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:43:44 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 12:24:35 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_display_padding(t_flags *flags, uintmax_t nb,
						int *size, char *base)
{
	int					width;
	int					precision;

	if (flags->precision <= 0 && flags->width <= 0)
	{
		if (flags->type == 'p' && *size > 0)
			*size += 2;
		return ;
	}
	width = 0;
	precision = flags->precision - *size;
	*size = (flags->precision > *size) ? flags->precision : *size;
	while (flags->minus && width++ < precision)
		ft_write_main("0", 1, flags);
	if (flags->minus && flags->precision != -1)
		ft_putnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	width = 0;
	while (width++ < flags->width - (*size + (flags->type == 'p' ? 2 : 0)))
		ft_write_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	width = 0;
	while (!flags->minus && width++ < precision)
		ft_write_main("0", 1, flags);
	if (*size > 0 && flags->type == 'p')
		*size += 2;
}

int						ft_handle_hash_key(uintmax_t nb, t_flags *flags,
						int *size, char *hkey)
{
	int					precision;

	precision = 0;
	if (nb == 0 && flags->type != 'p')
		flags->hash = 0;
	if (flags->hash && (!flags->width || flags->minus || flags->zero
				|| (precision = flags->precision > *size)))
		ft_write_main(hkey, ft_strlen(hkey), flags);
	if (flags->hash && ((flags->width) && !precision) && flags->type != 'p')
		*size += ft_strlen(hkey);
	return (precision);
}

int						ft_add_padding(va_list list, t_flags *flags,
						char *base, char *hkey)
{
	int					size;
	uintmax_t			nb;
	int					precision;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = ft_get_nbr_u(list, flags);
	ft_get_nbr_size_u(nb, ft_strlen(base), &size);
	precision = ft_handle_hash_key(nb, flags, &size, hkey);
	if (flags->precision == -1 && nb == 0)
		size = 0;
	ft_display_padding(flags, nb, &size, base);
	if (flags->hash && flags->width && !flags->minus && !flags->zero
			&& !precision)
		ft_write_main(hkey, ft_strlen(hkey), flags);
	if ((!flags->width || !flags->minus) && size > 0)
		ft_putnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	if (flags->hash && size > 0 && ((!flags->width || flags->minus)
				|| precision) && flags->type != 'p')
		size += ft_strlen(hkey);
	if (size == 0 && flags->type == 'p')
		size = 2;
	return (flags->width - size > 0 ? flags->width : size);
}
