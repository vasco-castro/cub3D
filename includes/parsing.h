/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:08 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/13 16:52:11 by biphuyal         ###   ########.fr       */
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

typedef struct s_img
{
	void	*ptr;
	void	*data;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img;

typedef struct s_map
{
	t_img			*north_texture;
	t_img			*south_texture;
	t_img			*east_texture;
	t_img			*west_texture;
	char			**map;
	t_point			size;
	unsigned int	floor;
	unsigned int	ceiling;
}	t_map;

typedef struct s_map_vars
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*floor;
	char			*ceiling;
}	t_map_vars;

void		free_map_data(t_map *map);
bool		is_space(char c);
void		skip_spaces(char *line, size_t *j);
bool		is_map_line(char *line, size_t j);
bool		valid_permisions(t_map_vars map_vars);
bool		valid_spacing(t_map_vars map_vars);
bool		valid_vars(t_map_vars map_vars);
bool		check_dup_inv_vars(char **raw_map);
bool		check_texture(t_map_vars map_vars);
void		parse_error_on_map(t_map *map);
char		**read_map(const char *filename);
t_map		*parse_map(const char *filename);
void		parse_error(const char *filename);
t_map_vars	store_map_variables(char **raw_map);
char		**store_map_body(char **raw_map);
bool		parse_textures(t_map_vars map_vars, t_map *map);
bool		parse_colors(t_map_vars map_vars, t_map *map);
bool		parse_map_body(char **map_body);
void		free_map_body(t_map *map, char **map_body);
void		free_map_vars(t_map *map, t_map_vars *map_vars);
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







#endif
