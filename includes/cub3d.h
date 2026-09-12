#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>

# include "libft.h"
# include "mlx.h"

# include "handlers.h"
# include "rendering.h"

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
