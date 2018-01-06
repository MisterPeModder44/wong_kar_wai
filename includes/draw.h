/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:29:54 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 14:00:07 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include <ncurses.h>

void			fill_window(WINDOW *win, short color);
void			print_middle(WINDOW *win, int y, char *str);
void			put_square(WINDOW *win, int *square, short *color, char *text);

#endif
