
#include "cub3d.h"

static void	render_bg(void)
{
	int	x;
	int	y;

	return ;
	debug("Rendering background...\n");
	x = 0;
	y = 0;
	while (W_HEIGHT / 2 >= y)
		put_line_x(x, y++, W_WIDTH, map()->ceiling);
	while (W_HEIGHT >= y)
		put_line_x(x, y++, W_WIDTH, map()->floor);
}

static void	render_walls(void)
{
	//debug("Rendering walls...\n");
}

void	render(void)
{
	int	minimap_low_pos;
	int	minimap_right_pos;

	render_bg();
	render_walls();
	if (MINIMAP)
	{
		minimap_low_pos = W_HEIGHT - (map()->size.y * map()->minimap_scale);
		minimap_right_pos = W_WIDTH - (map()->size.x * map()->minimap_scale);
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
