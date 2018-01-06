/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:04:49 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 10:54:58 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include "libft.h"

int			t_grid_init(t_grid *new_grid, unsigned int size)
{
	ft_bzero((void *)new_grid, sizeof(t_grid));
	if (size > GRID_SIZE_MAX)
		return (EXIT_FAILURE);
	new_grid->grid_size = size;
	return (EXIT_SUCCESS);
}

void		t_grid_display(t_grid grid)
{
	t_grid_map(&grid, t_grid_display_cell);
}

void		t_grid_display_cell(t_grid *grid, unsigned int line,
				unsigned int col)
{
	if (t_grid_is_valid_coord(*grid, line, col) == false)
		return ;
	ft_putchar('[');
	ft_putnbr(grid->grid[line][col]);
	ft_putchar(']');
	if (col == grid->grid_size - 1)
		ft_putchar('\n');
}

int			t_grid_set_number(t_grid *grid, unsigned int line,
						unsigned int col, unsigned int number)
{
	if (t_grid_is_valid_coord(*grid, line, col) == false)
		return (EXIT_FAILURE);
	grid->grid[line][col] = number;
	return (EXIT_SUCCESS);
}
