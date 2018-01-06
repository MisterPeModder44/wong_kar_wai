/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:17:13 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 16:29:54 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

/*
 ** Used in main loop
 ** This event is fired when the player presses a key.
 */

void			on_key_pressed(t_gamestate *state, int key)
{
	if (state->state == STATE_MENU)
		menu_key(state, key);
	else if (state->state == STATE_GAME)
		game_key(state, key);
}

/*
 ** Used in main loop
 ** This event is fired when the screen updates.
 */

void			on_redraw(t_gamestate *state)
{
	if (state->state == STATE_MENU)
		menu_redraw(state);
	else if (state->state == STATE_GAME)
		game_redraw(state);
	refresh();
}
