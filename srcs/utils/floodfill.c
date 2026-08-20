/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:24:53 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/20 17:21:47 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_floor_walkable(char c)
{
	if (c == '0')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

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
