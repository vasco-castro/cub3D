/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:24:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/06/08 21:47:54 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_map_body_line(char *line)
{
	size_t	j;

	j = 0;
	skip_spaces(line, &j);
	if (!line[j] || line[j] == '\n')
		return (true);
	return (is_map_line(line, j));
}

static size_t	find_map_start(char **raw_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (raw_map[i])
	{
		j = 0;
		skip_spaces(raw_map[i], &j);
		if (is_map_line(raw_map[i], j))
			return (i);
		i++;
	}
	return (i);
}

static char	**copy_map_body(char **raw_map, size_t start, size_t len)
{
	char	**map_body;
	size_t	i;

	map_body = ft_calloc(len + 1, sizeof(char *));
	if (!map_body)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map_body[i] = ft_strdup(raw_map[start + i]);
		if (!map_body[i])
			return (ft_tabfree(map_body), NULL);
		i++;
	}
	return (map_body);
}

char	**store_map_body(char **raw_map)
{
	size_t	start;
	size_t	len;

	start = find_map_start(raw_map);
	len = 0;
	while (raw_map[start + len] && is_map_body_line(raw_map[start + len]))
		len++;
	return (copy_map_body(raw_map, start, len));
}
