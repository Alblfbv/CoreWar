/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_d_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:42:21 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:42:30 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int			ft_dtype_dec_cap(va_list list, t_dflags *flags)
{
	flags->length_type = LENGTH_L;
	return (ft_dtype_dec(list, flags));
}
