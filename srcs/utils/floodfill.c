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

bool	is_floor_walkable(char c)
{
	if (c == '0')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

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
