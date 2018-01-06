/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:28:48 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 18:26:51 by yguaye           ###   ########.fr       */
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

static int		internal_get_group(int number)
{
	short		pos;

	if (number == 0)
		return (0);
	pos = 1;
	while (number > 1)
	{
		number >>= 1;
		++pos;
	}
	return (pos);
}

static short	internal_get_color(int number)
{
	if (number <= 2)
		return (COLOR_WHITE);
	else if (number == 4)
		return (COLOR_YELLOW);
	else if (number == 8)
		return (COLOR_GREEN);
	else if (number == 16 || number == 32)
		return (COLOR_CYAN);
	else if (number == 64 || number == 128)
		return (COLOR_BLUE);
	else if (number == 254 || number == 512)
		return (COLOR_BLUE);
	return (COLOR_RED);
}

void			put_square(WINDOW *win, int *square, int number, char *text)
{
	int			x;
	int			y;
	short		group;

	y = 0;
	group = COLOR_SQUARE + internal_get_group(number);
	init_pair(group, COLOR_BLACK, internal_get_color(number));
	attron(COLOR_PAIR(group));
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
	mvwprintw(win, square[1] + square[2] / 4 - 1, square[0] + square[2] / 2 -
			ft_strlen(text) / 2, text);
	attroff(COLOR_PAIR(group));
}
