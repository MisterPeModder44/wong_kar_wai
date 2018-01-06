/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:44:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 16:48:48 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <libft_base/stringft.h>
#include "events.h"
#include "draw.h"

int				game_key(t_gamestate *state, int key)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT)
	{
		t_grid_move(key, state->grid);
		t_grid_spread_random_number(state->grid, 1);
	}
	if (key == ESC_KEY || key == Q_KEY || t_grid_loose(state->grid))
	{
		state->state = STATE_MENU;
		t_grid_init(state->grid, state->grid->grid_size);
		t_grid_spread_random_number(state->grid, GRID_SIZE_MAX / 2);
	}
	return (0);
}

void			game_redraw(t_gamestate *state)
{
	int				sx;
	int				sy;
	unsigned int	x;
	unsigned int	y;
	char			*text;

	fill_window(stdscr, COLOR_BLACK);
	sx = COLS / 2 - (state->grid->grid_size * 12 + state->grid->grid_size - 1) / 2;
	sy = LINES / 2 - (state->grid->grid_size * 5 + state->grid->grid_size - 1) / 2;
	y = -1;
	text = NULL;
	while (++y < state->grid->grid_size)
	{
		x = -1;
		sx = COLS / 2 - (state->grid->grid_size * 12 + state->grid->grid_size - 1) / 2;
		while (++x < state->grid->grid_size)
		{
			if (text)
				ft_strdel(&text);
			text = state->grid->grid[x][y] ? ft_itoa(state->grid->grid[x][y]) : ft_strdup(" ");
			put_square(stdscr, (int[]){sx, sy, 12}, state->grid->grid[x][y], text);
			sx += 13;
		}
		sy += 6;
	}
}
