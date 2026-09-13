/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:40:29 by vsoares-          #+#    #+#             */
/*   Updated: 2026/09/13 17:30:25 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_px(t_image *img, int x, int y)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return (0);
	return (*(uint32_t *)(img->addr + y * img->line + x * (img->bpp / 8)));
}

void	put_px(t_image *img, int x, int y, uint32_t color)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	*(uint32_t *)(img->addr + y * img->line + x * (img->bpp / 8)) = color;
}

t_image	create_image(int w, int h)
{
	t_image	image;

	image.w = w;
	image.h = h;
	image.img = mlx_new_image(game()->mlx, w, h);
	image.addr = NULL;
	if (image.img)
		image.addr = mlx_get_data_addr(image.img, &image.bpp,
				&image.line, &image.endian);
	return (image);
}

void	destroy_image(t_image *img)
{
	if (img->img)
		mlx_destroy_image(game()->mlx, img->img);
	img->img = NULL;
	img->addr = NULL;
}

void	clear_image(t_image *img, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
			put_px(img, x++, y, color);
		y++;
	}
}
