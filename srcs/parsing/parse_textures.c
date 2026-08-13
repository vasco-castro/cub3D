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

void	free_image_once(void *mlx, t_img *east_image)
{
	if (east_image)
	{
		if (east_image->ptr)
			mlx_destroy_image(mlx, east_image->ptr);
		free(east_image);
	}
}

void	free_image_twice(void *mlx, t_img *east_image, t_img *west_image)
{
	if (east_image)
	{
		if (east_image->ptr)
			mlx_destroy_image(mlx, east_image->ptr);
		free(east_image);
	}
	if (west_image)
	{
		if (west_image->ptr)
			mlx_destroy_image(mlx, west_image->ptr);
		free(west_image);
	}
}

void	free_image_thrice(void *mlx, t_img *east_image, t_img *west_image, t_img *north_image)
{
	if (east_image)
	{
		if (east_image->ptr)
			mlx_destroy_image(mlx, east_image->ptr);
		free(east_image);
	}
	if (west_image)
	{
		if (west_image->ptr)
			mlx_destroy_image(mlx, west_image->ptr);
		free(west_image);
	}
	if (north_image)
	{
		if (north_image->ptr)
			mlx_destroy_image(mlx, north_image->ptr);
		free(north_image);
	}
}

t_img	*load_image_from_file(void *mlx, char *path)
{
	t_img	*image;
	int		width;
	int		height;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	image->ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!image->ptr)
	{
		free(image);
		return (NULL);
	}
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->size_l, &image->endian);
	if (!image->data)
	{
		free(image);
		return (NULL);
	}
	return (image);
}

bool	parse_textures(t_map_vars map_vars, t_map *map)
{
	(void)map;
	if (!check_texture(map_vars))
	{
		debug("Error\ncheck_texture failed\n");
		return (false);
	}
	map->east_texture = load_image_from_file(game()->mlx, map_vars.east);
	if (!map->east_texture)
		return (false);
	map->west_texture = load_image_from_file(game()->mlx, map_vars.west);
	if (!map->west_texture)
		return (free_image_once(game()->mlx,  map->east_texture), false);
	map->north_texture = load_image_from_file(game()->mlx, map_vars.north);
	if (!map->north_texture)
		return (free_image_twice(game()->mlx,  map->west_texture, map->east_texture), false);
	map->south_texture = load_image_from_file(game()->mlx, map_vars.south);
	if (!map->south_texture)
		return (free_image_thrice(game()->mlx,  map->north_texture, map->west_texture, map->east_texture), false);
	
	// if (map->west_texture = load_image_from_file(mlx, map_vars.west) == NULL)
	// 	return (free_image_once(game()->mlx,  map->east_texture), false);
	// if (map->north_texture = load_image_from_file(mlx, map_vars.north) == NULL)
	// 	return (free_image_twice(game()->mlx,  map->west_texture, map->east_texture), false);
	// if (map->south_texture = load_image_from_file(mlx, map_vars.south) == NULL)
	// 	return (free_image_thrice(game()->mlx,  map->north_texture, map->west_texture, map->east_texture), false);
	return (true);
}
