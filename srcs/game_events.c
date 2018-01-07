/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:44:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/07 12:14:21 by yguaye           ###   ########.fr       */
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

static void		game_redraw2(t_gamestate *state)
{
	char		*goal;

	mvprintw(LINES - 2, 2, "score: %d", state->grid->score);
	goal = ft_itoa(WIN_VALUE);
	goal = ft_strjoinf2("goal: ", &goal);
	mvprintw(LINES - 2, COLS - ft_strlen(goal) - 1, goal);
	ft_strdel(&goal);
	init_pair(COLOR_GREENTEXT, COLOR_GREEN, COLOR_BLACK);
	if (t_grid_win(state->grid))
	{
		attron(COLOR_PAIR(COLOR_GREENTEXT));
		print_middle(stdscr, LINES - 2, "YOU WIN");
		attroff(COLOR_PAIR(COLOR_GREENTEXT));
	}
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
			t = state->grid->grid[x][y] ? ft_itoa(state->grid->grid[x][y]) :
				ft_strdup(" ");
			put_square(stdscr, (int[]){sx, sy, 12}, state->grid->grid[x][y], t);
			ft_strdel(&t);
			sx += 13;
		}
		sy += 6;
	}
	game_redraw2(state);
}
