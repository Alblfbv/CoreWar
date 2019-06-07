/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:23:18 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/02/14 00:20:03 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define LENGTH_HH 1
# define LENGTH_H 2
# define LENGTH_L 3
# define FT_NUM 14
# define BUFF_SIZE 1028
# define LENGTH_LL 4
# define LENGTH_Z 5
# define LENGTH_J 6
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

typedef struct				s_flags
{
	int						zero;
	int						minus;
	int						plus;
	int						hash;
	int						space;
	int						width;
	int						length_type;
	int						precision;
	char					type;
	char					buffer[BUFF_SIZE];
	int						bytes;
	int						t_bytes;
}							t_flags;

typedef struct				s_types
{
	char					symbol;
	int						(*f)();
}							t_types;

int							ft_printf(const char *restrict format, ...);
void						ft_init_flags(t_flags *flags);
void						ft_test_container(t_flags *flags);
int							ft_multi_handle(char **str, t_flags *flags);
int							ft_multi_handler(char **str, va_list list,
							t_flags *flags);
int							ft_handle_width(char **str, va_list list,
							t_flags *flags);
int							ft_handle_length(char **str, t_flags *flags);
int							ft_handle_precision(char **str, va_list list,
							t_flags *flags);
int							ft_handle_flags(char **str, t_flags *flags);
int							ft_handle_hash(uintmax_t nb, t_flags *flags,
							int *size, char *hkey);
void						ft_display_padding(t_flags *flags, uintmax_t nbr,
							int *size, char *base);
void						ft_adjust_length(char **str, t_flags *flags,
							int length_type, int size);
int							ft_padding(t_flags *flags, int size);
int							ft_add_padding(va_list list, t_flags *flags,
							char *base, char *hkey);
double						ft_div_factor(double nbr, int *size);
intmax_t					ft_get_nbr(va_list list, t_flags *flags);
uintmax_t					ft_get_nbr_u(va_list list, t_flags *flags);
void						ft_put_sign(intmax_t nbr, t_flags *flags);
void						ft_after_point(int precision, int *index,
							double nbr, char **str);
int							ft_f_atoi(double nb, char **s, int precision);
int							ft_put_dec(t_flags *flags, int size,
							int prec, intmax_t nbr);
void						ft_putnbr_base_intmax_t_u(uintmax_t nbr, char *str,
							uintmax_t str_length, t_flags *flags);
void						ft_get_nbr_size_u(uintmax_t nbr,
							uintmax_t str_length, int *size);
int							ft_type_char(va_list list, t_flags *flags);
int							ft_type_perc(va_list list, t_flags *flags);
int							ft_type_s(va_list list, t_flags *flags);
int							ft_type_f(va_list list, t_flags *flags);
int							ft_type_dec(va_list list, t_flags *flags);
int							ft_type_x(va_list list, t_flags *flags);
int							ft_type_x_cap(va_list list, t_flags *flags);
int							ft_type_u(va_list list, t_flags *flags);
int							ft_type_o(va_list list, t_flags *flags);
int							ft_type_dec_cap(va_list list, t_flags *flags);
int							ft_type_o_cap(va_list list, t_flags *flags);
int							ft_type_u_cap(va_list list, t_flags *flags);
int							ft_type_p(va_list list, t_flags *flags);
int							ft_type_null(va_list list, t_flags *flags);
int							ft_write_main(void *s, int size, t_flags *flags);
int							ft_write_bfp(char **str, t_flags *flags);
int							ft_putchar_f(char c, t_flags *flags);

#endif
