/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:15:47 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/07 18:16:36 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "game_2048.h"

void			on_redraw(t_gamestate *state);
int				on_key_pressed(t_gamestate *state, int key);

void			menu_redraw(t_gamestate *state);
int				menu_key(t_gamestate *state, int key);

void			quit_dialog_redraw(t_gamestate *state);
int				quit_dialog_key(t_gamestate *state, int key);

int				game_key(t_gamestate *state, int key);
void			game_redraw(t_gamestate *state);

int				gameover_key(t_gamestate *state, int key);
int				gameover_key2(t_gamestate *state, int key);
void			gameover_redraw(t_gamestate *state);

int				score_key(t_gamestate *state, int key);
void			score_redraw(t_gamestate *state);

#endif
