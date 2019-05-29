/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_pparser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:57:19 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/29 20:05:40 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_utils.h"

t_option				g_options[4] = {
	{"-d", vm_pp_dumps}, {"s", vm_pp_sption}, {"a", vm_pp_aff}
	, {"v", vm_pp_verb}};

static int				vm_opt_launcher(int index, int count
		, char **av, t_oflags *flags)
{
	int					ret;

	ret = 0;
	if (index != 2)
	{
		if (!ft_isnumeric(av[count + 1]))
			return (0);
		ret = g_options[index].f(av[count + 1], flags);
	}
	else
		ret = g_options[index].f(av[count], flags);
	return (ret);
}

int						vm_preader(int ac, char **av, t_oflags *flags)
{
	int					index;
	int					ret;
	int					counter;

	index = 0;
	count = 1;
	while (index < 4 && count < ac - 1)
	{
		if (av[count] == g_options[index].f_option)
		{
			if (!(ret = vm_opt_launcher(index, count, av, flags)))
				return (0);
			count++;
		}
		index++;
	}
	return (count);
}
