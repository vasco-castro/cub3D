
#ifndef RENDERING_H
# define RENDERING_H

# include "cub3d.h"

void	render_minimap(int offset_x, int offset_y);
void	render(void);

void	put_pixel(int x, int y, uint32_t color);
void	put_line_x(int x, int y, int size, uint32_t color);
void	put_line_y(int x, int y, int size, uint32_t color);
void	put_line(int x0, int y0, int x1, int y1, uint32_t color);
void	put_square(int x, int y, int size, uint32_t color);
void	put_star(int x, int y, int size, uint32_t color);
void	put_circle(int cx, int cy, int radius, uint32_t color);

#endif /* RENDERING_H */