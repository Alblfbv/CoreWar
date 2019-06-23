/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:18:22 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/03/11 07:50:46 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nbwords(char const *s, char c)
{
	size_t			words;
	int				i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c && i != 0)
		{
			++words;
			while (s[i] && s[i] == c)
				++i;
		}
		else
			++i;
	}
	if (s[i] == '\0' && s[i - 1] != 'c')
		++words;
	return (words);
}

static int			ft_wordsalloc(char **tab, char const *s, char c)
{
	int				i;
	int				j;
	int				start;

	i = 0;
	start = 0;
	j = -1;
	while (s[i])
	{
		if (s[i + 1] == c || s[i + 1] == '\0')
		{
			if (!(tab[++j] = ft_strsub(s, start, i - start + 1)))
			{
				ft_strtabdel(&tab);
				return (2);
			}
			while (s[i + 1] == c)
				++i;
			start = ++i;
		}
		else
			++i;
	}
	tab[++j] = NULL;
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			nbwords;
	char			**tab;

	if (!s)
		return (NULL);
	nbwords = ft_nbwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (NULL);
	if (ft_wordsalloc(tab, s, c))
		return (NULL);
	return (tab);
}
