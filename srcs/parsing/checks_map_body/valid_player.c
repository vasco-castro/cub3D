/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:57:37 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/17 19:42:47 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	set_player_dir(char direction)
{
	if (direction == 'N')
		player()->dir = (t_dpoint){0, -1};
	else if (direction == 'S')
		player()->dir = (t_dpoint){0, 1};
	else if (direction == 'E')
		player()->dir = (t_dpoint){1, 0};
	else if (direction == 'W')
		player()->dir = (t_dpoint){-1, 0};
}

bool	valid_player(char **map_body)
{
	size_t	x;
	size_t	y;
	int		count;

	count = 0;
	y = 0;
	while (map_body && map_body[y])
	{
		x = 0;
		while (map_body[y][x] && map_body[y][x] != '\n')
		{
			if (is_player_char(map_body[y][x]))
			{
				count++;
				player()->pos = (t_dpoint){x + 0.5, y + 0.5};
				set_player_dir(map_body[x][y]);
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (debug("Error\nmap must contain exactly one player\n"), false);
	return (true);
}
