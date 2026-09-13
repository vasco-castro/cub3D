/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:56:56 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/20 17:21:44 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	flood_fill(char **copy_map, int x, int y)
{
	if (y < 0 || !copy_map[y])
		return (false);
	if (x < 0 || !copy_map[y][x] || copy_map[y][x] == '\n')
		return (false);
	if (copy_map[y][x] == ' ')
		return (false);
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'P')
		return (true);
	if (!is_floor_walkable(copy_map[y][x]))
		return (false);
	copy_map[y][x] = 'P';
	if (!flood_fill(copy_map, x + 1, y))
		return (false);
	if (!flood_fill(copy_map, x - 1, y))
		return (false);
	if (!flood_fill(copy_map, x, y + 1))
		return (false);
	if (!flood_fill(copy_map, x, y - 1))
		return (false);
	return (true);
}

bool	valid_map(char **map)
{
	char	**copy;

	copy = ft_tabcpy(map);
	if (!copy)
	{
		ft_error(ERR_MAP_COPY);
		return (false);
	}
	if (!flood_fill(copy, (int)player()->pos.x, (int)player()->pos.y))
	{
		ft_tabfree(copy);
		ft_error(ERR_MAP_OPEN);
		return (false);
	}
	ft_tabfree(copy);
	return (true);
}
