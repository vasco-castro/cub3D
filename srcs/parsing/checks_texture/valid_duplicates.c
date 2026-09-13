/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:51:15 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/19 19:44:38 by biphuyal         ###   ########.fr       */
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
	return (false);
}

/**
 * @brief Records the identifier on raw_map[i], printing an error if it is
 * unknown or was already seen. Line numbers in the errors start at 1.
 */
static bool	check_identifier(char **raw_map, size_t i, size_t j, int *seen)
{
	static const char	*keys[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int					id;

	id = get_var_id(raw_map[i], &j);
	if (id == -1)
		return (ft_error(ERR_INVALID_ID, (int)i + 1), false);
	seen[id]++;
	if (seen[id] > 1)
		return (ft_error(ERR_DUP_ID, keys[id], (int)i + 1), false);
	return (true);
}

bool	check_dup_inv_vars(char **raw_map)
{
	int		seen[6];
	size_t	i;
	size_t	j;

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
		if (!check_identifier(raw_map, i, j, seen))
			return (false);
		i++;
	}
	return (true);
}
