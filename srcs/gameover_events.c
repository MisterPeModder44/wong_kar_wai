/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:44:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/07 19:08:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <libft_base/stringft.h>
#include <libft_base/character.h>
#include "events.h"
#include "draw.h"

int				gameover_key(t_gamestate *state, int key)
{
	size_t		len;

	len = ft_strlen(state->player_name);
	if (key == DEL_KEY && len > 0)
		state->player_name[len - 1] = 0;
	else if (ft_isalnum(key) && len < NAME_SIZE_MAX)
		state->player_name[len] = (char)key;
	else if (key == ENTER_KEY && len > 0)
	{
		t_score_add_one(state->scores, state->player_name, state->grid->score);
		ft_strclr(state->player_name);
		state->state = STATE_LOST2;
	}
	return (0);
}

int				gameover_key2(t_gamestate *state, int key)
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

static void		gameover_redraw2(t_gamestate *state)
{
	char		*str;
	size_t		size;
	size_t		pn_len;
	size_t		i;

	str = "Enter a name: ";
	size = ft_strlen(str);
	mvprintw(LINES / 2 + 2, COLS / 2 - (size + NAME_SIZE_MAX) / 2, "Enter a name: ");
	init_pair(COLOR_TEXTFIELD, COLOR_BLACK, COLOR_WHITE);
	init_pair(COLOR_TEXTFIELD_INSIDE, COLOR_BLACK, COLOR_WHITE);
	i = -1;
	pn_len = ft_strlen(state->player_name);
	while (++i < NAME_SIZE_MAX)
	{
		if (i < pn_len)
		{
			attron(COLOR_PAIR(COLOR_TEXTFIELD_INSIDE));
			mvaddch(LINES / 2 + 2, i + COLS / 2 + 2, state->player_name[i]);
		}
		else
		{
			attroff(COLOR_PAIR(COLOR_TEXTFIELD_INSIDE));
			attron(COLOR_PAIR(COLOR_TEXTFIELD));
			mvaddch(LINES / 2 + 2, i + COLS / 2 + 2, ' ');
		}
	}
	attroff(COLOR_PAIR(COLOR_TEXTFIELD));
}

void			gameover_redraw(t_gamestate *state)
{
	void		*hints;
	char		*score;
	char		*str;
	int			win;

	win = t_grid_win(state->grid);
	init_pair(COLOR_TITLE, win ? COLOR_GREEN : COLOR_RED,
			COLOR_BLACK);
	attron(COLOR_PAIR(COLOR_TITLE));
	print_middle(stdscr, LINES / 2 - 2, "GAME OVER");
	if (win)
		print_middle(stdscr, LINES / 2 - 1, "- you won -");
	attroff(COLOR_PAIR(COLOR_TITLE));
	hints = subwin(stdscr, 5, 32, LINES - 7, COLS / 2 - 16);
	attron(COLOR_PAIR(0));
	print_middle(hints, 1, "press 'ENTER' to retry");
	print_middle(hints, 2, "press 'Q' to go to main menu");
	print_middle(hints, 3, "press 'ESC' to quit");
	attroff(COLOR_PAIR(0));
	box(hints, ACS_VLINE, ACS_HLINE);
	delwin(hints);
	score = ft_itoa(state->grid->score);
	print_middle(stdscr, LINES / 2, str = ft_strjoinf2("score: ", &score));
	ft_strdel(&str);
	if (state->state == STATE_LOST)
		gameover_redraw2(state);
}
