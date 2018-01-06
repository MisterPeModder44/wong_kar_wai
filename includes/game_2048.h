/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:52:38 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 09:53:20 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <stdbool.h>

# define GRID_SIZE_MAX   4

enum e_const
{
    EMPTY_VALUE = 0,
    WIN_VALUE = 2048
};

typedef enum        e_move
{
    MOVE_UP = 0,
    MOVE_RIGHT,
    MOVE_DOWN,
    MOVE_LEFT
}                   t_move;

typedef enum        e_square_action
{
    SQUARE_MOVE = 0,
    SQUARE_MERGE,
    SQUARE_BLOCKED,
    SQUARE_NOTHING,
    SQUARE_ERROR
}                   t_square_action;

typedef struct      s_grid
{
	unsigned int    grid[GRID_SIZE_MAX][GRID_SIZE_MAX];
	unsigned int    grid_size;
}                   t_grid;

typedef void        (*t_grid_func)(t_grid *, unsigned int line,
                                   unsigned int col);

/*
 * t_grid.c
 */
void                t_grid_display(t_grid grid);
int                 t_grid_init(t_grid *new_grid, unsigned int size);
int                 t_grid_set_number(t_grid *grid, unsigned int line,
									  unsigned int col, unsigned int number);

void                t_grid_display_cell(t_grid *grid, unsigned int line,
                                        unsigned int col);

/*
 * t_grid_move.c
 */
int                 t_grid_move(t_move move, t_grid *grid);


/*
 * t_grid_tools.c
 */
bool                t_grid_is_valid_coord(t_grid grid, unsigned int line,
                                          unsigned int col);
unsigned int        t_grid_cell_value(t_grid grid, unsigned int line,
                                      unsigned int col);
unsigned int        t_grid_get_next_value(unsigned int current_value);

#endif
