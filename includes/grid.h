/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:08:05 by mressier          #+#    #+#             */
/*   Updated: 2018/01/07 11:36:46 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include <ncurses.h>

# define GRID_SIZE_MAX	4

typedef struct		s_grid
{
	unsigned int	grid[GRID_SIZE_MAX][GRID_SIZE_MAX];
	unsigned int	grid_size;
	unsigned int	score;
}					t_grid;

typedef enum		e_move
{
	MOVE_UP = KEY_UP,
	MOVE_RIGHT = KEY_RIGHT,
	MOVE_DOWN = KEY_DOWN,
	MOVE_LEFT = KEY_LEFT
}					t_move;

typedef	void		(*t_grid_func)(t_grid *, unsigned int line,
		unsigned int col);
typedef	int			(*t_grid_func_iter)(t_grid *, unsigned int line,
		unsigned int col);
/*
** t_grid.c
*/
void				t_grid_display(t_grid grid);
int					t_grid_init(t_grid *new_grid, unsigned int size);
int					t_grid_set_number(t_grid *grid, unsigned int line,
		unsigned int col, unsigned int number);

void				t_grid_display_cell(t_grid *grid, unsigned int line,
		unsigned int col);

/*
** t_grid_map_iter.c
*/
int					t_grid_iter(t_grid *grid, t_grid_func_iter func);
void				t_grid_map(t_grid *grid, t_grid_func func);

/*
** t_grid_tools.c
*/
bool				t_grid_is_valid_coord(t_grid grid, unsigned int line,
		unsigned int col);
unsigned int		t_grid_cell_value(t_grid grid, unsigned int line,
		unsigned int col);
unsigned int		t_grid_get_next_value(unsigned int current_value);

/*
** t_grid_win_or_loose.c
*/
bool				t_grid_win(t_grid *grid);
bool				t_grid_loose(t_grid *grid);
int					is_empty_value(t_grid *grid, unsigned int line,
		unsigned int col);

/*
** t_grid_spread_random_number.c
*/
void				t_grid_spread_random_number(t_grid *grid,
		unsigned int nb_rand);

/*
** t_grid_move.c
*/
int					t_grid_merge_square(unsigned int *square_value,
		unsigned int *next_square_value);
int					t_grid_move_square(unsigned int *square_value,
		unsigned int *next_square_value);
int					t_grid_move(t_move move, t_grid *grid);

/*
** t_grid_calcul_column.c
*/
int					t_grid_calcul_column_up(t_grid *grid, unsigned int line);
int					t_grid_calcul_column_down(t_grid *grid, unsigned int line);

/*
** t_grid_calcul_line.c
*/
int					t_grid_calcul_line_left(t_grid *grid, unsigned int col);
int					t_grid_calcul_line_right(t_grid *grid, unsigned int col);

#endif
