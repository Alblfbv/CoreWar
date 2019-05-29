/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:09:47 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/29 20:05:55 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_UTILS_H
# define VM_UTILS_H

# include<limits.h>

typedef struct				s_option
{
	char					f_option[5];
	int						(*f)();
}							t_option;

typedef struct				s_oflags
{
	char					dump;
	int						n_dumps;
	char					soption;
	int						n_soption;
	char					aff;
	char					verb;
	int						n_verb;
	char					bin;
	char					ncurse;
}							t_oflags;

unsigned int				vm_endian_conversion(unsigned int val);

int							vm_pp_soption(char *val, t_oflags *flags);
int							vm_pp_aff(char *val, t_oflags *flags);
int							vm_pp_dumps(char *val, t_oflags *flags);
int							vm_pp_verb(char *val, t_oflags *flags);
int							vm_opt_getval(char *sval);


#endif
