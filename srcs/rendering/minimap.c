
#include "cub3d.h"

// Change x & y order to math an actual graph,
// accessing a double pointer is the one it should be reversed
void	render_minimap(int col, int row)
{
	int	x;
	int	y;
	int	pos_col;
	int	pos_row;

	//debug("Rendering minimap...\n");
	x = 0;
	while (x < map()->size.x && map()->map[x])
	{
		y = 0;
		while (y < map()->size.y && map()->map[x][y])
		{
			pos_col = (y * map()->minimap_scale) + col;
			pos_row = (x * map()->minimap_scale) + row;
			//debug("%d - %d\n", pos_col, pos_row);
			if (map()->map[x][y] == '0')
				put_square(pos_col, pos_row, map()->minimap_scale, 0x00fcba03);
			else
				put_square(pos_col, pos_row, map()->minimap_scale, 0x00bf5600);
			if ((int) player()->pos.x == y && (int) player()->pos.y == x)
				put_star(pos_col + (map()->minimap_scale / 4),
					pos_row + (map()->minimap_scale / 4),
					map()->minimap_scale / 2, 0x006300bf);
			y++;
		}
		x++;
	}
	mlx_string_put(game()->mlx, game()->win, x + 15, y + 15, 0xffffff, "test");
}
