/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_vars_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:17:11 by biphuyal          #+#    #+#             */
/*   Updated: 2026/09/14 14:55:51 by biphuyal         ###   ########.fr       */
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
		ft_error(ERR_BODY_START);
		return (false);
	}
	while (line[i] && line[i] != '\n')
	{
		if (!is_map_char(line[i]))
		{
			ft_error(ERR_BODY_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	check_map_line(char *line, bool *map_started, bool *map_ended)
{
	size_t	j;

	j = 0;
	skip_spaces(line, &j);
	if (!line[j] || line[j] == '\n')
	{
		if (*map_started)
			*map_ended = true;
		return (true);
	}
	if (*map_ended)
		return (ft_error(ERR_MAP_OPEN), false);
	if (line[j] == '1')
		*map_started = true;
	if (*map_started && !is_map_body_line(line))
		return (false);
	return (true);
}

bool	check_vars_in_out_map_body(char **raw_map)
{
	size_t	i;
	bool	map_started;
	bool	map_ended;

	i = 0;
	map_started = false;
	map_ended = false;
	while (raw_map[i])
	{
		if (!check_map_line(raw_map[i], &map_started, &map_ended))
			return (false);
		i++;
	}
	return (true);
}
