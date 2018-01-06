/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_calcul_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:19:28 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 18:19:29 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

#define INC_UP		1
#define INC_DOWN	-1

#define IS_INC_UP(inc) 		((inc) > 0)
#define IS_INC_DOWN(inc)	((inc) < 0)

static int		internal_move_squares_on_line(t_grid *grid, int col,
					int limit, int inc)
{
	int		move;
	int		count;
	int		line;
	int		start;

	move = 1;
	count = -1;
	start = (IS_INC_UP(inc) ? 0 : grid->grid_size - 1);
	while (move > 0)
	{
		move = 0;
		count++;
		line = start;
		while ((IS_INC_UP(inc) && line < limit)
				|| (IS_INC_DOWN(inc) && line > limit))
		{
			if (t_grid_move_square(&(grid->grid[line + inc][col]),
						&(grid->grid[line][col])))
				move++;
			line += inc;
		}
	}
	return (count > 0);
}

static int		internal_merge_squares_on_line(t_grid *grid, int col,
					int limit, int inc)
{
	int			move_value;
	int			line;
	int			start;

	start = (IS_INC_UP(inc) ? 0 : grid->grid_size - 1);
	move_value = 0;
	line = start;
	while ((IS_INC_UP(inc) && line < limit)
			|| (IS_INC_DOWN(inc) && line > limit))
	{
		if (t_grid_merge_square(&(grid->grid[line + inc][col]),
								&(grid->grid[line][col])))
		{
			move_value += t_grid_cell_value(*grid, line, col);
			line += inc;
		}
		line += inc;
	}
	return (move_value);
}

static int		internal_calcul_line(t_grid *grid, unsigned int col, int inc)
{
	int		limit;
	int		move;
	int		move_value;

	limit = (IS_INC_UP(inc) ? grid->grid_size - 1 : 0);
	move = internal_move_squares_on_line(grid, col, limit, inc);
	move_value = internal_merge_squares_on_line(grid, col, limit, inc);
	move += internal_move_squares_on_line(grid, col, limit, inc);
	move += move_value;
	grid->score += move_value;
	return (move);
}

int				t_grid_calcul_line_left(t_grid *grid, unsigned int col)
{
	return (internal_calcul_line(grid, col, INC_UP));
}

int				t_grid_calcul_line_right(t_grid *grid, unsigned int col)
{
	return (internal_calcul_line(grid, col, INC_DOWN));
}
