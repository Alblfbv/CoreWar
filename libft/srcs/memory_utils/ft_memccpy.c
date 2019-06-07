/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:56:26 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/15 15:27:43 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*s;
	char			*d;
	char			tmp;

	s = (char*)src;
	d = (char*)dest;
	tmp = (char)c;
	while (n != 0)
	{
		*d = *s;
		if (*s == tmp)
			return ((void*)++d);
		s++;
		d++;
		n--;
	}
	return (NULL);
}
