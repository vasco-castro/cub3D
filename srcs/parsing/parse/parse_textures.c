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
	destroy_image(&map()->north_texture);
	destroy_image(&map()->south_texture);
	destroy_image(&map()->east_texture);
	destroy_image(&map()->west_texture);
}

static bool	load_image_from_file(t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(game()->mlx, path,
			&image->w, &image->h);
	if (!image->img)
		return (false);
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line, &image->endian);
	if (!image->addr)
		return (mlx_destroy_image(game()->mlx, image->img), false);
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
