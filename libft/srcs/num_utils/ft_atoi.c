/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:48 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/25 12:30:20 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isspace(int c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == ' ' || c == '\v' || c
			== '\r')
		return (1);
	return (0);
}

static int		ft_countnum(const char *str)
{
	int			counter;

	counter = 0;
	while (str[counter] && ft_isdigit(str[counter]))
		counter++;
	return (counter);
}

int				ft_atoi(const char *str)
{
	int			tmp;
	int			stat;
	int			len;

	tmp = 0;
	stat = -1;
	len = ft_countnum(str);
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		stat = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		tmp = tmp * 10 + *str - '0';
		str++;
	}
	if (stat == 0)
		return (-tmp);
	else
		return (tmp);
}
