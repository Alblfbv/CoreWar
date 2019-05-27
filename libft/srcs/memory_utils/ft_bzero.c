/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:19:09 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/03/08 11:22:19 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void			ft_bzero(void *s, size_t n)
{
	size_t		index;

	index = 0;
	while (index < n)
	{
		((char *)s)[index] = '\0';
		index++;
	}
}
