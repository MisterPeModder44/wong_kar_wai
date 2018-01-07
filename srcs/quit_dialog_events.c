/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_dialog_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:32:30 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/07 15:52:02 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

int				quit_dialog_key(t_gamestate *state, int key)
{
	if (key == ESC_KEY || key == Q_KEY)
		state->state = STATE_MENU;
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		state->menu_item = state->menu_item ? 0 : 1;
	else if (key == ENTER_KEY)
	{
		if (state->menu_item == 1)
			state->state = STATE_MENU;
		else
			return (1);
	}
	return (0);
}

void			quit_dialog_redraw(t_gamestate *state)
{
	void		*dialog;

	dialog = subwin(stdscr, 5, 24, LINES / 2 - 3, COLS / 2 - 11);
	mvwprintw((WINDOW *)dialog, 1, 2, "Do you want to quit?");
	mvwprintw((WINDOW *)dialog, 3, 4, "YES");
	mvwprintw((WINDOW *)dialog, 3, 17, "NO");
	mvwaddch((WINDOW *)dialog, 3, state->menu_item ? 16 : 3, '[');
	mvwaddch((WINDOW *)dialog, 3, state->menu_item ? 20 : 7, ']');
	box(dialog, ACS_VLINE, ACS_HLINE);
	delwin(dialog);
	mvprintw(LINES - 2, 2,
			"Use arrows to move around, press 'ESC' or 'Q' to close.");
}
