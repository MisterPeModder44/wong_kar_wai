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
#include <stdio.h>

static bool				internal_merge_square(unsigned int *square_value,
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

static bool				internal_move_square(unsigned int *square_value,
									unsigned int *next_square_value)
{
	fprintf(stderr, "value : %u, next : %u\n", *square_value, *next_square_value);
	if (*next_square_value == EMPTY_VALUE)
	{
		*next_square_value = *square_value;
		*square_value = EMPTY_VALUE;
		return (true);
	}
	return (false);
}

static void				internal_calcul_new_line(t_grid *grid,
										unsigned int col, int inc)
{
	int	line;
	int	limit;
	int	turn;

	turn = TURN_MOVE;
	while (turn < TURN_MAX)
	{
		line = inc < 0 ? grid->grid_size - 1 : 0;
		limit = inc < 0 ? 0 : grid->grid_size - 1;
		while ((inc < 0 && line > limit)
				|| (inc > 0 && line < limit))
		{
			if (turn == TURN_MOVE || turn == TURN_RE_MOVE)
				internal_move_square(&(grid->grid[line][col]),
					&(grid->grid[line + inc][col]));
			if (turn == TURN_MERGE)
			{
				if (internal_merge_square(&(grid->grid[line][col]),
						&(grid->grid[line + inc][col])))
					line += inc;
			}
			line += inc;
		}
		turn++;
	}
}

static void				internal_calcul_new_column(t_grid *grid,
											unsigned int line, int inc)
{
	int	col;
	int	limit;
	int	turn;

	turn = TURN_MOVE;
	while (turn < TURN_MAX)
	{
		col = inc < 0 ? grid->grid_size - 1 : 0;
		limit = inc < 0 ? 0 : grid->grid_size - 1;
		while ((inc < 0 && col > limit)
				|| (inc > 0 && col < limit))
		{
			if (turn == TURN_MOVE || turn == TURN_RE_MOVE)
				internal_move_square(&(grid->grid[line][col]),
					&(grid->grid[line][col + inc]));
			if (turn == TURN_MERGE)
			{
				if (internal_merge_square(&(grid->grid[line][col]),
						&(grid->grid[line][col + inc])))
					col += inc;
			}
			col += inc;
		}
		turn++;
	}
}

int						t_grid_move(t_move move, t_grid *grid)
{
	unsigned int		col;
	unsigned int		line;
	int					inc;

	col = 0;
	line = 0;
	if (move == MOVE_LEFT || move == MOVE_RIGHT)
	{
		inc = (move == MOVE_RIGHT ? 1 : -1);
		while (col < grid->grid_size)
		{
			internal_calcul_new_line(grid, col, inc);
			col++;
		}
	}
	if (move == MOVE_DOWN || move == MOVE_UP)
	{
		inc = (move == MOVE_DOWN ? 1 : -1);
		while (line < grid->grid_size)
		{
			internal_calcul_new_column(grid, line, inc);
			line++;
		}
	}
	return (EXIT_SUCCESS);
}
