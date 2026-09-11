/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_vars_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:17:11 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/21 17:41:02 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

static bool	is_map_body_line(char *line)
{
	size_t	i;

	i = 0;
	skip_spaces(line, &i);
	if (line[i] != '1')
	{
		debug("Error\nmap body line must start with '1'\n");
		return (false);
	}
	while (line[i] && line[i] != '\n')
	{
		if (!is_map_char(line[i]))
		{
			debug("Error\ninvalid character inside map body\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_vars_in_out_map_body(char **raw_map)
{
	size_t	i;
	size_t	j;
	bool	map_started;

	i = 0;
	map_started = false;
	while (raw_map[i])
	{
		j = 0;
		skip_spaces(raw_map[i], &j);
		if (!raw_map[i][j] || raw_map[i][j] == '\n')
		{
			i++;
			continue ;
		}
		if (raw_map[i][j] == '1')
			map_started = true;
		if (map_started && !is_map_body_line(raw_map[i]))
			return (false);
		i++;
	}
	return (true);
}
