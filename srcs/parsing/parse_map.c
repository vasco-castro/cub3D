/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/06/08 22:42:58 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// static void clear_parse_allocation(t_map *result, char **map_body, t_map_vars map_vars)
// {
// 	(free(result), ft_tabfree(map_body), free_map_vars(NULL, &map_vars));
// }
/* 
void	print_map_vars(t_map_vars map_vars)
{
	printf("NO: %s\n", map_vars.north_texture_path
		? map_vars.north_texture_path : "(null)");
	printf("SO: %s\n", map_vars.south_texture_path
		? map_vars.south_texture_path : "(null)");
	printf("EA: %s\n", map_vars.east_texture_path
		? map_vars.east_texture_path : "(null)");
	printf("WE: %s\n", map_vars.west_texture_path
		? map_vars.west_texture_path : "(null)");
	printf("F: %s\n", map_vars.floor);
	printf("C: %s\n", map_vars.ceiling);
} */

t_map	*parse_map(const char *filename)
{
	t_map		*result;
	char		**raw_map;
	char		**map_body;
	t_map_vars	map_vars;

	result = ft_calloc(1, sizeof(t_map));
	if (!result)
		return (NULL);
	raw_map = read_map(filename);
	if (!raw_map)
		return (free(result), NULL);
	map_vars = store_map_variables(raw_map);
	map_body = store_map_body(raw_map);
	ft_tabfree(raw_map);
	// if (!parse_textures(map_vars, result) || !parse_colors(map_vars, result))
	// 	return (clear_parse_allocation(result, map_body, map_vars), NULL);
	// if (!parse_map_body(map_body))
	// 	return (clear_parse_allocation(result, map_body, map_vars), NULL);
	// result->map = map_body;
	return (result);
}
