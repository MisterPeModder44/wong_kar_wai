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
#include <stdio.h>

int				t_grid_calcul_line_left(t_grid *grid, unsigned int col)
{
	int					line;
	int					turn;
	int					move;

	turn = TURN_MOVE;
	move = false;
	while (turn < TURN_MAX)
	{
		line = 0;
		while (line < (int)grid->grid_size - 1)
		{
			if (turn == TURN_MOVE || turn == TURN_RE_MOVE)
				move = t_grid_move_square(&(grid->grid[line + 1][col]),
					&(grid->grid[line][col]));
			if (turn == TURN_MERGE)
			{
				if (t_grid_merge_square(&(grid->grid[line + 1][col]),
						&(grid->grid[line][col])))
					line++;
			}
			line++;
		}
		if (move)
			move = false;
		else
			turn++;
	}
	return (0);
}

int				t_grid_calcul_line_right(t_grid *grid, unsigned int col)
{
	int					line;
	int					turn;
	int					move;

	turn = TURN_MOVE;
	move = false;
	while (turn < TURN_MAX)
	{
		line = grid->grid_size - 1;
		while (line > 0)
		{
			if (turn == TURN_MOVE || turn == TURN_RE_MOVE)
				move = t_grid_move_square(&(grid->grid[line - 1][col]),
					&(grid->grid[line][col]));
			if (turn == TURN_MERGE)
			{
				if (t_grid_merge_square(&(grid->grid[line - 1][col]),
						&(grid->grid[line][col])))
					line--;
			}
			line--;
		}
		if (move)
			move = false;
		else
			turn++;
	}
	return (0);
}
