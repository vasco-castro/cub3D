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
 * @brief Which of the four faces of a wall tile the ray ran into.
 *
 * A ray that crossed a vertical grid line hit a face looking east or west,
 * and it is the face turned towards the ray that is lit: heading east means
 * landing on the wall's west side. North is -y, as the spawn angles say, so
 * a ray heading south lands on a north face.
 *
 * Returns a debug shade for now; once the walls are textured this is where
 * the matching texture gets picked.
 */
static uint32_t	face_color(t_ray *ray)
{
	if (ray->x_side && ray->step.x > 0)
		return (WALL_COLOR_WEST);
	if (ray->x_side)
		return (WALL_COLOR_EAST);
	if (ray->step.y > 0)
		return (WALL_COLOR_NORTH);
	return (WALL_COLOR_SOUTH);
}

/**
 * @brief Draws one vertical slice of wall, centred on the horizon.
 *
 * A wall one tile away fills the whole screen, one two tiles away half of
 * it, and so on, which is all the perspective a grid of equal-height walls
 * needs. The distance is floored so a wall you are hugging cannot blow the
 * height up past what an int holds.
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
	put_line(get_point(x, start), get_point(x, end), face_color(ray));
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
		render_column(x, &ray);
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
	display_image(&game()->screen, 0, 0);
}
