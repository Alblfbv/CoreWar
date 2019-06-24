/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhandlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:39:21 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:39:29 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int				ft_dhandle_width(char **str, va_list list, t_dflags *flags)
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

int				ft_dhandle_flags(char **str, t_dflags *flags)
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

int				ft_dhandle_length(char **str, t_dflags *flags)
{
	if (**str == 'h' && *(*str + 1) == 'h')
		ft_dadjust_length(str, flags, LENGTH_HH, 2);
	else if (**str == 'h')
		ft_dadjust_length(str, flags, LENGTH_H, 1);
	else if (**str == 'l' && *(*str + 1) == 'l')
		ft_dadjust_length(str, flags, LENGTH_LL, 2);
	else if (**str == 'l')
		ft_dadjust_length(str, flags, LENGTH_L, 1);
	else if (**str == 'z')
		ft_dadjust_length(str, flags, LENGTH_Z, 1);
	else if (**str == 'j')
		ft_dadjust_length(str, flags, LENGTH_J, 1);
	else
		return (0);
	return (1);
}

int				ft_dhandle_precision(char **str, va_list list, t_dflags *flags)
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
