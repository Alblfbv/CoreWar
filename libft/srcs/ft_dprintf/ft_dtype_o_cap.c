/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_o_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:44:30 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:44:35 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int			ft_dtype_o_cap(va_list list, t_dflags *flags)
{
	flags->length_type = LENGTH_L;
	return (ft_dtype_o(list, flags));
}
