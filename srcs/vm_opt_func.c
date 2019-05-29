/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_opt_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:22:10 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/29 20:05:47 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_utils.h"



int						vm_pp_dumps(char *val, t_oflags *flags)
{
	int					value;

	if (!flags->dump)
	{
		if ((value = vm_opt_getval(val)) == -1)
			return (0);
		flags->dump = '1';
		flags->n_dumps = dump;
	}
	return (1);
}

int						vm_pp_soption(char *val, t_oflags *flags)
{
	int					value;

	if (!flags->soption)
	{
		if ((value = vm_opt_getval(val)) == -1)
			return (0);
		flags->soption = '1';
		flags->n_soption = value;
	}
	return (1);
}

int						vm_pp_aff(char *val, t_oflags *flags)
{
	if (!flags->aff)
		flags->aff = '1';
	(void)val;
	return (1);
}

int						vm_pp_verb(char *val, t_oflags *flags)
{
	int					value;

	if (!flags->verb)
	{
		if ((value = vm_opt_getval(val)) == -1)
			return (0);
		flags->verb = '1';
		flags->n_verb = value;
	}
	return (1);
}
