#include "cub3d.h"


void	print_ddainfo(t_dda dda_info)
{
	printf("Hit: %s Wall at distance: %.2f, grid: (%d, %d)\n",
		dda_info.hitside == 0 ? "Horizontal" : "Vertical", dda_info.dist,
		dda_info.grid_x, dda_info.grid_y);
}
