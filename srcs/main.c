#include "libft.h"
#include "game_2048.h"

int		main()
{
    t_grid      new_grid;

    if (t_grid_init(&new_grid, GRID_SIZE_MAX) == EXIT_FAILURE)
        return (EXIT_FAILURE);

    for (int i = 0; i < 10; ++i) {
        t_grid_set_number(&new_grid, 0, 0, 1);
        t_grid_display(new_grid);
        ft_putchar('\n');

        ft_putstr("MOVE DOWN\n");
        t_grid_move(MOVE_DOWN, &new_grid);
        t_grid_display(new_grid);
        ft_putchar('\n');
    }

	return (EXIT_SUCCESS);
}

