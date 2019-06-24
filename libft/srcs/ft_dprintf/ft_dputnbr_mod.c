/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:40:57 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:41:01 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void					ft_ddisplay_padding(t_dflags *flags, uintmax_t nb,
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
		ft_dwrite_main("0", 1, flags);
	if (flags->minus && flags->precision != -1)
		ft_dputnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	width = 0;
	while (width++ < flags->width - (*size + (flags->type == 'p' ? 2 : 0)))
		ft_dwrite_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	width = 0;
	while (!flags->minus && width++ < precision)
		ft_dwrite_main("0", 1, flags);
	if (*size > 0 && flags->type == 'p')
		*size += 2;
}

int						ft_dhandle_hash_key(uintmax_t nb, t_dflags *flags,
						int *size, char *hkey)
{
	int					precision;

	precision = 0;
	if (nb == 0 && flags->type != 'p')
		flags->hash = 0;
	if (flags->hash && (!flags->width || flags->minus || flags->zero
				|| (precision = flags->precision > *size)))
		ft_dwrite_main(hkey, ft_strlen(hkey), flags);
	if (flags->hash && ((flags->width) && !precision) && flags->type != 'p')
		*size += ft_strlen(hkey);
	return (precision);
}

int						ft_dadd_padding(va_list list, t_dflags *flags,
						char *base, char *hkey)
{
	int					size;
	uintmax_t			nb;
	int					precision;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = ft_dget_nbr_u(list, flags);
	ft_dget_nbr_size_u(nb, ft_strlen(base), &size);
	precision = ft_dhandle_hash_key(nb, flags, &size, hkey);
	if (flags->precision == -1 && nb == 0)
		size = 0;
	ft_ddisplay_padding(flags, nb, &size, base);
	if (flags->hash && flags->width && !flags->minus && !flags->zero
			&& !precision)
		ft_dwrite_main(hkey, ft_strlen(hkey), flags);
	if ((!flags->width || !flags->minus) && size > 0)
		ft_dputnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	if (flags->hash && size > 0 && ((!flags->width || flags->minus)
				|| precision) && flags->type != 'p')
		size += ft_strlen(hkey);
	if (size == 0 && flags->type == 'p')
		size = 2;
	return (flags->width - size > 0 ? flags->width : size);
}
