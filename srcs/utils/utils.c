/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:53:31 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/16 16:53:43 by biphuyal         ###   ########.fr       */
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

/**
 * @brief Is the tile at (x, y) something a ray or the player cannot cross?
 *
 * Anything off the map counts as a wall, so a ray can never escape it.
 * The spawn tile still holds its N/S/E/W letter, which is walkable floor.
 */
bool	is_wall(int x, int y)
{
	if (x < 0 || x >= map()->size.x || y < 0 || y >= map()->size.y)
		return (true);
	return (!is_floor_walkable(map()->map[y][x]));
}
