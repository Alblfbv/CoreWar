/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:27:44 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/15 14:12:36 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		n;

	if (!*s1)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	n = ft_strlen(s2);
	while (len-- >= n && *s1)
	{
		if (*s1 == *s2 && !ft_memcmp(s1, s2, n))
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
