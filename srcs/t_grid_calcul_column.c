/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_calcul_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:19:19 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 18:19:20 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_2048.h"

#define INC_UP		1
#define INC_DOWN	-1

#define IS_INC_UP(inc) 		((inc) > 0)
#define IS_INC_DOWN(inc)	((inc) < 0)

static int		internal_move_squares_on_column(t_grid *grid, int line,
					int limit, int inc)
{
	int		move;
	int		count;
	int		col;
	int		start;

	move = 1;
	count = -1;
	start = (IS_INC_UP(inc) ? 0 : grid->grid_size - 1);
	while (move > 0)
	{
		move = 0;
		count++;
		col = start;
		while ((IS_INC_UP(inc) && col < limit)
				|| (IS_INC_DOWN(inc) && col > limit))
		{
			if (t_grid_move_square(&(grid->grid[line][col + inc]),
						&(grid->grid[line][col])))
				move++;
			col += inc;
		}
	}
	return (count > 0);
}

static int		internal_merge_squares_on_column(t_grid *grid, int line,
					int limit, int inc)
{
	int			move_value;
	int			col;
	int			start;

	start = (IS_INC_UP(inc) ? 0 : grid->grid_size - 1);
	move_value = 0;
	col = start;
	while ((IS_INC_UP(inc) && col < limit)
			|| (IS_INC_DOWN(inc) && col > limit))
	{
		if (t_grid_merge_square(&(grid->grid[line][col + inc]),
								&(grid->grid[line][col])))
		{
			move_value += t_grid_cell_value(*grid, line, col);
			col += inc;
		}
		col += inc;
	}
	return (move_value);
}

static int		internal_calcul_column(t_grid *grid, unsigned int line, int inc)
{
	int		limit;
	int		move;
	int		move_value;

	limit = (IS_INC_UP(inc) ? grid->grid_size - 1 : 0);
	move = internal_move_squares_on_column(grid, line, limit, inc);
	move_value = internal_merge_squares_on_column(grid, line, limit, inc);
	move += internal_move_squares_on_column(grid, line, limit, inc);
	move += move_value;
	grid->score += move_value;
	return (move);
}

int				t_grid_calcul_column_up(t_grid *grid, unsigned int line)
{
	return (internal_calcul_column(grid, line, INC_UP));
}

int				t_grid_calcul_column_down(t_grid *grid, unsigned int line)
{
	return (internal_calcul_column(grid, line, INC_DOWN));
}
