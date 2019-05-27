/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:30:50 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/13 20:34:53 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_strtabdel(char ***tab)
{
	int				index;

	if (tab && *tab)
	{
		index = 0;
		while ((*tab)[index])
		{
			ft_strdel(&(*tab)[index]);
			++index;
		}
		free(*tab);
		*tab = NULL;
	}
}
