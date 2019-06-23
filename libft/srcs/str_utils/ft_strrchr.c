/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:09:12 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/13 11:46:07 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = (int)ft_strlen(s) + 1;
	while (index--)
		if (*(s + index) == (char)c)
			return ((char *)s + index);
	return (NULL);
}
