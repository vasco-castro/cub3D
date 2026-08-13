/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:16 by biphuyal          #+#    #+#             */
/*   Updated: 2026/05/19 15:33:12 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_map_data(t_map *map)
{
	if (!map)
		return ;
	if (map->map)
		ft_tabfree(map->map);
	free(map);
}

static size_t	count_lines(int fd)
{
	size_t	count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

static char	**fill_lines(int fd, char **lines, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
		{
			ft_tabfree(lines);
			return (NULL);
		}
		i++;
	}
	lines[i] = NULL;
	return (lines);
}

char	**read_map(const char *filename)
{
	char	**lines;
	int		fd;
	size_t	line_count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_count = count_lines(fd);
	close(fd);
	lines = ft_calloc(line_count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(lines), NULL);
	if (!fill_lines(fd, lines, line_count))
		return (close(fd), NULL);
	close(fd);
	return (lines);
}
