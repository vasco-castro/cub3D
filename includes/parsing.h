/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:08 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/19 15:46:10 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include <errno.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"
# include "cub3d.h"

typedef struct s_map_vars
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*floor;
	char			*ceiling;
}	t_map_vars;

bool		parse_map(const char *filename);
t_map_vars	store_map_variables(char **raw_map);
bool		is_space(char c);
void		skip_spaces(char *line, size_t *j);
bool		valid_map(char **map);
bool		flood_fill(char **copy_map, int x, int y);
bool		is_map_line(char *line, size_t j);
bool		valid_permisions(t_map_vars map_vars);
bool		valid_spacing(t_map_vars map_vars);
bool		valid_vars(t_map_vars map_vars);
bool		check_dup_inv_vars(char **raw_map);
bool		check_texture(t_map_vars map_vars);
void		parse_error_on_map(t_map *map);
char		**read_map(const char *filename);
void		parse_error(const char *filename);
char		**store_map_body(char **raw_map);
bool		parse_textures(t_map_vars map_vars);
bool		parse_colors(t_map_vars map_vars);
bool		parse_map_body(char **map_body);
void		free_images(void);
void		free_map_body(char **map_body);
void		free_map_vars(t_map_vars *map_vars);
void		print_map_vars(t_map_vars map_vars);
bool		check_vars_in_out_map_body(char **raw_map);
bool		valid_extentions(t_map_vars map_vars);
bool		invalid_space(char **raw_map);
bool		new_line(char **raw_map, size_t *i, size_t *j);
bool		checks_for_colors(t_map_vars map_vars);
bool		valid_chars(t_map_vars map_vars);
bool		three_values_exists(t_map_vars map_vars);
bool		three_values_only(t_map_vars map_vars);
bool		check_floors(t_map_vars map_vars, int i);
bool		check_ceilings(t_map_vars map_vars, int i);
bool		valid_range(t_map_vars map_vars);
bool		valid_separator(t_map_vars map_vars);
bool		trim_spaces(t_map_vars map_vars);
bool		checks_for_map(char **map_body);
void		printf_double_pointer(char **args);
bool		valid_player(char **map_body);

#endif
