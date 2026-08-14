
#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"

# define FOV 1.047
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define W_MSG "Let's get cub3D!"

# define N_TEXTURE 0
# define S_TEXTURE 1
# define W_TEXTURE 2
# define E_TEXTURE 3

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

typedef struct s_game {
	char		*textures[4];

	uint32_t	ceiling;
	uint32_t	floor;

	t_map		*map;

	void		*mlx;
	void		*win;
}	t_game;



t_game	*game();

// void	load_map(void);
void	destroy_cub3d(int status);

# include "handlers.h"

#endif /* CUB3D_H */
