/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:10:02 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/07 17:28:03 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

int				menu_key(t_gamestate *state, int key)
{
	if (key == ESC_KEY || key == Q_KEY)
	{
		state->menu_item = 0;
		state->state = STATE_QUIT_DIALOG;
	}
	else if (key == KEY_UP)
		--state->menu_item;
	else if (key == KEY_DOWN)
		++state->menu_item;
	else if (key == ENTER_KEY)
	{
		if (state->menu_item == 0)
			state->state = STATE_GAME;
		if (state->menu_item == 1)
			state->state = STATE_SCORE_MENU;
		else if (state->menu_item == 2)
		{
			state->menu_item = 0;
			state->state = STATE_QUIT_DIALOG;
		}
	}
	state->menu_item = state->menu_item < 0 ? 2 : state->menu_item;
	state->menu_item = state->menu_item > 2 ? 0 : state->menu_item;
	return (0);
}

static void		printh_middle(int *i, char *str, t_gamestate *st)
{
	if (st->menu_item == i[1])
	{
		mvprintw(i[0], COLS / 2 - 5, "[");
		init_pair(COLOR_SELECT, COLOR_WHITE, COLOR_BLUE);
		attron(COLOR_PAIR(COLOR_SELECT));
	}
	else
		mvprintw(i[0], COLS / 2 - 5, "-");
	print_middle(stdscr, i[0], str);
	if (st->menu_item == i[1])
	{
		attroff(COLOR_PAIR(COLOR_SELECT));
		mvprintw(i[0], COLS / 2 + 5, "]");
	}
	else
		mvprintw(i[0], COLS / 2 + 5, "-");
}

void			menu_redraw(t_gamestate *state)
{
	printh_middle((int[]){LINES / 2 - 1, 0}, "PLAY", state);
	printh_middle((int[]){LINES / 2, 1}, "SCORES", state);
	printh_middle((int[]){LINES / 2 + 2, 2}, "QUIT", state);
	mvprintw(LINES - 2, 2,
			"Use arrows to move around, press 'ESC' or 'Q' to quit.");
}
