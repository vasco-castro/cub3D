/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/09/14 18:56:22 by biphuyal         ###   ########.fr       */
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
 * @brief Whether `filename` is a directory. Opening one for reading works
 * and reads as zero lines, so it would otherwise pass for an empty file.
 */
static bool	is_directory(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY | O_DIRECTORY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	parse_map(const char *filename)
{
	char		**raw_map;
	t_map_vars	map_vars;

	if (is_directory(filename))
		return (ft_error(ERR_MAP_IS_DIR, filename), false);
	raw_map = read_map(filename);
	if (!raw_map)
		return (ft_error(ERR_READ_MAP, filename), false);
	if (!raw_map[0])
		return (ft_error(ERR_EMPTY_FILE, filename), ft_tabfree(raw_map), false);
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
