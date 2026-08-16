/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	char_in_set(char c, char *set)
{
	if (!set)
		return (false);
	while (*set)
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}

static bool	is_outside_map(t_floodfill *fill, t_point pos)
{
	if (pos.y < 0 || pos.x < 0)
		return (true);
	if (!fill->map[pos.y])
		return (true);
	if (!fill->map[pos.y][pos.x] || fill->map[pos.y][pos.x] == '\n')
		return (true);
	return (false);
}

bool	floodfill(t_floodfill *fill, t_point pos)
{
	char	cell;

	if (is_outside_map(fill, pos))
		return (!fill->check_closed);
	cell = fill->map[pos.y][pos.x];
	if (char_in_set(cell, fill->invalid))
		return (false);
	if (!char_in_set(cell, fill->walkable))
		return (true);
	if (char_in_set(cell, fill->target))
		fill->target_count++;
	fill->map[pos.y][pos.x] = fill->mark;
	if (!floodfill(fill, (t_point){pos.x + 1, pos.y}))
		return (false);
	if (!floodfill(fill, (t_point){pos.x - 1, pos.y}))
		return (false);
	if (!floodfill(fill, (t_point){pos.x, pos.y + 1}))
		return (false);
	if (!floodfill(fill, (t_point){pos.x, pos.y - 1}))
		return (false);
	return (true);
}
