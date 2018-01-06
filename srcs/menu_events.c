/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:10:02 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 13:52:31 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

void			menu_key(t_gamestate *state, int key)
{
	if (key == KEY_UP)
		--state->menu_item;
	else if (key == KEY_DOWN)
		++state->menu_item;
	else if (key == 10 && state->menu_item == 0)
	{
		state->state = STATE_GAME;
	}
	state->menu_item = state->menu_item < 0 ? 2 : state->menu_item;
	state->menu_item = state->menu_item > 2 ? 0 : state->menu_item;
}

static void		printh_middle(WINDOW *win, int *i, char *str, t_gamestate *st)
{
	if (st->menu_item == i[1])
	{
		init_pair(COLOR_SELECT, COLOR_WHITE, COLOR_RED);
		attron(COLOR_PAIR(COLOR_SELECT));
	}
	print_middle(win, i[0], str);
	if (st->menu_item == i[1])
		attroff(COLOR_PAIR(COLOR_SELECT));
}

void			menu_redraw(t_gamestate *state)
{
	init_pair(COLOR_TITLE, COLOR_RED, COLOR_BLUE);
	attron(COLOR_PAIR(COLOR_TITLE));
	print_middle(stdscr, 0, "2048");
	attroff(COLOR_PAIR(COLOR_TITLE));
	printh_middle(stdscr, (int[]){LINES / 2 - 1, 0}, "PLAY", state);
	printh_middle(stdscr, (int[]){LINES / 2 + 1, 2}, "OPTIONS", state);
	printh_middle(stdscr, (int[]){LINES / 2, 1}, "SCORES", state);
}
