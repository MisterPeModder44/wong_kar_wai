/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:44:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 19:04:32 by yguaye           ###   ########.fr       */
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
		if (t_grid_move(key, state->grid))
			t_grid_spread_random_number(state->grid, 1);
	}
	if (key == ESC_KEY || key == Q_KEY)
	{
		state->state = STATE_MENU;
		t_grid_init(state->grid, state->grid->grid_size);
		t_grid_spread_random_number(state->grid, GRID_SIZE_MAX / 2);
	}
	else if (key == KEY_F(12) || t_grid_loose(state->grid))
		state->state = STATE_LOST;
	return (0);
}

static void		internal_centered_coords(t_gamestate *st, int *sx, int *sy)
{
	if (sx)
		*sx = COLS / 2 - (st->grid->grid_size * 12 +
				st->grid->grid_size - 1) / 2;
	if (sy)
		*sy = LINES / 2 - (st->grid->grid_size * 5 +
				st->grid->grid_size - 1) / 2;
}

void			game_redraw(t_gamestate *state)
{
	int				sx;
	int				sy;
	unsigned int	x;
	unsigned int	y;
	char			*t;

	internal_centered_coords(state, &sx, &sy);
	y = -1;
	t = NULL;
	while (++y < state->grid->grid_size)
	{
		x = -1;
		internal_centered_coords(state, &sx, NULL);
		while (++x < state->grid->grid_size)
		{
			if (t)
				ft_strdel(&t);
			t = state->grid->grid[x][y] ? ft_itoa(state->grid->grid[x][y]) :
				ft_strdup(" ");
			put_square(stdscr, (int[]){sx, sy, 12}, state->grid->grid[x][y], t);
			sx += 13;
		}
		sy += 6;
	}
}
