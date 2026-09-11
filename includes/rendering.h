#ifndef RENDERING_H
# define RENDERING_H

# include "cub3d.h"

/**
 * @brief One ray of the DDA walk, from the player out to the wall it hits.
 *
 * dir    direction the ray travels, in map units
 * delta  distance along the ray between two grid lines of each axis
 * side   running distance to the next grid line of each axis
 * map    tile the ray is standing on right now
 * step   +1 or -1 per axis, whichever way the ray is heading
 * dist   perpendicular distance to the wall, once the walk is over
 * x_side true if the ray came in through a vertical grid line, so the wall
 *        it hit faces east or west
 */
typedef struct s_ray
{
	t_dpoint	dir;
	t_dpoint	delta;
	t_dpoint	side;
	t_point		map;
	t_point		step;
	double		dist;
	bool		x_side;
}	t_ray;

t_ray			cast_ray(double camera_x);

void			render_minimap(int offset_x, int offset_y);
void			render(void);

t_image			create_image(int w, int h);
void			destroy_image(t_image *img);
void			clear_image(t_image *img, uint32_t color);
uint32_t		get_px(t_image *img, int x, int y);
void			put_px(t_image *img, int x, int y, uint32_t color);
void			display_image(t_image *img, int x, int y);

void			put_pixel(int x, int y, uint32_t color);
void			put_line(t_point a, t_point b, uint32_t color);
void			put_square(int x, int y, int size, uint32_t color);
void			put_star(int x, int y, int size, uint32_t color);
void			put_circle(int cx, int cy, int radius, uint32_t color);

#endif /* RENDERING_H */
