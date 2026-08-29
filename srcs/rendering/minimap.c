#include "cub3d.h"

static void	render_minimap_direction(int px, int py, int radius)
{
	int	length;
	int	dx;
	int	dy;

	length = map()->minimap_scale;
	dx = (int)(player()->dir.x * length);
	dy = (int)(player()->dir.y * length);
	put_line(get_point(px - (int)(player()->dir.x * radius),
			py - (int)(player()->dir.y * radius)),
		get_point(px - dx, py - dy), MINIMAP_PLAYER_COLOR);
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
