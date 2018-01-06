/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:10:02 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 18:55:28 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

int				menu_key(t_gamestate *state, int key)
{
	if (key == ESC_KEY || key == Q_KEY)
		return (1);
	else if (key == KEY_UP)
		--state->menu_item;
	else if (key == KEY_DOWN)
		++state->menu_item;
	else if (key == ENTER_KEY && state->menu_item == 0)
	{
		state->state = STATE_GAME;
	}
	state->menu_item = state->menu_item < 0 ? 2 : state->menu_item;
	state->menu_item = state->menu_item > 2 ? 0 : state->menu_item;
	return (0);
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
	printh_middle(stdscr, (int[]){LINES / 2 - 1, 0}, "PLAY", state);
	printh_middle(stdscr, (int[]){LINES / 2 + 1, 2}, "OPTIONS", state);
	printh_middle(stdscr, (int[]){LINES / 2, 1}, "SCORES", state);
}
