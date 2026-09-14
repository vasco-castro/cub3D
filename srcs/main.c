/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:03:27 by vsoares-          #+#    #+#             */
/*   Updated: 2026/09/13 17:05:32 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "rendering.h"

void	destroy_cub3d(int status)
{
	if (game())
	{
		free_images();
		destroy_image(&game()->screen);
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
		return (ft_error(ERR_MLX_INIT), false);
	return (true);
}

static void	create_window(void)
{
	game()->win = mlx_new_window(game()->mlx, W_WIDTH, W_HEIGHT, W_MSG);
	if (!game()->win)
	{
		ft_error(ERR_MLX_WIN);
		destroy_cub3d(EXIT_FAILURE);
	}
	game()->screen = create_image(W_WIDTH, W_HEIGHT);
	if (!game()->screen.addr)
	{
		ft_error(ERR_MLX_IMAGE);
		destroy_cub3d(EXIT_FAILURE);
	}
}

static void	game_init(void)
{
	minimap_init();
	create_window();
	mlx_hook(game()->win, ON_DESTROY, MASK_KEYPRESS,
		(void *)close_window, &game);
	mlx_hook(game()->win, ON_KEYDOWN, MASK_KEYPRESS,
		(void *)key_down_handler, &game);
	mlx_hook(game()->win, ON_KEYUP, MASK_KEYRELEASE,
		(void *)key_up_handler, &game);
	mlx_loop_hook(game()->mlx, (void *)loop_hook, &game);
	mlx_loop(game()->mlx);
}

int	main(int argc, char *argv[])
{
	parse_debug_mode(&argc, argv);
	if (argc != 2)
		return (ft_error(ERR_ARGC, argv[0]), EXIT_FAILURE);
	if (!ft_has_extension(argv[1], ".cub"))
		return (ft_error(ERR_MAP_EXT), EXIT_FAILURE);
	if (!mlx_init_game())
		return (EXIT_FAILURE);
	if (!parse_map(argv[1]))
		return (destroy_cub3d(EXIT_FAILURE), EXIT_FAILURE);
	debug("%t", map()->map);
	return (game_init(), destroy_cub3d(EXIT_SUCCESS), EXIT_SUCCESS);
}
