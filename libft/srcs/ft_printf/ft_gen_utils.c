/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 03:09:50 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/25 12:31:47 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_adjust_length(char **str, t_flags *flags,
						int flag_type, int size)
{
	*str += size;
	if (flags->length_type < flag_type)
		flags->length_type = flag_type;
}
