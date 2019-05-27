/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:21:34 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/13 12:01:51 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		k;
	int		tmp;

	if (!ft_strlen(to_find))
		return ((char *)str);
	i = -1;
	tmp = 0;
	while (*(str + ++i) && !tmp)
	{
		if (*(str + i) == *(to_find + 0))
		{
			j = 0;
			k = i;
			tmp = 1;
			while (*(to_find + j))
				if (*(to_find + j++) != *(str + k++))
					tmp = 0;
			if (tmp)
				return ((char *)str + i);
		}
	}
	return (NULL);
}
