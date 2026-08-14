
#include "cub3d.h"

void	put_pixel(int x, int y, uint32_t color)
{
	mlx_pixel_put(game()->mlx, game()->win, x, y, color);
}

void	put_line_x(int x, int y, int size, uint32_t color)
{
	int	i;

	i = 0;
	while (i < size)
		put_pixel(x + i++, y, color);
}

void	put_line_y(int x, int y, int size, uint32_t color)
{
	int	i;

	i = 0;
	while (i < size)
		put_pixel(x, y + i++, color);
}

void	put_square(int x, int y, int size, uint32_t color)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_line_x(x, y + i, size, color);
		i++;
	}
}

void	put_star(int x, int y, int size, uint32_t color)
{
	int	i;
	int	width;
	int	center;

	if (size <= 0)
		return ;
	center = size / 2;
	i = 0;
	while (i < size)
	{
		if (i <= center)
			width = 1 + 2 * i;
		else
			width = 1 + 2 * (size - 1 - i);
		if (width > size)
			width = size;
		put_line_y(x + i, y + ((size - width) / 2), width, color);
		i++;
	}
}
