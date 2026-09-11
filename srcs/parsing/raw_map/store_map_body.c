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

static size_t	get_map_width(char **raw_map, size_t start, size_t len)
{
	size_t	i;
	size_t	width;
	size_t	line_width;

	i = 0;
	width = 0;
	while (i < len)
	{
		line_width = ft_strlen(raw_map[start + i]);
		if (line_width && raw_map[start + i][line_width - 1] == '\n')
			line_width--;
		if (line_width > width)
			width = line_width;
		i++;
	}
	return (width);
}

static char	*copy_map_line(char *line, size_t width)
{
	char	*copy;
	size_t	line_width;

	copy = ft_calloc(width + 2, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memset(copy, ' ', width);
	copy[width] = '\n';
	line_width = ft_strlen(line);
	if (line_width && line[line_width - 1] == '\n')
		line_width--;
	ft_memcpy(copy, line, line_width);
	return (copy);
}

static char	**copy_map_body(char **raw_map, size_t start, size_t len)
{
	char	**map_body;
	size_t	i;
	size_t	width;

	width = get_map_width(raw_map, start, len);
	map_body = ft_calloc(len + 1, sizeof(char *));
	if (!map_body)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map_body[i] = copy_map_line(raw_map[start + i], width);
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
	size_t	j;

	start = 0;
	while (raw_map[start])
	{
		j = 0;
		skip_spaces(raw_map[start], &j);
		if (is_map_line(raw_map[start], j))
			break ;
		start++;
	}
	len = 0;
	while (raw_map[start + len] && is_map_body_line(raw_map[start + len]))
		len++;
	return (copy_map_body(raw_map, start, len));
}
