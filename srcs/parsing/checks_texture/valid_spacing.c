/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_spacing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:42:47 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/27 17:56:01 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	invalid_space(char **raw_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (raw_map[i])
	{
		j = 0;
		skip_spaces(raw_map[i], &j);
		if (new_line(raw_map, &i, &j))
			continue ;
		if (is_map_line(raw_map[i], j))
			break ;
		while (raw_map[i][j] && raw_map[i][j] != ' '
				&& raw_map[i][j] != '\t' 
				&& raw_map[i][j] != '\n')
			j++;
		if (raw_map[i][j] != ' ')
			return (false);
		while (raw_map[i][j] == ' ')
			j++;
		if (raw_map[i][j] == '\t' || raw_map[i][j] == '\n')
			return (false);
		i++;
	}
	return (true);
}

// ↑
// | Before finishing the checks for raw map


// | After finishing the checks for raw map
// ↓
bool	check_invalid_spacing(char *map_vars)
{
	int	i;
	
	i = 0;
	while (map_vars[i])
	{
		if (map_vars[i] == ' ')
		{
			debug("Error\nspace inside value '%s'\n", map_vars);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_spacing(t_map_vars map_vars)
{
	if (!check_invalid_spacing(map_vars.east))
		return (false);
	if (!check_invalid_spacing(map_vars.south))
		return (false);
	if (!check_invalid_spacing(map_vars.west))
		return (false);
	if (!check_invalid_spacing(map_vars.north))
		return (false);
	return (true);
}
