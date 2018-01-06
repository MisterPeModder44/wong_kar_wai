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

#define GRID_SIZE_MAX   4

enum e_const
{
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
	int				grid[GRID_SIZE_MAX][GRID_SIZE_MAX];
	unsigned int	grid_size;
}					t_grid;

typedef struct		s_gamestate
{
	int				state;
	int				menu_item;
	t_grid			*grid;
}					t_gamestate;

/*
 * t_grid.c
 */
void                t_grid_display(t_grid grid);
int                 t_grid_init(t_grid *new_grid, unsigned int size);
int                 t_grid_set_number(t_grid *grid, unsigned int line,
		unsigned int col, unsigned int number);

#endif
