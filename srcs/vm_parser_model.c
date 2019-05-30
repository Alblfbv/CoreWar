/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parser_model.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:34:26 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/30 13:34:27 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_ull               vm_get_value(char *sval)
{
    t_ull            value;

    if (!sval || !ft_isnumeric(sval))
        return (-1);
    value = ft_atoill(sval);
    if (ft_validInt(value) && value > 0)
        return (value);
    return (-1);
}