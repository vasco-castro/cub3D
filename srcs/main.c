
#include "cub3d.h"

void	destroy_cub3d(int status)
{
	if (game())
	{
		// clean_textures();
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
	// free_textures();
	// free_sprites();
	exit(status);
}

static void	game_init(void)
{
	game()->mlx = mlx_init();
	game()->win = mlx_new_window(game()->mlx, W_WIDTH, W_HEIGHT, W_MSG);
	mlx_key_hook(game()->win, (void *)key_handler, &game);
	// mlx_hook(game()->win, ON_KEYDOWN, (1L<<0), (void *)key_handler, &game);
	mlx_mouse_hook(game()->win, (void *)mouse_click_handler, &game);
	// mlx_hook(game()->win, ON_MOUSEDOWN, (1L<<2), (void *)mouse_click_handler, &game);
	mlx_hook(game()->win, ON_MOUSEUP, (1L<<3), (void *)mouse_click_handler, &game);
	// mlx_hook(game()->win, ON_MOUSEMOVE, (1L<<6), (void *)mouse_move_handler, &game);
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
		return (1);
	}
	if (!ft_has_extension(argv[1], ".cub"))
	{
		ft_dprintf(STDERR_FILENO, RED "Error\n%s" RESET,
			"Invalid file. Expected a .cub file.\n");
		return (1);
	}
	parse_map(argv[1]);
	ft_printfile("banner.txt");
	game_init();
	return (destroy_cub3d(EXIT_SUCCESS), EXIT_SUCCESS);
}
