
#include "cub3d.h"

static void	render_bg(void)
{
	int	x;
	int	y;

	return ;
	debug("Rendering background...\n");
	y = 0;
	while (W_HEIGHT / 2 >= y++)
	{
		x = 0;
		while (W_WIDTH >= x++)
			mlx_pixel_put(game()->mlx, game()->win, x, y, map()->ceiling);
	}
	while (W_HEIGHT >= y++)
	{
		x = 0;
		while (W_WIDTH >= x++)
			mlx_pixel_put(game()->mlx, game()->win, x, y, map()->floor);
	}
}

static void	render_walls(void)
{
	debug("Rendering walls...\n");
}

static void	render_minimap(int col, int row)
{
	int	x;
	int	y;
	int	pos_col;
	int	pos_row;

	debug("Rendering minimap...\n");
	x = 0;
	while (x < map()->size.x && map()->map[x])
	{
		y = 0;
		while (y < map()->size.y && map()->map[x][y])
		{
			pos_col = (y * map()->minimap_scale) + col;
			pos_row = (x * map()->minimap_scale) + row;
			debug("%d - %d\n", pos_col, pos_row);
			if (map()->map[x][y] == '0')
				put_square(pos_col, pos_row, map()->minimap_scale, 0x00fcba03);
			else
				put_square(pos_col, pos_row, map()->minimap_scale, 0x00bf5600);
			if (player()->coord.x == y && player()->coord.y == x)
				put_star(pos_col, pos_row, map()->minimap_scale, 0x006300bf);
			y++;
		}
		x++;
	}
}

void	render(void)
{
	render_bg();
	render_walls();
	if (MINIMAP)
	{
		int minimap_low_pos = W_HEIGHT - (map()->size.y * map()->minimap_scale);
		int minimap_right_pos = W_WIDTH - (map()->size.x * map()->minimap_scale);
		if (MINIMAP_POS == MINIMAP_UL)
			render_minimap(0, 0);
		else if (MINIMAP_POS == MINIMAP_LL)
			render_minimap(0, minimap_low_pos);
		else if (MINIMAP_POS == MINIMAP_UR)
			render_minimap(minimap_right_pos, 0);
		else if (MINIMAP_POS == MINIMAP_LR)
			render_minimap(minimap_right_pos, minimap_low_pos);
		else
			render_minimap(0, 0);
	}
}
