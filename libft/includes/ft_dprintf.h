/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:46:39 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/06/24 07:47:05 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
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

typedef struct				s_dflags
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
	int						fd;
	int						t_bytes;
}							t_dflags;

typedef struct				s_dtypes
{
	char					symbol;
	int						(*f)();
}							t_dtypes;

int							ft_dprintf(int fd, const char *restrict format, ...);
void						ft_dinit_flags(t_dflags *flags, int fd);
void						ft_dtest_container(t_dflags *flags);
int							ft_dmulti_handle(char **str, t_dflags *flags);
int							ft_dmulti_handler(char **str, va_list list,
							t_dflags *flags, int fd);
int							ft_dhandle_width(char **str, va_list list,
							t_dflags *flags);
int							ft_dhandle_length(char **str, t_dflags *flags);
int							ft_dhandle_precision(char **str, va_list list,
							t_dflags *flags);
int							ft_dhandle_flags(char **str, t_dflags *flags);
int							ft_dhandle_hash(uintmax_t nb, t_dflags *flags,
							int *size, char *hkey);
void						ft_ddisplay_padding(t_dflags *flags, uintmax_t nbr,
							int *size, char *base);
void						ft_dadjust_length(char **str, t_dflags *flags,
							int length_type, int size);
int							ft_dpadding(t_dflags *flags, int size);
int							ft_dadd_padding(va_list list, t_dflags *flags,
							char *base, char *hkey);
double						ft_ddiv_factor(double nbr, int *size);
intmax_t					ft_dget_nbr(va_list list, t_dflags *flags);
uintmax_t					ft_dget_nbr_u(va_list list, t_dflags *flags);
void						ft_dput_sign(intmax_t nbr, t_dflags *flags);
void						ft_dafter_point(int precision, int *index,
							double nbr, char **str);
int							ft_df_atoi(double nb, char **s, int precision);
int							ft_dput_dec(t_dflags *flags, int size,
							int prec, intmax_t nbr);
void						ft_dputnbr_base_intmax_t_u(uintmax_t nbr, char *str,
							uintmax_t str_length, t_dflags *flags);
void						ft_dget_nbr_size_u(uintmax_t nbr,
							uintmax_t str_length, int *size);
int							ft_dtype_char(va_list list, t_dflags *flags);
int							ft_dtype_perc(va_list list, t_dflags *flags);
int							ft_dtype_s(va_list list, t_dflags *flags);
int							ft_dtype_f(va_list list, t_dflags *flags);
int							ft_dtype_dec(va_list list, t_dflags *flags);
int							ft_dtype_x(va_list list, t_dflags *flags);
int							ft_dtype_x_cap(va_list list, t_dflags *flags);
int							ft_dtype_u(va_list list, t_dflags *flags);
int							ft_dtype_o(va_list list, t_dflags *flags);
int							ft_dtype_dec_cap(va_list list, t_dflags *flags);
int							ft_dtype_o_cap(va_list list, t_dflags *flags);
int							ft_dtype_u_cap(va_list list, t_dflags *flags);
int							ft_dtype_p(va_list list, t_dflags *flags);
int							ft_dtype_null(va_list list, t_dflags *flags);
int							ft_dwrite_main(void *s, int size, t_dflags *flags);
int							ft_dwrite_bfp(char **str, t_dflags *flags);
int							ft_dputchar_f(char c, t_dflags *flags);

#endif
