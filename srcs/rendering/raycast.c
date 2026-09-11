#include "rendering.h"

/**
 * @brief Direction of the ray for one screen column.
 *
 * `camera_x` runs from -1 on the left edge of the screen to +1 on the right.
 *
 * The engine stores `dir` as (cos angle, sin angle) but moves the player
 * against it (see move_player), so the way the player actually faces is -dir.
 *
 * `plane` is the camera plane: perpendicular to the view and tan(HALF_FOV)
 * long, so its two tips are exactly the edges of the FOV. Walking along it
 * in even steps is what keeps the columns evenly spaced on screen, instead
 * of the fish-eye you get from fanning the rays out by equal angles.
 */
static t_dpoint	ray_dir(double camera_x)
{
	t_dpoint	dir;
	t_dpoint	plane;

	dir = get_dpoint(-player()->dir.x, -player()->dir.y);
	plane = get_dpoint(-dir.y * tan(HALF_FOV), dir.x * tan(HALF_FOV));
	return (get_dpoint(dir.x + plane.x * camera_x,
			dir.y + plane.y * camera_x));
}

/**
 * @brief Sets up the x axis of the DDA: which way to step and how far.
 *
 * delta.x is the distance the ray travels between two vertical grid lines,
 * side.x the distance from the player to the first one ahead.
 * A ray running exactly parallel to the axis never crosses one, hence 1e30.
 */
static void	init_side_x(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->delta.x = 1e30;
	else
		ray->delta.x = fabs(1 / ray->dir.x);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (player()->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map.x + 1 - player()->pos.x) * ray->delta.x;
	}
}

/**
 * @brief Same as init_side_x, for the horizontal grid lines.
 */
static void	init_side_y(t_ray *ray)
{
	if (ray->dir.y == 0)
		ray->delta.y = 1e30;
	else
		ray->delta.y = fabs(1 / ray->dir.y);
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (player()->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map.y + 1 - player()->pos.y) * ray->delta.y;
	}
}

/**
 * @brief Walks the ray tile by tile until it lands on a wall.
 *
 * Each turn it jumps to whichever grid line is closer, so the ray visits
 * every tile it touches and never skips a corner.
 *
 * The distance kept at the end is the one *before* the last jump, which is
 * the distance to the wall face rather than to the far side of the tile.
 * It is measured along the camera plane's normal, not along the ray, which
 * is what makes flat walls come out flat.
 */
static void	run_dda(t_ray *ray)
{
	while (true)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->x_side = true;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->x_side = false;
		}
		if (is_wall(ray->map.x, ray->map.y))
			break ;
	}
	if (ray->x_side)
		ray->dist = ray->side.x - ray->delta.x;
	else
		ray->dist = ray->side.y - ray->delta.y;
}

/**
 * @brief Casts one ray from the player and returns where it hit.
 * @param camera_x Position on the camera plane, -1 left edge to +1 right.
 */
t_ray	cast_ray(double camera_x)
{
	t_ray	ray;

	ray.dir = ray_dir(camera_x);
	ray.map = get_point((int)player()->pos.x, (int)player()->pos.y);
	ray.x_side = false;
	ray.dist = 0;
	init_side_x(&ray);
	init_side_y(&ray);
	run_dda(&ray);
	return (ray);
}
