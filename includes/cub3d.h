/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:03:27 by vsoares-          #+#    #+#             */
/*   Updated: 2026/09/13 17:03:27 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>

# include "libft.h"
# include "mlx.h"

# include "handlers.h"
# include "rendering.h"

/*
 * Error messages, printed through ft_error(), which puts "Error\n" before
 * them and a newline after. Some take printf arguments, noted beside them.
 */
# define ERR_ARGC "Invalid number of arguments.\nUsage: %s <map.cub>" // argv[0]
# define ERR_MAP_EXT "Invalid file. Expected a .cub file."
# define ERR_READ_MAP "failed to read map file '%s'" // filename
# define ERR_INVALID_ID "invalid identifier on line %d" // line number
# define ERR_DUP_ID "duplicate '%s' identifier on line %d" // key, line number
# define ERR_KEY_SPACING "invalid spacing between key and value"
# define ERR_BODY_START "map body line must start with '1'"
# define ERR_BODY_CHAR "invalid character inside map body"
# define ERR_MISSING_NO "missing NO texture variable"
# define ERR_MISSING_SO "missing SO texture variable"
# define ERR_MISSING_WE "missing WE texture variable"
# define ERR_MISSING_EA "missing EA texture variable"
# define ERR_MISSING_F "missing floor color variable"
# define ERR_MISSING_C "missing ceiling color variable"
# define ERR_TEX_SPACE "space inside value '%s'" // texture path
# define ERR_TEX_EXT "texture '%s' must be a .xpm file" // texture path
# define ERR_TEX_OPEN "cannot open texture '%s': %s" // texture path, strerror
# define ERR_TEX_LOAD "texture '%s' is not a valid xpm image" // texture path
# define ERR_COLOR_COMMAS "color must contain exactly two commas"
# define ERR_FLOOR_MISSING "Not all values present in the floor colors"
# define ERR_CEIL_MISSING "Not all values present in the ceiling colors"
# define ERR_FLOOR_CHAR "Invalid character in the floor's value"
# define ERR_CEIL_CHAR "Invalid character in the ceiling's value"
# define ERR_FLOOR_RANGE "floor color values must be between 0 and 255"
# define ERR_CEIL_RANGE "ceiling color values must be between 0 and 255"
# define ERR_PLAYER "map needs to have exactly one player"
# define ERR_MAP_OPEN "map is not closed"
# define ERR_MAP_COPY "failed to copy map for validation"
# define ERR_MLX_INIT "failed to initialise minilibx"
# define ERR_MLX_WIN "failed to create window"
# define ERR_MLX_IMAGE "failed to create screen image"

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_image		screen;
}	t_game;

typedef struct s_map
{
	uint32_t	floor;
	uint32_t	ceiling;

	t_image		north_texture;
	t_image		south_texture;
	t_image		east_texture;
	t_image		west_texture;

	char		**map;
	t_point		size;

}	t_map;

/**
 * @brief The player, and the camera they carry.
 *
 * pos   position in map tiles, fractional
 * angle heading in radians, growing clockwise on screen
 * dir   unit vector the player faces, straight out of angle
 * plane camera plane: perpendicular to dir and tan(HALF_FOV) long, so its
 *       two tips are the edges of the field of view
 *
 * dir points where the player actually walks, with no sign to undo, and
 * update_player_vectors is the only thing that writes either vector.
 */
typedef struct s_player
{
	t_dpoint	pos;
	double		angle;
	t_dpoint	dir;
	t_dpoint	plane;
}	t_player;

typedef struct s_keys
{
	bool	forward;
	bool	backward;
	bool	left;
	bool	right;
	bool	rot_left;
	bool	rot_right;
	bool	run;
	bool	minimap;
}	t_keys;

t_game		*game(void);
t_map		*map(void);
t_player	*player(void);
t_keys		*keys(void);
t_minimap	*minimap(void);

void		destroy_cub3d(int status);

bool		is_floor_walkable(char c);
bool		is_wall(int x, int y);

#endif /* CUB3D_H */
