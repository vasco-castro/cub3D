#ifndef RENDERING_H
# define RENDERING_H

# include "libft.h"

# define W_MSG "Let's get cub3D!"
// # define W_WIDTH 720
// # define W_HEIGHT 480
# define W_WIDTH 1280
# define W_HEIGHT 720
// # define W_WIDTH 1920
// # define W_HEIGHT 1080
// # define W_WIDTH 2560
// # define W_HEIGHT 1440

// Half the FOV, in radians: the angle between the direction and each edge ray.
# define HALF_FOV 0.57595865315 //(FOV * M_PI / 360.0)

// Debug shades, one per wall face, until the textures go on.
# define WALL_COLOR_NORTH 0x00BF4040
# define WALL_COLOR_SOUTH 0x0040BF40
# define WALL_COLOR_EAST 0x004040BF
# define WALL_COLOR_WEST 0x00BFBF40

// Share of the window height the minimap box takes up.
# define MINIMAP_SCALE_PERCENTAGE 25
# define MINIMAP_POS MINIMAP_UL
// How many tiles the minimap shows either side of the player.
# define MINIMAP_RADIUS 5
// Length of the view cone drawn on the minimap, in map tiles.
# define MINIMAP_CONE_TILES 3
// Radius of the player dot, in map tiles. Also where the cone starts.
# define MINIMAP_PLAYER_RADIUS 0.25

# define MINIMAP_FLOOR_COLOR 0x00CCCCCC
# define MINIMAP_WALL_COLOR 0x00333333
# define MINIMAP_PLAYER_COLOR 0x006300BF
# define MINIMAP_CONE_COLOR 0x00B48CE8

// Which corner of the window the minimap sits in.
typedef enum e_minimap_pos
{
	MINIMAP_UL,
	MINIMAP_LL,
	MINIMAP_UR,
	MINIMAP_LR,
}	t_minimap_pos;

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

/**
 * @brief Everything the minimap needs to place itself on screen.
 *
 * origin top-left corner of the box, in window pixels
 * scale  window pixels per map tile
 * side   width and height of the box, in window pixels
 *
 * All three are settled once by minimap_init and read from there on, so no
 * drawing function has to be told where the minimap lives.
 */
typedef struct s_minimap
{
	t_point	origin;
	int		scale;
	int		side;
}	t_minimap;

/**
 * @brief One ray of the DDA walk, from the player out to the wall it hits.
 *
 * dir    direction the ray travels, in map units
 * delta  distance along the ray between two grid lines of each axis
 * side   running distance to the next grid line of each axis
 * map    tile the ray is standing on right now
 * step   +1 or -1 per axis, whichever way the ray is heading
 * dist   perpendicular distance to the wall, once the walk is over
 * x_side true if the ray came in through a vertical grid line, so the wall
 *        it hit faces east or west
 */
typedef struct s_ray
{
	t_dpoint	dir;
	t_dpoint	delta;
	t_dpoint	side;
	t_point		map;
	t_point		step;
	double		dist;
	bool		x_side;
}	t_ray;

void			render(void);

t_dpoint		camera_ray(double camera_x);
t_ray			cast_ray(t_dpoint dir);

void			minimap_init(void);
void			render_minimap(void);
void			render_minimap_player(void);
t_point			minimap_pos(t_dpoint world);

t_image			create_image(int w, int h);
void			destroy_image(t_image *img);
void			clear_image(t_image *img, uint32_t color);
uint32_t		get_px(t_image *img, int x, int y);
void			put_px(t_image *img, int x, int y, uint32_t color);
void			display_image(t_image *img, int x, int y);

void			put_pixel(int x, int y, uint32_t color);
void			put_line(t_point a, t_point b, uint32_t color);
void			put_square(int x, int y, int size, uint32_t color);
void			put_star(int x, int y, int size, uint32_t color);
void			put_circle(int cx, int cy, int radius, uint32_t color);

void			update_player_vectors(void);

#endif /* RENDERING_H */
