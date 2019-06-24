/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:43:20 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:43:26 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int					ft_dtype_f(va_list list, t_dflags *flags)
{
	char			*nbr;
	int				size;
	double			num;

	if (flags->precision <= 0)
		flags->precision = 7;
	num = va_arg(list, double);
	size = ft_df_atoi(num, &nbr, flags->precision);
	ft_dwrite_main(nbr, size, flags);
	free(nbr);
	return (size);
}
