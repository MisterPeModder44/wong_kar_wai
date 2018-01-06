/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:52:38 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 19:01:04 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <stdbool.h>
# include "grid.h"

# define ESC_KEY	27
# define Q_KEY		113
# define ENTER_KEY	10

enum	e_const
{
	EMPTY_VALUE = 0,
	STATE_MENU,
	STATE_GAME,
	STATE_LOST,
	WIN_VALUE = 2048,
};

enum	e_color_set
{
	COLOR_TITLE = 1,
	COLOR_BG,
	COLOR_SELECT,
	COLOR_SQUARE,
	COLOR_PLAIN
};

#endif
