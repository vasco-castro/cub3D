
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

void	put_line(int x0, int y0, int x1, int y1, uint32_t color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = -(abs(y1 - y0));
	sx = -1 + 2 * (x0 < x1);
	sy = -1 + 2 * (y0 < y1);
	err = dx + dy;
	while (1)
	{
		put_pixel(x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
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

void	put_circle(int cx, int cy, int radius, uint32_t color)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				put_pixel(cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}
