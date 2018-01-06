/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:17:13 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 18:21:20 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

int				on_key_pressed(t_gamestate *state, int key)
{
	if (state->state == STATE_MENU)
		return (menu_key(state, key));
	else if (state->state == STATE_GAME)
		return (game_key(state, key));
	else if (state->state == STATE_LOST)
		return (gameover_key(state, key));
	return (0);
}

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
