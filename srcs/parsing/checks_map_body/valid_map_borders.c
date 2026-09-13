/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/09/13 15:41:42 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	touches_void(char **map_body, int x, int y)
{
	if (x == 0 || y == 0)
		return (true);
	if (x == map()->size.x - 1 || y == map()->size.y - 1)
		return (true);
	if (map_body[y][x - 1] == ' ' || map_body[y][x + 1] == ' ')
		return (true);
	if (map_body[y - 1][x] == ' ' || map_body[y + 1][x] == ' ')
		return (true);
	if (map_body[y - 1][x - 1] == ' ' || map_body[y - 1][x + 1] == ' ')
		return (true);
	if (map_body[y + 1][x - 1] == ' ' || map_body[y + 1][x + 1] == ' ')
		return (true);
	return (false);
}

bool	valid_map_borders(char **map_body)
{
	int	x;
	int	y;

	y = 0;
	while (y < map()->size.y)
	{
		x = 0;
		while (x < map()->size.x)
		{
			if (is_floor_walkable(map_body[y][x])
				&& touches_void(map_body, x, y))
			{
				ft_error(ERR_MAP_OPEN);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
