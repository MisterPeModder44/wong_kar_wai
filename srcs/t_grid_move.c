/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:32:21 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 10:32:22 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_2048.h"

#include <stdio.h>
static t_square_action      internal_move_down(t_grid *grid, unsigned int line,
                                unsigned int col)
{
    unsigned int        square_value;
    unsigned int        next_square_value;

    square_value = t_grid_cell_value(*grid, line, col);;
    if (t_grid_is_valid_coord(*grid, line, col) == false || line + 1 >= GRID_SIZE_MAX)
        return SQUARE_ERROR;
    next_square_value = t_grid_cell_value(*grid, line + 1, col);
    if (square_value == EMPTY_VALUE)
        return SQUARE_NOTHING;
        // square on the next line is same number
    if (next_square_value == square_value)
    {
        printf("can merge : %d et %d \n", square_value, next_square_value);
        t_grid_set_number(grid, line + 1, col,
                          t_grid_get_next_value(square_value));
        t_grid_set_number(grid, line, col, EMPTY_VALUE);
        return SQUARE_MERGE;
    }
        // square on the next line is empty
    if (next_square_value == EMPTY_VALUE)
    {
        t_grid_set_number(grid, line + 1, col, square_value);
        t_grid_set_number(grid, line, col, EMPTY_VALUE);
        return SQUARE_MOVE;
    }
    return SQUARE_NOTHING;
}

static t_square_action      internal_move_line_down(t_grid *grid, unsigned int col)
{
    unsigned int    line = 0;

    bool            has_merge;
    int             value_merge;

    has_merge = false;
    while (line < grid->grid_size)
    {
        if (internal_move_down(grid, line, col) == SQUARE_MERGE)
        {
            value_merge = t_grid_cell_value(*grid, line, col);

        }
        line++;
    }

}


int                         t_grid_move(t_move move, t_grid *grid)
{
    unsigned int        col = 0;
    unsigned int        inc_col = 1;

    if (move == MOVE_DOWN)
    {
        while (col < grid->grid_size)
        {
            internal_move_line_down(grid, col);
            col += inc_col;
        }
    }
    return (EXIT_SUCCESS);
}

