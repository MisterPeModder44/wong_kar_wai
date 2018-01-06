/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_win_or_loose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:11:40 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 14:11:41 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Used on t_grid_iter
** t_grid_iter return the first value which is not 0
** If we found the win value, we return 1 to break the loop
*/
static int		is_win_value(t_grid *grid, unsigned int line, unsigned int col)
{
	if (t_grid_cell_value(*grid, line, col) == WIN_VALUE)
		return (1);
	return (0);
}

/*
** Use on t_grid_iter
** t_grid_iter return the first value which is not 0
** If we found an empty value, we return 1 to break the loop
*/
static int		is_empty_value(t_grid *grid, unsigned int line, unsigned int col)
{
	if (t_grid_cell_value(*grid, line, col) == EMPTY_VALUE)
		return (1);
	return (0);
}

/*
** Return true if the WIN_VALUE have been found on the grid
*/
bool			t_grid_win(t_grid *grid)
{
	return (t_grid_iter(grid, is_win_value) != 0);
}

/*
** Return true if there is no more empty square on the grid
**
** t_grid_iter return 1 if an empty square is found
** so if it return 1, there is empty square yet, so we doesn't loose
*/
bool			t_grid_loose(t_grid *grid)
{
	return (t_grid_iter(grid, is_empty_value) != 0);
}

