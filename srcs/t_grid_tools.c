/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:44:02 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 13:44:08 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

bool			t_grid_is_valid_coord(t_grid grid, unsigned int line,
										unsigned int col)
{
	if (line >= grid.grid_size || col >= grid.grid_size)
		return (false);
	return (true);
}

unsigned int	t_grid_cell_value(t_grid grid, unsigned int line,
									unsigned int col)
{
	return (grid.grid[line][col]);
}

unsigned int	t_grid_get_next_value(unsigned int current_value)
{
	return (current_value * 2);
}
