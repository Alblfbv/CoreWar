/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_cap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:49:33 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 17:50:54 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type_dec_cap(va_list list, t_flags *flags)
{
	flags->length_type = LENGTH_L;
	return (ft_type_dec(list, flags));
}
