/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:31:39 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 11:12:19 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_padding(t_flags *flags, int size)
{
	int					width;

	if (flags->width <= 0)
		return (size);
	width = 0;
	while (width++ < flags->width - size)
		ft_write_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	return (size + width - 1);
}
