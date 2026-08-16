#include "cub3d.h"
#include "parsing.h"

void	destroy_cub3d(int status)
{
	if (game())
	{
		free_images();
		if (game()->win)
			mlx_destroy_window(game()->mlx, game()->win);
		if (game()->mlx)
		{
			mlx_destroy_display(game()->mlx);
			free(game()->mlx);
		}
		if (map()->map)
			ft_tabfree(map()->map);
	}
	exit(status);
}

static bool	mlx_init_game(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		return (false);
	return (true);
}

static void	game_init(void)
{
	game()->win = mlx_new_window(game()->mlx, W_WIDTH, W_HEIGHT, W_MSG);
	if (!game()->win)
		destroy_cub3d(EXIT_FAILURE);
	mlx_key_hook(game()->win, (void *)key_handler, &game);
	// mlx_hook(game()->win, ON_KEYDOWN, (1L << 0), (void *)key_handler, &game);
	mlx_mouse_hook(game()->win, (void *)mouse_click_handler, &game);
	// mlx_hook(game()->win, ON_MOUSEDOWN, (1L << 2), (void *)mouse_click_handler, &game);
	mlx_hook(game()->win, ON_MOUSEUP, (1L << 3), (void *)mouse_click_handler, &game);
	// mlx_hook(game()->win, ON_MOUSEMOVE, (1L << 6), (void *)mouse_move_handler, &game);
	mlx_hook(game()->win, ON_DESTROY, 1, (void *)close_window, &game);
	mlx_loop_hook(game()->mlx, (void *)loop_hook, &game);
	mlx_loop(game()->mlx);
}

int	main(int argc, char *argv[])
{
	parse_debug_mode(&argc, argv);
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: %s <filename>\n", argv[0]);
		ft_dprintf(STDERR_FILENO, RED "Error\n%s" RESET,
			"Invalid number of arguments. Expected 1 argument for the map file.\n");
		return (EXIT_FAILURE);
	}
	if (!ft_has_extension(argv[1], ".cub"))
	{
		ft_dprintf(STDERR_FILENO, RED "Error\n%s" RESET,
			"Invalid file. Expected a .cub file.\n");
		return (EXIT_FAILURE);
	}
	if (!mlx_init_game())
		return (EXIT_FAILURE);
	if (!parse_map(argv[1]))
	{
		ft_dprintf(STDERR_FILENO, RED "Error\nfailed to parse map\n" RESET);
		return (destroy_cub3d(EXIT_FAILURE), EXIT_FAILURE);
	}
	map()->minimap_scale = W_WIDTH / 100 * MINIMAP_SCALE_PERCENTAGE / map()->size.x;
	if (debug_mode())
		printf_double_pointer(map()->map);
	return (game_init(), destroy_cub3d(EXIT_SUCCESS), EXIT_SUCCESS);
}
