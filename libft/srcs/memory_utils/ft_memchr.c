/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:28:41 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/13 11:10:34 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*tmp;
	size_t		index;

	tmp = (const char *)s;
	index = -1;
	while (++index < n)
		if (*(tmp + index) == (char)c)
			return ((void *)tmp + index);
	return (NULL);
}
