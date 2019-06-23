/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:02:38 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/13 11:38:33 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	int		index;

	index = -1;
	while (++index < (int)ft_strlen(s) + 1)
		if (*(s + index) == (char)c)
			return ((char *)s + index);
	return (NULL);
}
