
#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"

# include "handlers.h"
# include "rendering.h"

# define W_MSG "Let's get cub3D!"
// # define W_WIDTH 720
// # define W_HEIGHT 480
# define W_WIDTH 1280
# define W_HEIGHT 720
// # define W_WIDTH 1920
// # define W_HEIGHT 1080
# define FOV 1.047

# define MINIMAP true
// # define MINIMAP_SCALE 8
# define MINIMAP_SCALE_PERCENTAGE 25
# define MINIMAP_POS MINIMAP_UL

typedef enum e_minimap
{
	MINIMAP_UL = 1,
	MINIMAP_LL = 2,
	MINIMAP_UR = 3,
	MINIMAP_LR = 4,
}	t_minimap;

typedef struct s_game
{
	void		*mlx;
	void		*win;
}	t_game;

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
	t_img			north_texture;
	t_img			south_texture;
	t_img			east_texture;
	t_img			west_texture;

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
}	t_player;

t_game		*game(void);
t_map		*map(void);
t_player	*player(void);

void		destroy_cub3d(int status);

#endif /* CUB3D_H */
