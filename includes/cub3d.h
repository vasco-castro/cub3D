
#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>

# include "libft.h"
# include "mlx.h"

# include "handlers.h"

# define W_MSG "Let's get cub3D!"
// # define W_WIDTH 720
// # define W_HEIGHT 480
# define W_WIDTH 1280
# define W_HEIGHT 720
// # define W_WIDTH 1920
// # define W_HEIGHT 1080
# define FOV 1.047

# define MINIMAP true
# define MINIMAP_SCALE 8
# define MINIMAP_SCALE_PERCENTAGE 25
# define MINIMAP_POS MINIMAP_UL
# define MINIMAP_RADIUS 5

typedef enum e_minimap
{
	MINIMAP_UL,
	MINIMAP_LL,
	MINIMAP_UR,
	MINIMAP_LR,
}	t_minimap;

typedef struct s_image
{
	void	*img;
	char	*addr; // address
	int		w; // width
	int		h; // height
	int		bpp; // bits per pixel
	int		line; //line lenght (size)
	int		endian;
}		t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_image		screen;
}	t_game;

typedef struct s_map
{
	t_image			north_texture;
	t_image			south_texture;
	t_image			east_texture;
	t_image			west_texture;

	char			**map;
	t_point			size;

	int			minimap_scale;

	uint32_t	floor;
	uint32_t	ceiling;

}	t_map;

typedef struct s_player
{
	t_dpoint	pos;
	t_dpoint	dir;
	double		angle;
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
}	t_keys;

t_game		*game(void);
t_map		*map(void);
t_player	*player(void);
t_keys		*keys(void);

void		destroy_cub3d(int status);

# include "rendering.h"

#endif /* CUB3D_H */
