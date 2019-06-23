/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:09:11 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/15 13:42:47 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memmove(void *s1, const void *s2, size_t len)
{
	char	*s;
	char	*d;
	size_t	index;

	index = -1;
	s = (char *)s2;
	d = (char *)s1;
	if (s < d)
		while ((int)(--len) >= 0)
			*(d + len) = *(s + len);
	else
		while (++index < len)
			*(d + index) = *(s + index);
	return (s1);
}
