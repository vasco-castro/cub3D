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

bool	parse_map(const char *filename)
{
	char		**raw_map;
	t_map_vars	map_vars;

	raw_map = read_map(filename);
	if (!raw_map)
	{
		debug("Error\nfailed to read map file '%s'\n", filename);
		return (false);
	}
	if (!checks_for_raw_map(raw_map))
		return (false);
	map_vars = store_map_variables(raw_map);
	if (debug_mode())
		print_map_vars(map_vars);
	map()->map = store_map_body(raw_map);
	ft_tabfree(raw_map);
	if (!parse_textures(map_vars) || !parse_colors(map_vars))
		return (ft_tabfree(map()->map), free_map_vars(&map_vars), false);
	// if (!parse_map_body(map()->map))
	// 	return (ft_tabfree(map()->map), free_map_vars(&map_vars), false);
	return (free_map_vars(&map_vars), true);
}
