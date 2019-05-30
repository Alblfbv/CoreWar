/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validInt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:16:42 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/30 14:16:51 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int             ft_validInt(unsigned long long number)
{
    return ((number > (unsigned long long)INT_MIN && number < (unsigned long long)INT_MAX) ? 1 : 0);
}