
#ifndef RENDERING_H
# define RENDERING_H

# include "cub3d.h"

void	render_minimap(int col, int row);
void	render(void);

void	put_pixel(int x, int y, uint32_t color);
void	put_line_x(int x, int y, int size, uint32_t color);
void	put_line_y(int x, int y, int size, uint32_t color);
void	put_square(int x, int y, int size, uint32_t color);
void	put_star(int x, int y, int size, uint32_t color);

#endif /* RENDERING_H */