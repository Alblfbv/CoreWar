/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:12:05 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/09 11:31:33 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		index;
	size_t		len;

	index = 0;
	len = ft_strlen(s1);
	while (s2[index] != '\0' && index != n)
	{
		s1[len] = s2[index];
		index++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
