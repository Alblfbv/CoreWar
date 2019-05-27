/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_o_cap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:25:30 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 09:55:41 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type_o_cap(va_list list, t_flags *flags)
{
	flags->length_type = LENGTH_L;
	return (ft_type_o(list, flags));
}
