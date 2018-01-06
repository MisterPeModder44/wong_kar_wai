/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:43:57 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 13:43:58 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_2048.h"

int				t_grid_merge_square(unsigned int *square_value,
									unsigned int *next_square_value)
{
	if (*square_value == EMPTY_VALUE)
		return (false);
	if (*square_value == *next_square_value)
	{
		*next_square_value = t_grid_get_next_value(*square_value);
		*square_value = EMPTY_VALUE;
		return (true);
	}
	return (false);
}

int				t_grid_move_square(unsigned int *square_value,
									unsigned int *next_square_value)
{
	if (*square_value == EMPTY_VALUE)
		return (false);
	if (*next_square_value == EMPTY_VALUE)
	{
		*next_square_value = *square_value;
		*square_value = EMPTY_VALUE;
		return (true);
	}
	return (false);
}

int						t_grid_move(t_move move, t_grid *grid)
{
	unsigned int		i;
	unsigned int		move_value;

	i = 0;
	move_value = 0;
	while (i < grid->grid_size)
	{
		if (move == MOVE_DOWN)
			t_grid_calcul_column_down(grid, i);
		else if (move == MOVE_UP)
			t_grid_calcul_column_up(grid, i);
		else if (move == MOVE_LEFT)
			t_grid_calcul_line_left(grid, i);
		else if (move == MOVE_RIGHT)
			t_grid_calcul_line_right(grid, i);
		i++;
	}
	return (EXIT_SUCCESS);
}
