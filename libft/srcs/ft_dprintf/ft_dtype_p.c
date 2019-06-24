/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtype_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:44:50 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:44:54 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int				ft_dtype_p(va_list list, t_dflags *flags)
{
	flags->length_type = LENGTH_L;
	flags->hash = 1;
	return (ft_dtype_x(list, flags));
}
