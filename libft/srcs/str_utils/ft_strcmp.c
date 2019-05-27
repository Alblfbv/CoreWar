/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:33:42 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/09 17:56:30 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t		len;

	len = 0;
	while (s1[len] && s2[len] && s1[len] == s2[len])
		len++;
	return ((unsigned char)s1[len] - (unsigned char)s2[len]);
}
