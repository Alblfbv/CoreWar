/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:19:44 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/09 11:21:26 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ptr1;
	const unsigned char		*ptr2;

	ptr1 = (const unsigned char*)s1;
	ptr2 = (const unsigned char*)s2;
	while (n)
	{
		if (*ptr1 != *ptr2)
			return ((int)(*ptr1 - *ptr2));
		n--;
		ptr1++;
		ptr2++;
	}
	return (0);
}
