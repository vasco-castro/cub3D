/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:57:37 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/19 20:10:42 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <math.h>

static bool	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player_dir(char angle)
{
	if (angle == 'N')
		player()->angle = M_PI_2;
	else if (angle == 'S')
		player()->angle = 3 * M_PI_2;
	else if (angle == 'E')
		player()->angle = M_PI;
	else if (angle == 'W')
		player()->angle = 0;
	update_player_vectors();
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
				set_player_dir(map_body[y][x]);
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (false);
	return (true);
}
