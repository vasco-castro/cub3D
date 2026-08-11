/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:51:15 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/10 12:01:54 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_var_id(char *line, size_t *j)
{
	size_t	start;
	size_t	len;

	skip_spaces(line, j);
	start = *j;
	while (line[*j] && !is_space(line[*j]) && line[*j] != '\n')
		(*j)++;
	len = *j - start;
	if (len == 2 && ft_strncmp(&line[start], "NO", 2) == 0)
		return (0);
	if (len == 2 && ft_strncmp(&line[start], "SO", 2) == 0)
		return (1);
	if (len == 2 && ft_strncmp(&line[start], "WE", 2) == 0)
		return (2);
	if (len == 2 && ft_strncmp(&line[start], "EA", 2) == 0)
		return (3);
	if (len == 1 && line[start] == 'F')
		return (4);
	if (len == 1 && line[start] == 'C')
		return (5);
	return (-1);
}

bool	new_line(char **raw_map, size_t *i, size_t *j)
{
	if (!raw_map[*i][*j] || raw_map[*i][*j] == '\n')
	{
		(*i)++;
		return (true);
	}
	else 
		return (false);
}

bool	check_dup_inv_vars(char **raw_map)
{
	int		seen[6];
	size_t	i;
	size_t	j;
	int		id;

	ft_bzero(seen, sizeof(seen));
	i = 0;
	while (raw_map[i])
	{
		j = 0;
		skip_spaces(raw_map[i], &j);
		if (new_line(raw_map, &i, &j))
			continue ;
		if (is_map_line(raw_map[i], j))
			break ;
		id = get_var_id(raw_map[i], &j);
		if (id == -1)
			return (false);
		seen[id]++;
		if (seen[id] > 1)
			return (false);
		i++;
	}
	return (true);
}
