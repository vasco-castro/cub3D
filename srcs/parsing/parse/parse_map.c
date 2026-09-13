/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/21 20:54:46 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	store_map_size(char **map_body)
{
	size_t	width;
	size_t	height;
	size_t	line_width;

	width = 0;
	height = 0;
	while (map_body && map_body[height])
	{
		line_width = 0;
		while (map_body[height][line_width]
			&& map_body[height][line_width] != '\n')
			line_width++;
		if (line_width > width)
			width = line_width;
		height++;
	}
	map()->size = (t_point){width, height};
}

bool	checks_for_raw_map(char **raw_map)
{
	if (!check_dup_inv_vars(raw_map))
		return (ft_tabfree(raw_map), false);
	if (!invalid_space(raw_map))
	{
		ft_error(ERR_KEY_SPACING);
		return (ft_tabfree(raw_map), false);
	}
	if (!check_vars_in_out_map_body(raw_map))
		return (ft_tabfree(raw_map), false);
	return (true);
}

/**
 * @note Known issues, all printing a misleading error:
 * - An empty file, or a directory named *.cub, reads as zero lines and
 *   reports "missing NO texture variable".
 * - A file with no map, or store_map_body failing to allocate, reports
 *   "map needs to have exactly one player".
 */
bool	parse_map(const char *filename)
{
	char		**raw_map;
	t_map_vars	map_vars;

	raw_map = read_map(filename);
	if (!raw_map)
	{
		ft_error(ERR_READ_MAP, filename);
		return (false);
	}
	if (!checks_for_raw_map(raw_map))
		return (false);
	map_vars = store_map_variables(raw_map);
	map()->map = store_map_body(raw_map);
	ft_tabfree(raw_map);
	store_map_size(map()->map);
	if (!parse_textures(map_vars) || !parse_colors(map_vars))
		return (free_map_vars(&map_vars), false);
	if (!parse_map_body(map()->map))
		return (free_map_vars(&map_vars), false);
	return (free_map_vars(&map_vars), true);
}
