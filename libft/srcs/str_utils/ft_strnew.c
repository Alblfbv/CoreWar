/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:21:08 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/03/25 17:13:20 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strnew(size_t size)
{
	size_t				index;
	char				*str;

	index = -1;
	while (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++index < (size + 1))
		str[index] = '\0';
	return (str);
}
