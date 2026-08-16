/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/16 16:57:15 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

bool	valid_closed_map(char **map_body)
{
	t_floodfill	fill;
	size_t		y;
	size_t		x;

	fill = (t_floodfill){ft_tabcpy(map_body), "0NSEW", "\t", NULL,
		0, 'F', true};
	if (!fill.map)
		return (false);
	y = 0;
	while (fill.map[y])
	{
		x = 0;
		while (fill.map[y][x] && fill.map[y][x] != '\n')
		{
			if (is_walkable(fill.map[y][x])
				&& !floodfill(&fill, (t_point){x, y}))
				return (ft_tabfree(fill.map), false);
			x++;
		}
		y++;
	}
	return (ft_tabfree(fill.map), true);
}
