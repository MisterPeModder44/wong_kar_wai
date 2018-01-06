/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:17:13 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 17:56:52 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

/*
 ** Used in main loop
 ** This event is fired when the player presses a key.
 **
 ** Returns 0 or 1 depening on whether it should close the progam or not.
 */

int			on_key_pressed(t_gamestate *state, int key)
{
	if (state->state == STATE_MENU)
		return (menu_key(state, key));
	else if (state->state == STATE_GAME)
		return (game_key(state, key));
	else if (state->state == STATE_LOST)
		return (gameover_key(state, key));
	return (0);
}

/*
 ** Used in main loop
 ** This event is fired when the screen updates.
 */

void			on_redraw(t_gamestate *state)
{
	fill_window(stdscr, COLOR_BLACK);
	refresh();
	if (state->state == STATE_MENU)
		menu_redraw(state);
	else if (state->state == STATE_GAME)
		game_redraw(state);
	else if (state->state == STATE_LOST)
		gameover_redraw();
	refresh();
}
