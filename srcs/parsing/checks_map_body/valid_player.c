/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:46:08 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/16 16:26:09 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	store_player(char c, size_t x, size_t y)
{
	player()->pos.x = x + 0.5;
	player()->pos.y = y + 0.5;
	player()->dir.x = 0;
	player()->dir.y = 0;
	if (c == 'N')
		player()->dir.y = -1.5;
	else if (c == 'S')
		player()->dir.y = 1.5;
	else if (c == 'E')
		player()->dir.x = 1.5;
	else if (c == 'W')
		player()->dir.x = -1.5;
}

static bool	count_players(char **map_body, int *count)
{
	t_floodfill	fill;
	size_t		y;
	size_t		x;

	fill = (t_floodfill){ft_tabcpy(map_body), "01NSEW \t", NULL, "NSEW",
		0, 'F', false};
	if (!fill.map)
		return (false);
	y = 0;
	while (fill.map[y])
	{
		x = 0;
		while (fill.map[y][x] && fill.map[y][x] != '\n')
		{
			if (!floodfill(&fill, (t_point){x, y}))
				return (ft_tabfree(fill.map), false);
			x++;
		}
		y++;
	}
	*count = fill.target_count;
	return (ft_tabfree(fill.map), true);
}

static void	set_player_position(char **map_body)
{
	size_t		y;
	size_t		x;

	y = 0;
	while (map_body[y])
	{
		x = 0;
		while (map_body[y][x] && map_body[y][x] != '\n')
		{
			if (is_player(map_body[y][x]))
				store_player(map_body[y][x], x, y);
			x++;
		}
		y++;
	}
}

bool	valid_player(char **map_body)
{
	int	count;

	if (!map_body || !count_players(map_body, &count))
		return (false);
	if (count != 1)
		return (debug("Error\nmap must have exactly one player\n"), false);
	set_player_position(map_body);
	return (true);
}
