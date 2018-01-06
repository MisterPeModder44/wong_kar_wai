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

int				t_grid_calcul_column_up(t_grid *grid, unsigned int line)
{
	int					col;
	int					turn;
	int					move;

	turn = TURN_MOVE;
	move = false;
	while (turn < TURN_MAX)
	{
		col = 0;
		while (col < (int)grid->grid_size - 1)
		{
			if (turn == TURN_MOVE || turn == TURN_RE_MOVE)
				move = t_grid_move_square(&(grid->grid[line][col + 1]),
					&(grid->grid[line][col]));
			if (turn == TURN_MERGE)
			{
				if (t_grid_merge_square(&(grid->grid[line][col + 1]),
						&(grid->grid[line][col])))
					col++;
			}
			col++;
		}
		if (move)
			move = false;
		else
			turn++;
	}
	return (0);
}

int				t_grid_calcul_column_down(t_grid *grid, unsigned int line)
{
	int		col;
	int		turn;
	int		move;

	turn = TURN_MOVE;
	move = false;
	while (turn < TURN_MAX)
	{
		col = grid->grid_size - 1;
		while (col > 0)
		{
			if (turn == TURN_MOVE || turn == TURN_RE_MOVE)
				move = t_grid_move_square(&(grid->grid[line][col - 1]),
					&(grid->grid[line][col]));
			if (turn == TURN_MERGE)
			{
				if (t_grid_merge_square(&(grid->grid[line][col - 1]),
						&(grid->grid[line][col])))
					col--;
			}
			col--;
		}
		if (move)
			move = false;
		else
			turn++;
	}
	return (0);
}

