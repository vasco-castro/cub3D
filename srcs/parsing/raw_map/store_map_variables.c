/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:49:15 by biphuyal          #+#    #+#             */
/*   Updated: 2026/06/22 18:56:03 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	match_key(char *line, size_t *j, const char *key)
{
	size_t	start;
	size_t	len;

	start = *j;
	while (line[*j] && !is_space(line[*j]) && line[*j] != '\n')
		(*j)++;
	len = *j - start;
	if (len != ft_strlen(key))
		return (false);
	if (ft_strncmp(&line[start], key, len) != 0)
		return (false);
	return (true);
}

static char	*copy_value(char *line, size_t j)
{
	size_t	end;

	skip_spaces(line, &j);
	if (!line[j] || line[j] == '\n')
		return (NULL);
	end = j;
	while (line[end] && line[end] != '\n')
		end++;
	while (end > j && is_space(line[end - 1]))
		end--;
	return (ft_substr(line, j, end - j));
}

static char	*get_vars_from_raw_map(char **raw_map, const char *key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (raw_map[i])
	{
		j = 0;
		skip_spaces(raw_map[i], &j);
		if (!raw_map[i][j] || raw_map[i][j] == '\n')
		{
			i++;
			continue ;
		}
		if (is_map_line(raw_map[i], j))
			return (NULL);
		if (match_key(raw_map[i], &j, key))
			return (copy_value(raw_map[i], j));
		i++;
	}
	return (NULL);
}

t_map_vars	store_map_variables(char **raw_map)
{
	return ((t_map_vars){
		.north=get_vars_from_raw_map(raw_map, "NO"),
		.south=get_vars_from_raw_map(raw_map, "SO"),
		.west=get_vars_from_raw_map(raw_map, "WE"),
		.east=get_vars_from_raw_map(raw_map, "EA"),
		.floor=get_vars_from_raw_map(raw_map, "F"),
		.ceiling=get_vars_from_raw_map(raw_map, "C")
	});
}
