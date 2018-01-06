/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:52:38 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 09:53:20 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

#define GRID_SIZE_MAX   4

typedef struct      s_grid
{
    int             grid[GRID_SIZE_MAX][GRID_SIZE_MAX];
    unsigned int    grid_size;
}                   t_grid;

/*
 * t_grid.c
 */
void                t_grid_display(t_grid grid);
int                 t_grid_init(t_grid *new_grid, unsigned int size);
int                 t_grid_set_number(t_grid *grid, unsigned int line,
                                      unsigned int col, unsigned int number);

#endif
