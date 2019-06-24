/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfloat_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:38:42 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:38:50 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void					ft_dbefore_point(double *nb, char **str, int *index,
						double df)
{
	char				*res;

	res = *str;
	while ((int)*nb != 0)
	{
		res[(*index)++] = (char)((*nb / df) + 48);
		*nb -= (int)(*nb / df) * df;
		df /= 10;
	}
}

void					ft_dafter_point(int precision, int *index, double nbr,
						char **str)
{
	int					i;
	int					tmp;
	char				*res;

	nbr *= 10;
	i = 0;
	res = *str;
	res[(*index)++] = '.';
	while (i++ < precision)
	{
		if ((int)nbr == 0)
		{
			res[(*index)++] = '0';
			continue ;
		}
		tmp = ((int)nbr != 9) ? (int)(nbr + 0.01) : (int)nbr;
		res[(*index)++] = (char)(tmp + 48);
		nbr = (nbr - tmp) * 10;
	}
}

int						ft_df_atoi(double nbr, char **s, int precision)
{
	int					index;
	int					size;
	char				*str;
	int					sign;
	double				df;

	size = 1;
	sign = 0;
	if (nbr < 0 && size++ && (sign = 1) == 1)
		nbr = -nbr;
	df = ft_ddiv_factor(nbr, &size);
	size += precision;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	index = 0;
	if (sign)
		str[index++] = '-';
	ft_dbefore_point(&nbr, &str, &index, df);
	ft_dafter_point(precision, &index, nbr, &str);
	str[--index] = '\0';
	*s = str;
	return (size);
}
