/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:06:49 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/09 11:28:46 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strcat(char *s1, const char *s2)
{
	size_t		index;
	size_t		len;

	index = 0;
	len = ft_strlen(s1);
	while (s2[index] != '\0')
	{
		s1[len] = s2[index];
		index++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
