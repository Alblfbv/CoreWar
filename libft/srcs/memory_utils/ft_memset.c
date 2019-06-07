/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:04:55 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/13 11:35:05 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void			*ft_memset(void *b, int c, size_t len)
{
	char		*tmp;
	size_t		index;

	index = 0;
	tmp = b;
	while (index < len)
		*(tmp + index++) = c;
	return (b);
}
