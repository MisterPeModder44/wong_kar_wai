/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:28:48 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 14:16:50 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game_2048.h"
#include <libft_base/stringft.h>

void			fill_window(WINDOW *win, short color)
{
	int			dim[2];
	int			i;
	int			bj;
	int			j;

	getmaxyx(win, dim[0], dim[1]);
	getbegyx(win, i, bj);
	init_pair(COLOR_BG, COLOR_WHITE, color);
	attron(COLOR_PAIR(COLOR_BG));
	while (i <= dim[0])
	{
		j = bj;
		while (j < dim[1])
		{
			mvwaddch(win, i, j, ' ');
			++j;
		}
		++i;
	}
	attroff(COLOR_PAIR(COLOR_BG));
	wrefresh(win);
}

void			print_middle(WINDOW *win, int y, char *str)
{
	int			dim[2];

	getmaxyx(win, dim[0], dim[1]);
	mvwprintw(win, y, dim[1] / 2 - ft_strlen(str) / 2, str);
}

void			put_square(WINDOW *win, int *square, short *color, char *text)
{
	int			x;
	int			y;

	y = 0;
	init_pair(color[0], COLOR_BLACK, color[1]);
	attron(COLOR_PAIR(color[0]));
	while (y < square[2] / 2 - 1)
	{
		x = 0;
		while (x < square[2])
		{
			mvwaddch(win, y + square[1], x + square[0], ' ');
			++x;
		}
		++y;
	}
	mvwprintw(win, square[1] + square[2] / 4 - 1, square[0] + square[2] / 2 - ft_strlen(text) / 2, text);
	attroff(COLOR_PAIR(color[0]));
}
