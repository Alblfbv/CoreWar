/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpadding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:40:27 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:40:33 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int						ft_dpadding(t_dflags *flags, int size)
{
	int					width;

	if (flags->width <= 0)
		return (size);
	width = 0;
	while (width++ < flags->width - size)
		ft_dwrite_main((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	return (size + width - 1);
}
