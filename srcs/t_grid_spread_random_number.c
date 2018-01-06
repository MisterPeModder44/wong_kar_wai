/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_spread_random_number.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:32:18 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 14:32:19 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <stdlib.h>

#define NUMBERS_MAX		4

static unsigned int		internal_get_random_start_value()
{
	unsigned int		numbers[NUMBERS_MAX];
	int					i;

	i = 0;
	numbers[i++] = 2;
	numbers[i++] = 2;
	numbers[i++] = 2;
	numbers[i++] = 4;
	return (numbers[rand() % NUMBERS_MAX]);
}

static void				internal_set_number_on_random_pos(t_grid *grid,
							unsigned int number)
{
	int		pos_max;
	int		line;
	int		col;

	pos_max = grid->grid_size;
	if (t_grid_iter(grid, is_empty_value) == 0)
		return ;
	while (true)
	{
		line = rand() % pos_max;
		col = rand() % pos_max;
		if (t_grid_cell_value(*grid, line, col) == EMPTY_VALUE)
		{
			t_grid_set_number(grid, line, col, number);
			break ;
		}
	}
}

void					t_grid_spread_random_number(t_grid *grid,
							unsigned int nb_rand)
{
	unsigned int		number;
	unsigned int		i;

	i = 0;
	while (i < nb_rand)
	{
		number = internal_get_random_start_value();
		internal_set_number_on_random_pos(grid, number);
		i++;
	}
}

