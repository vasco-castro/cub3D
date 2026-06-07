
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
# define MINIMAP_SCALE_PERCENTAGE 15
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

typedef struct s_map
{
	char		*n_texture;
	char		*w_texture;
	char		*s_texture;
	char		*e_texture;

	uint32_t	ceiling;
	uint32_t	floor;

	char		**map;
	int			minimap_scale;

	t_point		size;
}	t_map;

typedef struct s_player
{
	t_point	coord;
	t_point	angle;
}	t_player;

t_game		*game(void);
t_map		*map(void);
t_player	*player(void);

void		parse_map(const char *filename);
void		destroy_cub3d(int status);

#endif /* CUB3D_H */
