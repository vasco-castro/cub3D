/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/10 12:01:54 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// static void clear_parse_allocation(t_map *result, char **map_body, t_map_vars map_vars)
// {
// 	(free(result), ft_tabfree(map_body), free_map_vars(NULL, &map_vars));
// }



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
	if (!check_dup_inv_vars(raw_map))
		return (NULL);
	map_vars = store_map_variables(raw_map);
	map_body = store_map_body(raw_map);
	ft_tabfree(raw_map);
	if (!parse_textures(map_vars, result) || !parse_colors(map_vars, result))
		return (clear_parse_allocation(result, map_body, map_vars), NULL);
	// if (!parse_map_body(map_body))
	// 	return (clear_parse_allocation(result, map_body, map_vars), NULL);
	// result->map = map_body;
	return (result);
}
