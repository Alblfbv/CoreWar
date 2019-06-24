/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbase_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:38:23 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:38:33 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void				ft_dputnbr_base_intmax_t_u(uintmax_t nbr, char *str,
					uintmax_t str_length, t_dflags *flags)
{
	if (nbr >= str_length)
		ft_dputnbr_base_intmax_t_u(nbr / str_length, str, str_length, flags);
	ft_dputchar_f(str[nbr % str_length], flags);
}

void				ft_dget_nbr_size_u(uintmax_t nbr, uintmax_t str_length,
					int *size)
{
	*size += 1;
	while (nbr >= str_length)
	{
		nbr /= str_length;
		*size += 1;
	}
}
