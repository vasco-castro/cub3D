/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:03:27 by vsoares-          #+#    #+#             */
/*   Updated: 2026/09/13 17:03:27 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief The point `dist` along a ray, on the minimap.
 *
 * cast_ray leaves dir unnormalised, and pos + dir * dist is the point the
 * DDA was standing on at that distance, so the same arithmetic gives both
 * the wall it hit and any point short of it.
 */
static t_point	ray_pos(t_ray *ray, double dist)
{
	return (minimap_pos(get_dpoint(player()->pos.x + ray->dir.x * dist,
				player()->pos.y + ray->dir.y * dist)));
}

/**
 * @brief Draws one ray of the cone, from the player dot to whatever stops it.
 *
 * A ray stops at the wall it hit or at the cone's reach, whichever comes
 * first, so the cone shows what the player can actually see instead of
 * spilling through walls.
 */
static void	draw_ray(double camera_x, uint32_t color)
{
	t_ray	ray;
	double	dist;

	ray = cast_ray(camera_ray(camera_x));
	dist = ray.dist;
	if (dist > MINIMAP_CONE_TILES)
		dist = MINIMAP_CONE_TILES;
	put_line(ray_pos(&ray, MINIMAP_PLAYER_RADIUS), ray_pos(&ray, dist), color);
}

/**
 * @brief Draws the player: the FOV cone, its three marker rays and the dot.
 *
 * The cone is filled by sweeping camera_x across the camera plane, the very
 * same sweep render_walls does, one ray per pixel of the plane's width so
 * the wedge cannot show gaps. The marker rays are the two FOV edges and the
 * centre line.
 */
void	render_minimap_player(void)
{
	t_point	centre;
	int		rays;
	int		i;

	rays = (int)(2 * tan(HALF_FOV) * MINIMAP_CONE_TILES
			* minimap()->scale) + 2;
	i = 0;
	while (i <= rays)
	{
		draw_ray(-1.0 + 2.0 * i / rays, MINIMAP_CONE_COLOR);
		i++;
	}
	draw_ray(-1.0, MINIMAP_PLAYER_COLOR);
	draw_ray(0.0, MINIMAP_PLAYER_COLOR);
	draw_ray(1.0, MINIMAP_PLAYER_COLOR);
	centre = minimap_pos(player()->pos);
	put_circle(centre.x, centre.y,
		(int)(MINIMAP_PLAYER_RADIUS * minimap()->scale),
		MINIMAP_PLAYER_COLOR);
}
