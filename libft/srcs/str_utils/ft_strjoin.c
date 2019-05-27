/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:38:08 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/26 16:25:54 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*snew;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(snew = ft_strnew(size)))
		return (NULL);
	while (*s1)
	{
		snew[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		snew[i++] = *s2;
		s2++;
	}
	snew[i] = '\0';
	return (snew);
}
