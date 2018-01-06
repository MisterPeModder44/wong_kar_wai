/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:52:38 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 13:58:14 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <stdbool.h>

# define GRID_SIZE_MAX   4

enum e_const
{
	EMPTY_VALUE = 0,
	STATE_MENU,
	STATE_GAME,
	WIN_VALUE = 2048,
};

enum e_color_set
{
	COLOR_TITLE = 1,
	COLOR_BG,
	COLOR_SELECT,
	COLOR_SQUARE,
};

typedef struct		s_grid
{
	unsigned int	grid[GRID_SIZE_MAX][GRID_SIZE_MAX];
	unsigned int	grid_size;
}					t_grid;

typedef struct		s_gamestate
{
	int				state;
	int				menu_item;
	t_grid			*grid;
}					t_gamestate;

typedef enum		e_move
{
	MOVE_UP = 0,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT
}					t_move;

typedef enum		e_merge_turns
{
	TURN_MOVE = 0,
	TURN_MERGE,
	TURN_RE_MOVE,
	TURN_MAX
}					t_merge_turns;

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
** t_grid_move.c
*/
int					t_grid_move(t_move move, t_grid *grid);

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

/*
** t_grid_spread_random_number.c
*/
void				t_grid_spread_random_number(t_grid *grid, unsigned int nb_rand);

#endif
