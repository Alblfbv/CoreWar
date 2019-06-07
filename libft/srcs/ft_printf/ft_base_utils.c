/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:42:14 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 11:19:36 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnbr_base_intmax_t_u(uintmax_t nbr, char *str,
					uintmax_t str_length, t_flags *flags)
{
	if (nbr >= str_length)
		ft_putnbr_base_intmax_t_u(nbr / str_length, str, str_length, flags);
	ft_putchar_f(str[nbr % str_length], flags);
}

void				ft_get_nbr_size_u(uintmax_t nbr, uintmax_t str_length,
					int *size)
{
	*size += 1;
	while (nbr >= str_length)
	{
		nbr /= str_length;
		*size += 1;
	}
}
