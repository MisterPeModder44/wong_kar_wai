/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:15:47 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/06 13:45:20 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

#include "game_2048.h"

void			on_redraw(t_gamestate *state);
void			on_key_pressed(t_gamestate *state, int key);

void			menu_redraw(t_gamestate *state);
void			menu_key(t_gamestate *state, int key);

void			game_key(t_gamestate *state, int key);
void			game_redraw(t_gamestate *state);

#endif