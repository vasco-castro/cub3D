#include "cub3d.h"

/**
 * @brief The corner of the window the minimap sits in, in pixels.
 *
 * MINIMAP_POS is fixed at compile time, so this runs once from minimap_init
 * and every drawing call afterwards just reads minimap()->origin.
 */
static t_point	minimap_origin(void)
{
	int	low;
	int	right;

	low = W_HEIGHT - minimap()->side;
	right = W_WIDTH - minimap()->side;
	if (MINIMAP_POS == MINIMAP_LL)
		return (get_point(0, low));
	if (MINIMAP_POS == MINIMAP_UR)
		return (get_point(right, 0));
	if (MINIMAP_POS == MINIMAP_LR)
		return (get_point(right, low));
	return (get_point(0, 0));
}

/**
 * @brief Settles the minimap's size and place. Call once, at startup.
 *
 * The box is a share of the window height, rounded down to a whole number
 * of pixels per tile so tiles never land on half pixels. Only compile-time
 * sizes are read, so this does not need the window to exist yet.
 */
void	minimap_init(void)
{
	keys()->minimap = true;
	minimap()->scale = W_HEIGHT * MINIMAP_SCALE_PERCENTAGE / 100;
	minimap()->scale /= (2 * MINIMAP_RADIUS + 1);
	minimap()->side = (2 * MINIMAP_RADIUS + 1) * minimap()->scale;
	minimap()->origin = minimap_origin();
}

/**
 * @brief Where a point of the world lands on the minimap, in screen pixels.
 *
 * The minimap is just the world scaled down and re-centred on the player,
 * so one formula covers tiles, the player dot and the cone alike.
 */
t_point	minimap_pos(t_dpoint world)
{
	int	x;
	int	y;

	x = minimap()->origin.x + (int)((world.x - player()->pos.x
				+ MINIMAP_RADIUS) * minimap()->scale);
	y = minimap()->origin.y + (int)((world.y - player()->pos.y
				+ MINIMAP_RADIUS) * minimap()->scale);
	return (get_point(x, y));
}

/**
 * @brief Draws the tiles around the player, then the player on top.
 */
void	render_minimap(void)
{
	t_point	pos;
	int		x;
	int		y;

	y = (int)player()->pos.y - MINIMAP_RADIUS;
	while (y <= (int)player()->pos.y + MINIMAP_RADIUS)
	{
		x = (int)player()->pos.x - MINIMAP_RADIUS;
		while (x <= (int)player()->pos.x + MINIMAP_RADIUS)
		{
			pos = minimap_pos(get_dpoint(x, y));
			if (is_wall(x, y))
				put_square(pos.x, pos.y, minimap()->scale, MINIMAP_WALL_COLOR);
			else
				put_square(pos.x, pos.y, minimap()->scale, MINIMAP_FLOOR_COLOR);
			x++;
		}
		y++;
	}
	render_minimap_player();
}
