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
 * @brief Draws one vertical slice of wall, centred on the horizon.
 *
 * A wall one tile away fills the whole screen, one two tiles away half of
 * it, and so on, which is all the perspective a grid of equal-height walls
 * needs. The distance is floored so a wall you are hugging cannot blow the
 * height up past what an int holds.
 *
 * East/west faces get a darker shade, so corners stay readable while there
 * are no textures yet.
 */
static void	render_column(int x, t_ray *ray)
{
	int		height;
	int		start;
	int		end;

	if (ray->dist < 0.01)
		ray->dist = 0.01;
	height = (int)(W_HEIGHT / ray->dist);
	start = W_HEIGHT / 2 - height / 2;
	end = start + height;
	if (start < 0)
		start = 0;
	if (end > W_HEIGHT - 1)
		end = W_HEIGHT - 1;
	if (ray->x_side)
		put_line(get_point(x, start), get_point(x, end), WALL_COLOR_EW);
	else
		put_line(get_point(x, start), get_point(x, end), WALL_COLOR_NS);
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
		ray = cast_ray(2.0 * x / W_WIDTH - 1.0);
		render_column(x, &ray);
		x++;
	}
}

void	render(void)
{
	int	minimap_low_pos;
	int	minimap_right_pos;

	clear_image(&game()->screen, 0x00000000);
	render_bg();
	render_walls();
	if (keys()->minimap)
	{
		minimap_low_pos = W_HEIGHT
			- ((2 * MINIMAP_RADIUS + 1) * map()->minimap_scale);
		minimap_right_pos = W_WIDTH
			- ((2 * MINIMAP_RADIUS + 1) * map()->minimap_scale);
		if (MINIMAP_POS == MINIMAP_UL)
			render_minimap(0, 0);
		else if (MINIMAP_POS == MINIMAP_LL)
			render_minimap(0, minimap_low_pos);
		else if (MINIMAP_POS == MINIMAP_UR)
			render_minimap(minimap_right_pos, 0);
		else if (MINIMAP_POS == MINIMAP_LR)
			render_minimap(minimap_right_pos, minimap_low_pos);
		else
			render_minimap(0, 0);
	}
	display_image(&game()->screen, 0, 0);
}
