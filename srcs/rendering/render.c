/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:03:27 by vsoares-          #+#    #+#             */
/*   Updated: 2026/09/13 17:25:19 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_bg(void)
{
	int	y;

	y = 0;
	while (y < W_HEIGHT / 2)
	{
		put_line(get_point(0, y), get_point(W_WIDTH - 1, y), map()->ceiling);
		y++;
	}
	while (y < W_HEIGHT)
	{
		put_line(get_point(0, y), get_point(W_WIDTH - 1, y), map()->floor);
		y++;
	}
}

/**
 * @brief Casts one ray per screen column and draws the wall it found.
 */
static void	render_walls(void)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < W_WIDTH)
	{
		ray = cast_ray(camera_ray(2.0 * x / W_WIDTH - 1.0));
		render_wall_column(x, &ray);
		x++;
	}
}

void	render(void)
{
	clear_image(&game()->screen, 0x00000000);
	render_bg();
	render_walls();
	if (keys()->minimap)
		render_minimap();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->screen.img, 0, 0);
}
