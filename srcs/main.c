/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:59:49 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 18:18:10 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include "draw.h"
#include "events.h"
#include "game_2048.h"

void			sig_handler(int signo)
{
	if (signo == SIGINT || signo == SIGTSTP || signo == SIGUSR1 ||
			signo == SIGUSR2)
	{
		endwin();
		exit(EXIT_FAILURE);
	}
}

void			loop(void)
{
	t_gamestate	state;
	t_grid		grid;
	int			key;

	state = (t_gamestate){.state = STATE_MENU, .menu_item = 0, .grid = &grid};
	t_grid_init(state.grid, GRID_SIZE_MAX);
	t_grid_spread_random_number(state.grid, GRID_SIZE_MAX / 2);
	start_color();
	while (1)
	{
		on_redraw(&state);
		key = getch();
		if (on_key_pressed(&state, key))
			break ;
	}
}

int				main(void)
{
	srand(time(NULL));
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	signal(SIGINT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	if (has_colors())
		loop();
	else
	{
		printw("Your terminal does not support color.");
		refresh();
	}
	endwin();
	return (0);
}
