/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_handler_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 01:56:44 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 12:22:36 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_types					g_types[FT_NUM] = {
	{'c', ft_type_char}, {'%', ft_type_perc},
	{'s', ft_type_s}, {'i', ft_type_dec}, {'d', ft_type_dec},
	{'x', ft_type_x}, {'X', ft_type_x_cap}, {'o', ft_type_o},
	{'f', ft_type_f}, {'u', ft_type_u}, {'U', ft_type_u_cap},
	{'D', ft_type_dec_cap}, {'O', ft_type_o_cap}, {'p', ft_type_p}};

void					ft_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->length_type = 0;
	flags->precision = 0;
	flags->width = 0;
}

static int				ft_pass_to_type(char **str, va_list list,
						t_flags *flags)
{
	int					index;
	int					size;

	index = 0;
	while (index < FT_NUM)
	{
		if (**str == g_types[index].symbol)
		{
			*str += 1;
			flags->type = g_types[index].symbol;
			return (g_types[index].f(list, flags));
		}
		index++;
	}
	size = 1;
	if (!flags->minus)
		size = ft_padding(flags, size);
	ft_write_main(*str, 1, flags);
	if (flags->minus)
		size = ft_padding(flags, size);
	*str += 1;
	return (size);
}

int						ft_multi_handler(char **str, va_list list,
						t_flags *flags)
{
	int					f_status;

	ft_init_flags(flags);
	while (**str)
	{
		f_status = 0;
		while (ft_handle_flags(str, flags)
				|| ft_handle_width(str, list, flags)
				|| ft_handle_precision(str, list, flags)
				|| ft_handle_length(str, flags))
			f_status = 1;
		if (ft_isalpha(**str) || **str == '%')
			return (ft_pass_to_type(str, list, flags));
		else if (!(*(*str + 1) || !f_status))
			return (0);
	}
	return (0);
}
