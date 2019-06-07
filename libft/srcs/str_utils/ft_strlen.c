/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:00:17 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/03/08 10:50:08 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlen(const char *s)
{
	size_t		counter;

	counter = 0;
	if (!s)
		return (counter);
	while (s[counter] != '\0')
		counter++;
	return (counter);
}
