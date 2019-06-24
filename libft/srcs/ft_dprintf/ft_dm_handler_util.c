/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dm_handler_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:39:45 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:39:51 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_dtypes					g_dtypes[FT_NUM] = {
	{'c', ft_type_char}, {'%', ft_type_perc},
	{'s', ft_type_s}, {'i', ft_type_dec}, {'d', ft_type_dec},
	{'x', ft_type_x}, {'X', ft_type_x_cap}, {'o', ft_type_o},
	{'f', ft_type_f}, {'u', ft_type_u}, {'U', ft_type_u_cap},
	{'D', ft_type_dec_cap}, {'O', ft_type_o_cap}, {'p', ft_type_p}};

void					ft_dinit_flags(t_dflags *flags, int fd)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->length_type = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->fd = fd;
}

static int				ft_dpass_to_type(char **str, va_list list,
						t_dflags *flags)
{
	int					index;
	int					size;

	index = 0;
	while (index < FT_NUM)
	{
		if (**str == g_dtypes[index].symbol)
		{
			*str += 1;
			flags->type = g_dtypes[index].symbol;
			return (g_dtypes[index].f(list, flags));
		}
		index++;
	}
	size = 1;
	if (!flags->minus)
		size = ft_dpadding(flags, size);
	ft_dwrite_main(*str, 1, flags);
	if (flags->minus)
		size = ft_dpadding(flags, size);
	*str += 1;
	return (size);
}

int						ft_dmulti_handler(char **str, va_list list,
						t_dflags *flags, int fd)
{
	int					f_status;

	ft_dinit_flags(flags, fd);
	while (**str)
	{
		f_status = 0;
		while (ft_dhandle_flags(str, flags)
				|| ft_dhandle_width(str, list, flags)
				|| ft_dhandle_precision(str, list, flags)
				|| ft_dhandle_length(str, flags))
			f_status = 1;
		if (ft_isalpha(**str) || **str == '%')
			return (ft_dpass_to_type(str, list, flags));
		else if (!(*(*str + 1) || !f_status))
			return (0);
	}
	return (0);
}
