#include "cub3d.h"

/**
 * @brief Point at `dist` pixels from the minimap centre along `angle`.
 *
 * The minus signs match the rest of the minimap: screen y grows downwards
 * while the player angle is measured in the opposite convention.
 */
static t_point	cone_point(int px, int py, double angle, double dist)
{
	return (get_point(px - (int)(cos(angle) * dist),
		py - (int)(sin(angle) * dist)));
}

/**
 * @brief Fills the FOV wedge as a fan of rays between plane1 and plane2.
 *
 * One ray per pixel of arc length keeps the wedge gap-free at any scale.
 */
static void	render_minimap_cone(int px, int py, int radius, int length)
{
	double	step;
	double	angle;
	int		rays;
	int		i;

	rays = (int)(2 * HALF_FOV * length) + 2;
	step = 2 * HALF_FOV / rays;
	i = 0;
	while (i <= rays)
	{
		angle = player()->angle - HALF_FOV + i * step;
		put_line(cone_point(px, py, angle, radius),
			cone_point(px, py, angle, length), MINIMAP_CONE_COLOR);
		i++;
	}
}

static void	render_minimap_direction(int px, int py, int radius)
{
	int	length;

	length = MINIMAP_CONE_TILES * map()->minimap_scale;
	render_minimap_cone(px, py, radius, length);
	put_line(cone_point(px, py, player()->angle + HALF_FOV, radius),
		cone_point(px, py, player()->angle + HALF_FOV, length),
		MINIMAP_PLAYER_COLOR);
	put_line(cone_point(px, py, player()->angle - HALF_FOV, radius),
		cone_point(px, py, player()->angle - HALF_FOV, length),
		MINIMAP_PLAYER_COLOR);
	put_line(cone_point(px, py, player()->angle, radius),
		cone_point(px, py, player()->angle, length), MINIMAP_PLAYER_COLOR);
}

void	render_minimap_player(int offset_x, int offset_y)
{
	int	px;
	int	py;
	int	radius;

	px = offset_x + MINIMAP_RADIUS * map()->minimap_scale;
	py = offset_y + MINIMAP_RADIUS * map()->minimap_scale;
	radius = map()->minimap_scale / 10;
	render_minimap_direction(px, py, radius);
	put_circle(px, py, radius, MINIMAP_PLAYER_COLOR);
}

void	render_minimap(int offset_x, int offset_y)
{
	int	y;
	int	x;
	int	px;
	int	py;

	y = (int) player()->pos.y - MINIMAP_RADIUS;
	while (y <= (int) player()->pos.y + MINIMAP_RADIUS)
	{
		x = (int) player()->pos.x - MINIMAP_RADIUS;
		while (x <= (int) player()->pos.x + MINIMAP_RADIUS)
		{
			px = offset_x + (int)((x - player()->pos.x + MINIMAP_RADIUS)
					* map()->minimap_scale);
			py = offset_y + (int)((y - player()->pos.y + MINIMAP_RADIUS)
					* map()->minimap_scale);
			if (y >= 0 && y < map()->size.y && x >= 0 && x < map()->size.x
				&& map()->map[y][x] == '0')
				put_square(px, py, map()->minimap_scale, MINIMAP_FLOOR_COLOR);
			else
				put_square(px, py, map()->minimap_scale, MINIMAP_WALL_COLOR);
			x++;
		}
		y++;
	}
	render_minimap_player(offset_x, offset_y);
}
