#include "libft.h"
#include "game_2048.h"

int		main()
{
    t_grid      new_grid;

    if (t_grid_init(&new_grid, GRID_SIZE_MAX) == EXIT_FAILURE)
        return (EXIT_FAILURE);

    for (int i = 0; i < GRID_SIZE_MAX; i++)
    {

    }

    if (t_grid_set_number(&new_grid, GRID_SIZE_MAX - 1, GRID_SIZE_MAX - 1, 1) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    t_grid_display(new_grid);
	return (EXIT_SUCCESS);
}

