/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 06:25:38 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 17:39:45 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t				ft_get_nbr(va_list list, t_flags *flags)
{
	intmax_t			nbr;

	nbr = va_arg(list, intmax_t);
	if (flags->length_type == LENGTH_L)
		nbr = (long int)nbr;
	else if (flags->length_type == LENGTH_LL)
		nbr = (long long int)nbr;
	else if (flags->length_type == LENGTH_H)
		nbr = (short int)nbr;
	else if (flags->length_type == LENGTH_HH)
		nbr = (char)nbr;
	else if (flags->length_type == LENGTH_J)
		nbr = (intmax_t)nbr;
	else if (flags->length_type == LENGTH_Z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t				ft_get_nbr_u(va_list list, t_flags *flags)
{
	uintmax_t			nbr;

	nbr = va_arg(list, uintmax_t);
	if (flags->length_type == LENGTH_L)
		nbr = (unsigned long int)nbr;
	else if (flags->length_type == LENGTH_LL)
		nbr = (unsigned long long int)nbr;
	else if (flags->length_type == LENGTH_H)
		nbr = (unsigned short int)nbr;
	else if (flags->length_type == LENGTH_HH)
		nbr = (unsigned char)nbr;
	else if (flags->length_type == LENGTH_J)
		nbr = (uintmax_t)nbr;
	else if (flags->length_type == LENGTH_Z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
