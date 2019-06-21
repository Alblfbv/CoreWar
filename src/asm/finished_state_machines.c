/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finished_state_machines.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:44:06 by sunakim           #+#    #+#             */
/*   Updated: 2019/06/21 16:17:25 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	g_lsm_col[13][26] =
{
	{"_"},
	{"stuvwxyzabcdefghijklmnopq"},
	{"r"},
	{"0123456789"},
	{"-"},
	{DIRECT_CHAR},
	{LABEL_CHAR},
	{SPACE_CHAR},
	{"#;"},
	{SEPARATOR_CHAR},
	{"\n"},
	{"."},
	{"\""},
};

int	g_lex_sm[29][14] =
{
	{6, 4, 2, 5, 16, 10, 18, 0, 1, 26, 27, 21, -1, -1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 27, 1, 1, 1},
	{6, 4, 4, 3, -1, -1, 7, 9, -1, -1, -1, -1, -1, -1},
	{6, 6, 6, 3, -1, -1, 7, 8, 8, 8, 8, -1, -1, -1},
	{6, 4, 4, 6, -1, -1, 7, 9, 9, 9, 9, -1, -1, -1},
	{6, 6, 6, 5, -1, -1, 7, 17, 17, 17, 17, -1, -1, -1},

	{6, 6, 6, 6, -1, -1, 7, -1, -1, -1, -1, -1, -1, -1},
	{-2, 0},

	{-3, 1},

	{-3, 2},

	{-1, -1, -1, 11, 11, -1, 13, -1, -1, -1, -1, -1, -1, -1},

	{-1, -1, -1, 11, -1, -1, -1, 12, 12, 12, 12, -1, -1, -1},
	{-3, 3},

	{14, 14, 14, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{14, 14, 14, 14, -1, -1, -1, 15, 15, 15, 15, -1, -1, -1},
	{-3, 4},

	{-1, -1, -1, 16, -1, -1, -1, 17, 17, 17, 17, -1, -1, -1},
	{-3, 5},

	{19, 19, 19, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{19, 19, 19, 19, -1, -1, -1, 20, 20, 20, 20, -1, -1, -1},
	{-3, 6},

	{-1, 22, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, 22, 22, -1, -1, -1, -1, 23, -1, -1, -1, -1, 24, -1},
	{-1, -1, -1, -1, -1, -1, -1, 23, -1, -1, -1, -1, 24, -1},
	{24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 24},
	{-2, 7},

	{-2, 8},

	{-2, 9},
};

int	g_syntactic_sm[56][14] =
{
	{10, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1},
	{-1, 12, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1},
	{-1, -1, 14, 6, -1, -1, -1, -1, -1, -1, 2, -1},
	{-1, -1, 14, 8, -1, -1, -1, -1, -1, -1, 3, 5},

	{-3},

	{-2, 3},

	{-1, -1, 14, -1, -1, -1, -1, -1, -1, -1, 7, -1},
	{-2, 2},
	{-1, -1, 14, -1, -1, -1, -1, -1, -1, -1, 9, -1},
	{-2, 3},

	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 11, -1},
	{-2, 1},

	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 13, -1},
	{-2, 2},

	{-3},

	{-1, -1, -1, -1, -1, -1, -1, 16, 16, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 17, -1},
	{-2, 3},

	{-1, -1, -1, -1, -1, 19, 19, 19, 19, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 20, -1, -1},
	{-1, -1, -1, -1, 21, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, -1},
	{-2, 3},

	{-1, -1, -1, -1, 24, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 25, -1, -1},
	{-1, -1, -1, -1, 26, 26, 26, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, -1},
	{-2, 3},

	{-1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 30, -1, -1},
	{-1, -1, -1, -1, 31, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 32, -1, -1},
	{-1, -1, -1, -1, 33, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 34, -1},
	{-2, 3},

	{-1, -1, -1, -1, 36, 36, 36, 36, 36, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 37, -1, -1},
	{-1, -1, -1, -1, 38, 38, 38, 38, 38, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 39, -1, -1},
	{-1, -1, -1, -1, 40, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 41, -1},
	{-2, 3},

	{-1, -1, -1, -1, 43, 43, 43, 43, 43, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 44, -1, -1},
	{-1, -1, -1, -1, 45, -1, -1, 45, 45, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 46, -1, -1},
	{-1, -1, -1, -1, 47, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 48, -1},
	{-2, 3},

	{-1, -1, -1, -1, 50, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 51, -1, -1},
	{-1, -1, -1, -1, 52, 52, 52, 52, 52, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 53, -1, -1},
	{-1, -1, -1, -1, 54, -1, -1, 54, 54, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 55, -1},
	{-2, 3},
};
