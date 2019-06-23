/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:41:48 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/01/31 18:27:16 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_type_p(va_list list, t_flags *flags)
{
	flags->length_type = LENGTH_L;
	flags->hash = 1;
	return (ft_type_x(list, flags));
}
