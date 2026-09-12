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
	if (x < 0 || !copy_map[x])
		return (false);
	if (y < 0 || !copy_map[x][y] || copy_map[x][y] == '\n')
		return (false);
	if (copy_map[x][y] == ' ')
		return (false);
	if (copy_map[x][y] == '1' || copy_map[x][y] == 'P')
		return (true);
	if (!is_floor_walkable(copy_map[x][y]))
		return (false);
	copy_map[x][y] = 'P';
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
		debug("Error\nfailed to copy map for validation\n");
		return (false);
	}
	if (!flood_fill(copy, (int)player()->pos.y, (int)player()->pos.x))
	{
		ft_tabfree(copy);
		debug("Error\nmap is not closed\n");
		return (false);
	}
	ft_tabfree(copy);
	return (true);
}
