/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:24:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/12 20:32:50 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

void	free_images(void)
{
	if (map()->north_texture.ptr)
		mlx_destroy_image(game()->mlx, map()->north_texture.ptr);
	if (map()->south_texture.ptr)
		mlx_destroy_image(game()->mlx, map()->south_texture.ptr);
	if (map()->east_texture.ptr)
		mlx_destroy_image(game()->mlx, map()->east_texture.ptr);
	if (map()->west_texture.ptr)
		mlx_destroy_image(game()->mlx, map()->west_texture.ptr);
}

static bool	load_image_from_file(t_img *image, char *path)
{
	int		width;
	int		height;

	image->ptr = mlx_xpm_file_to_image(game()->mlx, path, &width, &height);
	if (!image->ptr)
		return (false);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->size_l, &image->endian);
	if (!image->data)
		return (mlx_destroy_image(game()->mlx, image->ptr), false);
	return (true);
}

bool	parse_textures(t_map_vars map_vars)
{
	if (!check_texture(map_vars))
		return (debug("Error\ncheck_texture failed\n"), false);
	if (!load_image_from_file(&map()->north_texture, map_vars.north))
		return (free_images(), false);
	if (!load_image_from_file(&map()->south_texture, map_vars.south))
		return (free_images(), false);
	if (!load_image_from_file(&map()->west_texture, map_vars.west))
		return (free_images(), false);
	if (!load_image_from_file(&map()->east_texture, map_vars.east))
		return (free_images(), false);
	return (true);
}
