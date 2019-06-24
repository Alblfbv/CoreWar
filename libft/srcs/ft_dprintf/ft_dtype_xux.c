/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_xux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:45:54 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:45:58 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int						ft_dtype_x(va_list list, t_dflags *flags)
{
	return (ft_dadd_padding(list, flags, "0123456789abcdef", "0x"));
}

int						ft_dtype_x_cap(va_list list, t_dflags *flags)
{
	return (ft_dadd_padding(list, flags, "0123456789ABCDEF", "0X"));
}

int						ft_dtype_u(va_list list, t_dflags *flags)
{
	return (ft_dadd_padding(list, flags, "0123456789", NULL));
}
