#include "cub3d.h"

void	put_pixel(int x, int y, uint32_t color)
{
	put_px(&game()->screen, x, y, color);
}

void	put_line(t_point a, t_point b, uint32_t color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d = get_point(abs(b.x - a.x), -abs(b.y - a.y));
	s = get_point(-1 + 2 * (a.x < b.x), -1 + 2 * (a.y < b.y));
	err = d.x + d.y;
	while (1)
	{
		put_pixel(a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			a.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			a.y += s.y;
		}
	}
}

void	put_square(int x, int y, int size, uint32_t color)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_line(get_point(x, y + i), get_point(x + size - 1, y + i), color);
		i++;
	}
}

void	put_star(int x, int y, int size, uint32_t color)
{
	int	i;
	int	width;
	int	center;
	int	off;

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
		off = x + (size - width) / 2;
		put_line(get_point(off, y + i),
			get_point(off + width - 1, y + i), color);
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
