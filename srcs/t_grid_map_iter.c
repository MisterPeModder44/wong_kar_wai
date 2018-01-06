/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_grid_map_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:16:22 by mressier          #+#    #+#             */
/*   Updated: 2018/01/06 14:16:23 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		t_grid_map(t_grid *grid, t_grid_func func)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < grid->grid_size)
	{
		j = 0;
		while (j < grid->grid_size)
		{
			func(grid, i, j);
			j++;
		}
		i++;
	}
}

int			t_grid_iter(t_grid *grid, t_grid_func_iter func)
{
	unsigned int	i;
	unsigned int	j;
	int				ret;

	i = 0;
	while (i < grid->grid_size)
	{
		j = 0;
		while (j < grid->grid_size)
		{
			ret = func(grid, i, j);
			if (ret != 0)
				return (ret);
			j++;
		}
		i++;
	}
	return (0);
}
