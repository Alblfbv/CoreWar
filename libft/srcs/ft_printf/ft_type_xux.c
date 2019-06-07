/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_xux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:24:00 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 19:08:59 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_type_x(va_list list, t_flags *flags)
{
	return (ft_add_padding(list, flags, "0123456789abcdef", "0x"));
}

int						ft_type_x_cap(va_list list, t_flags *flags)
{
	return (ft_add_padding(list, flags, "0123456789ABCDEF", "0X"));
}

int						ft_type_u(va_list list, t_flags *flags)
{
	return (ft_add_padding(list, flags, "0123456789", NULL));
}
