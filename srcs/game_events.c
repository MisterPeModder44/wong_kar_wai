/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:44:11 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 14:43:44 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <libft_base/stringft.h>
#include "events.h"
#include "draw.h"

void			game_key(t_gamestate *state, int key)
{
	state--;
	key--;
}

void			game_redraw(t_gamestate *state)
{
	int				sx;
	int				sy;
	unsigned int	x;
	unsigned int	y;
	char			*text;

	fill_window(stdscr, COLOR_BLACK);
	sx = COLS / 2 - (state->grid->grid_size * 12 + state->grid->grid_size - 1) / 2;
	sy = LINES / 2 - (state->grid->grid_size * 5 + state->grid->grid_size - 1) / 2;
	y = -1;
	text = NULL;
	while (++y < state->grid->grid_size)
	{
		x = -1;
		sx = COLS / 2 - (state->grid->grid_size * 12 + state->grid->grid_size - 1) / 2;
		while (++x < state->grid->grid_size)
		{
			if (text)
				ft_strdel(&text);
			text = state->grid->grid[x][y] ? ft_itoa(state->grid->grid[x][y]) : ft_strdup(" ");
			put_square(stdscr, (int[]){sx, sy, 12}, (short[]){COLOR_SQUARE, COLOR_YELLOW}, text);
			sx += 13;
		}
		sy += 6;
	}
}
