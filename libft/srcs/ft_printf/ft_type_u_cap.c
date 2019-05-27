/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u_cap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:07:32 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 19:08:14 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type_u_cap(va_list list, t_flags *flags)
{
	flags->length_type = LENGTH_L;
	return (ft_type_u(list, flags));
}
