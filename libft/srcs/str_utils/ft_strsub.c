/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:26:23 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/09 18:21:04 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*snew;
	size_t	i;

	i = 0;
	if (!s || !(snew = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		snew[i] = s[start + i];
		i++;
	}
	return (snew);
}
