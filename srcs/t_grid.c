/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:04:49 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 10:04:51 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include "libft.h"

int      t_grid_init(t_grid *new_grid, unsigned int size)
{
    ft_bzero((void *)new_grid, sizeof(t_grid));
    if (size > GRID_SIZE_MAX)
        return (EXIT_FAILURE);
    new_grid->grid_size = size;
    return (EXIT_SUCCESS);
}

void        t_grid_display(t_grid grid)
{
    unsigned int    i;
    unsigned int    j;

    i = 0;
    while (i < grid.grid_size)
    {
        j = 0;
        while (j < grid.grid_size)
        {
            ft_putchar('[');
            ft_putnbr(grid.grid[i][j]);
            ft_putchar(']');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int        t_grid_set_number(t_grid *grid, unsigned int line, unsigned int col, unsigned int number)
{
    if (line >= grid->grid_size || col >= grid->grid_size)
        return (EXIT_FAILURE);
    grid->grid[line][col] = number;
    return (EXIT_SUCCESS);
}

