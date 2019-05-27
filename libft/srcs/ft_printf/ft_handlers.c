/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 02:05:36 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/01 11:21:16 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_handle_width(char **str, va_list list, t_flags *flags)
{
	int			width;

	if ((width = ft_atoi(*str)) > 0 || **str == '*')
	{
		if (**str == '*')
		{
			width = va_arg(list, int);
			if (width < 0)
				flags->minus = 1;
			flags->width = (width < 0 ? width * -1 : width);
			width = 1;
		}
		else
			flags->width = width;
		while (width > 0 && (*str += 1))
			width /= 10;
		return (1);
	}
	return (0);
}

int				ft_handle_flags(char **str, t_flags *flags)
{
	if (*(*str) == '-')
		flags->minus = 1;
	else if (*(*str) == '+')
		flags->plus = 1;
	else if (*(*str) == ' ')
		flags->space = 1;
	else if (*(*str) == '0')
		flags->zero = 1;
	else if (*(*str) == '#')
		flags->hash = 1;
	else
		return (0);
	(*str)++;
	return (1);
}

int				ft_handle_length(char **str, t_flags *flags)
{
	if (**str == 'h' && *(*str + 1) == 'h')
		ft_adjust_length(str, flags, LENGTH_HH, 2);
	else if (**str == 'h')
		ft_adjust_length(str, flags, LENGTH_H, 1);
	else if (**str == 'l' && *(*str + 1) == 'l')
		ft_adjust_length(str, flags, LENGTH_LL, 2);
	else if (**str == 'l')
		ft_adjust_length(str, flags, LENGTH_L, 1);
	else if (**str == 'z')
		ft_adjust_length(str, flags, LENGTH_Z, 1);
	else if (**str == 'j')
		ft_adjust_length(str, flags, LENGTH_J, 1);
	else
		return (0);
	return (1);
}

int				ft_handle_precision(char **str, va_list list, t_flags *flags)
{
	int			precision;

	if (**str == '.')
	{
		*str += 1;
		if (!ft_isdigit(**str) && **str != '*')
		{
			flags->precision = -1;
			return (1);
		}
		precision = (**str == '*') ? va_arg(list, int) : ft_atoi(*str);
		flags->precision = (precision == 0) ? -1 : precision;
		if (flags->precision < 0 && flags->precision != -1)
			flags->precision = 0;
		if (**str == '*')
			precision = 1;
		else if (precision == 0)
			*str += 1;
		while (precision > 0 && (*str = *str += 1))
			precision /= 10;
		return (1);
	}
	return (0);
}
