/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgen_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:39:03 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:39:07 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void					ft_dadjust_length(char **str, t_dflags *flags,
						int flag_type, int size)
{
	*str += size;
	if (flags->length_type < flag_type)
		flags->length_type = flag_type;
}
