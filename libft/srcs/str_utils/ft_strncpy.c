/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:51:25 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/24 20:34:09 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t		index;

	index = 0;
	while (index < len && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	if (index != len && !src[index])
	{
		while (index < len)
		{
			dest[index] = '\0';
			index++;
		}
	}
	return (dest);
}
