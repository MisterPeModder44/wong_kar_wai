/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:44:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 18:53:50 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <libft_base/stringft.h>
#include "events.h"
#include "draw.h"

int				gameover_key(t_gamestate *state, int key)
{
	if (key == ESC_KEY)
		return (1);
	else if (key == ENTER_KEY || key == Q_KEY)
	{
		state->state = key == Q_KEY ? STATE_MENU : STATE_GAME;
		t_grid_init(state->grid, state->grid->grid_size);
		t_grid_spread_random_number(state->grid, GRID_SIZE_MAX / 2);
	}
	return (0);
}

void			gameover_redraw(void)
{
	WINDOW		*hints;

	init_pair(COLOR_TITLE, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(COLOR_TITLE));
	print_middle(stdscr, LINES / 2, "GAME OVER");
	attroff(COLOR_PAIR(COLOR_TITLE));
	hints = subwin(stdscr, 5, 32, LINES - 7, COLS / 2 - 16);
	attron(COLOR_PAIR(0));
	print_middle(hints, 1, "press 'ENTER' to retry");
	print_middle(hints, 2, "press 'Q' to go to main menu");
	print_middle(hints, 3, "press 'ESC' to quit");
	attroff(COLOR_PAIR(0));
	box(hints, ACS_VLINE, ACS_HLINE);
	delwin(hints);
}
