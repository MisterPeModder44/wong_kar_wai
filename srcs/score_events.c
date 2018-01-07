/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:34:04 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/07 17:34:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "events.h"
#include "draw.h"

int				score_key(t_gamestate *state, int key)
{
	if (key == ESC_KEY || key == Q_KEY || key == ENTER_KEY)
		state->state = STATE_MENU;
	return (0);
}

void			score_redraw(t_gamestate *state)
{
	void			*win;
	unsigned int	i;
	t_score			*score_tab;

	win = subwin(stdscr, state->scores->nb_score, 29, LINES / 2 -
			state->scores->nb_score / 2, COLS / 2 - 14);
	i = -1;
	score_tab = state->scores->score_tab;
	while (++i < state->scores->nb_score)
		mvwprintw(win, i + 1, 1, "%d - %s: %d", i + 1, score_tab[i].name,
				score_tab[i].score);
	box(win, ACS_VLINE, ACS_HLINE);
	delwin(win);
	print_middle(stdscr, LINES / 2 - state->scores->nb_score / 2 - 1, "SCORES");
	print_middle(stdscr, LINES / 2 + state->scores->nb_score / 2 + 1,
			"[ BACK ]");
}
