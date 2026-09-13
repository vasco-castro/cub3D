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
 * @brief Which way the player was looking when the ray hit, as a debug shade.
 *
 * Walls are named after the direction they are seen from: looking north
 * shows the NORTH wall, whatever side of its tile that face is on. A ray
 * that crossed a vertical grid line was heading east or west, and North is
 * -y, as the spawn angles say, so a ray with step.y < 0 was heading north.
 *
 * face_texture picks the texture off the same four cases; this shade is
 * what debug mode draws instead, to check the faces without textures.
 */
static uint32_t	face_color(t_ray *ray)
{
	if (ray->x_side && ray->step.x > 0)
		return (WALL_COLOR_EAST);
	if (ray->x_side)
		return (WALL_COLOR_WEST);
	if (ray->step.y < 0)
		return (WALL_COLOR_NORTH);
	return (WALL_COLOR_SOUTH);
}

/**
 * @brief The texture for the wall a ray hit, using the same four cases as
 * face_color: looking north shows the NO texture, looking east the EA one.
 */
static t_image	*face_texture(t_ray *ray)
{
	if (ray->x_side && ray->step.x > 0)
		return (&map()->east_texture);
	if (ray->x_side)
		return (&map()->west_texture);
	if (ray->step.y < 0)
		return (&map()->north_texture);
	return (&map()->south_texture);
}

/**
 * @brief Which column of `tex` the ray hit, from 0 to tex->w - 1.
 *
 * The hit point is pos + dir * dist, and its fractional part along the wall
 * is how far across the tile the ray landed. On faces the player sees while
 * looking west or south, that coordinate shrinks as the screen moves right,
 * so the column is flipped or the texture would come out mirrored.
 */
static int	texture_x(t_ray *ray, t_image *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->x_side)
		wall_x = player()->pos.y + ray->dist * ray->dir.y;
	else
		wall_x = player()->pos.x + ray->dist * ray->dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->w);
	if ((ray->x_side && ray->dir.x < 0) || (!ray->x_side && ray->dir.y > 0))
		tex_x = tex->w - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->w)
		tex_x = tex->w - 1;
	return (tex_x);
}

/**
 * @brief Draws one vertical slice of wall, centred on the horizon.
 *
 * A wall one tile away fills the whole screen, one two tiles away half of
 * it, and so on, which is all the perspective a grid of equal-height walls
 * needs. The distance is floored so a wall you are hugging cannot blow the
 * height up past what an int holds.
 *
 * The slice walks down the texture column by `step` texels per pixel,
 * counted from the wall's real top even when that is above the screen, so a
 * wall taller than the window is cropped rather than squashed. In debug mode
 * the slice is a flat face_color instead.
 */
static void	render_column(int x, t_ray *ray)
{
	t_image	*tex;
	int		tex_x;
	int		top;
	int		y;
	double	step;

	tex = face_texture(ray);
	tex_x = texture_x(ray, tex);
	y = (int)(W_HEIGHT / fmax(ray->dist, 0.01));
	step = (double)tex->h / y;
	top = W_HEIGHT / 2 - y / 2;
	y = top + y;
	if (y > W_HEIGHT)
		y = W_HEIGHT;
	while (--y >= 0 && y >= top)
	{
		if (debug_mode())
			put_pixel(x, y, face_color(ray));
		else
			put_pixel(x, y, get_px(tex, tex_x, (int)((y - top) * step))
				& 0x00FFFFFF);
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
