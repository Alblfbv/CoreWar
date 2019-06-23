/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:26:29 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 18:33:31 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_type_f(va_list list, t_flags *flags)
{
	char			*nbr;
	int				size;
	double			num;

	if (flags->precision <= 0)
		flags->precision = 7;
	num = va_arg(list, double);
	size = ft_f_atoi(num, &nbr, flags->precision);
	ft_write_main(nbr, size, flags);
	free(nbr);
	return (size);
}
