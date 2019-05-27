/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:18:08 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/09 11:33:30 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void		ft_strlcat_sub(char *d, const char *s, int ava_space)
{
	while (*s)
	{
		if (ava_space != 1)
		{
			*d = *s;
			d++;
			ava_space--;
		}
		s++;
	}
	*d = '\0';
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*d;
	const char		*s;
	size_t			len;
	size_t			ava_space;

	ava_space = size;
	d = dest;
	s = src;
	while (ava_space && *d)
	{
		d++;
		ava_space--;
	}
	len = d - dest;
	ava_space = size - len;
	if (!ava_space)
		return (len + ft_strlen(src));
	ft_strlcat_sub(d, s, ava_space);
	return (len + ft_strlen(src));
}
