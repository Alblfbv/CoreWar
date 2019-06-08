/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:03:48 by sunakim           #+#    #+#             */
/*   Updated: 2019/06/08 15:52:07 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error(t_pos *pos, int i, t_tkn *tkn)
{
	if (i == 1 && tkn)
		ft_printf("Lexical error at [%d : %d]\n", pos->line, tkn->buff_start);
	else if (i == 2 && tkn)
		ft_printf("Syntactic error at [%d : %d]\n", pos->line, tkn->buff_start);
	else
		ft_printf("Error\n");
	//free
}
