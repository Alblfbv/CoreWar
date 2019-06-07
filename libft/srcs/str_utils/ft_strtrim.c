/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:15:42 by mndhlovu          #+#    #+#             */
/*   Updated: 2018/11/14 13:20:46 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_blank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	index;
	size_t	len;

	if (s)
	{
		len = ft_strlen(s) - 1;
		index = 0;
		while (ft_is_blank(s[index]) && s[index])
			index++;
		if (!s[index])
			return (ft_strnew(1));
		while (len != index && ft_is_blank(s[len]))
			len--;
		if (!index && len == ft_strlen(s) - 1)
		{
			str = ft_strsub(s, 0, ft_strlen(s));
			return (str);
		}
		str = ft_strsub(s, index, len - index + 1);
		if (!str)
			return (NULL);
		return (str);
	}
	return (NULL);
}
