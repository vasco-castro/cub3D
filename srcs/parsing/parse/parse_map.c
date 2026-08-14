/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/14 17:27:09 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	clear_parse_allocation(t_map *result, char **map_body,
	t_map_vars map_vars)
{
	free_map_data(result);
	free_map_body(NULL, map_body);
	free_map_vars(NULL, &map_vars);
}

bool	checks_for_raw_map(char **raw_map)
{
	if (!check_dup_inv_vars(raw_map))
	{
		debug("Error\nduplicate or invalid map variable\n");
		ft_tabfree(raw_map);
		return (false);
	}
	if (!invalid_space(raw_map))
	{
		debug("Error\ninvalid spacing between key and value\n");
		ft_tabfree(raw_map);
		return (false);
	}
	if (!check_vars_in_out_map_body(raw_map))
	{
		debug("Error\nnon-map line found after map started\n");
		ft_tabfree(raw_map);
		return (false);
	}
	return (true);
}

t_map	*parse_map(const char *filename)
{
	t_map		*result;
	char		**raw_map;
	char		**map_body;
	t_map_vars	map_vars;

	result = ft_calloc(1, sizeof(t_map));
	if (!result)
	{
		debug("Error\nfailed to allocate t_map\n");
		return (NULL);
	}
	raw_map = read_map(filename);
	if (!raw_map)
	{
		debug("Error\nfailed to read map file '%s'\n", filename);
		return (free(result), NULL);
	}
	if (!checks_for_raw_map(raw_map))
		return (free(result), NULL);
	map_vars = store_map_variables(raw_map);
	if (debug_mode())
		print_map_vars(map_vars);
	map_body = store_map_body(raw_map);
	ft_tabfree(raw_map);
	if (!parse_textures(map_vars, result) || !parse_colors(map_vars, result))
	{
		return (clear_parse_allocation(result, map_body, map_vars), NULL);
	}
	// if (!parse_map_body(map_body))
	// 	return (clear_parse_allocation(result, map_body, map_vars), NULL);
	result->map = map_body;
	free_map_vars(NULL, &map_vars);
	return (result);
}
