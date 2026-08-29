#ifndef RENDERING_H
# define RENDERING_H

# include "cub3d.h"

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
