/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:17:13 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/07 20:13:35 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

int				on_key_pressed(t_gamestate *state, int key)
{
	if (state->state == STATE_MENU)
		return (menu_key(state, key));
	else if (state->state == STATE_QUIT_DIALOG)
		return (quit_dialog_key(state, key));
	else if (state->state == STATE_GAME)
		return (game_key(state, key));
	else if (state->state == STATE_LOST)
		return (gameover_key(state, key));
	else if (state->state == STATE_LOST2)
		return (gameover_key2(state, key));
	else if (state->state == STATE_SCORE_MENU)
		return (score_key(state, key));
	return (0);
}

static void		check_screen_size(void)
{
	while (LINES < 36 || COLS < 70)
	{
		erase();
		init_pair(COLOR_TITLE, COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(COLOR_TITLE));
		print_middle(stdscr, LINES / 2, "Screen is too small!");
		attroff(COLOR_PAIR(COLOR_TITLE));
		getch();
	}
}

void			on_redraw(t_gamestate *state)
{
	fill_window(stdscr, COLOR_BLACK);
	check_screen_size();
	box(stdscr, ACS_VLINE, ACS_HLINE);
	init_pair(COLOR_LOGO, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(COLOR_LOGO));
	print_middle(stdscr, 1, "   ___   ____  __ __  ____ ");
	print_middle(stdscr, 2, "  |__ \\ / __ \\/ // / ( __ )");
	print_middle(stdscr, 3, "  __/ // / / / // /_/ __  |");
	print_middle(stdscr, 4, " / __// /_/ /__  __/ /_/ / ");
	print_middle(stdscr, 5, "/____/\\____/  /_/  \\____/  ");
	attroff(COLOR_PAIR(COLOR_LOGO));
	refresh();
	if (state->state == STATE_MENU)
		menu_redraw(state);
	else if (state->state == STATE_QUIT_DIALOG)
		quit_dialog_redraw(state);
	else if (state->state == STATE_GAME)
		game_redraw(state);
	else if (state->state == STATE_LOST || state->state == STATE_LOST2)
		gameover_redraw(state);
	else if (state->state == STATE_SCORE_MENU)
		score_redraw(state);
	refresh();
}
