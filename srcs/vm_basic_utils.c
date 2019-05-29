/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_basic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:32:37 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/29 20:05:50 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_utils.h"

int					vm_opt_getval(char *sval)
{
	int				ret;

	if (ft_strlen(sval) > 0 && ft_strlen(sval) <= 10)
	{
		ret = ft_atoi(sval);
		if (ret < 0)
			return (-1);
		return (ret);
	}
	return (-1);
}
