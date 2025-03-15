/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/15 16:15:44 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_vertical_line(t_cube3d *game, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
		y++;
	}
	return ;
}

void	render(t_cube3d *game, t_dda *dda)
{
	int	x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;

	int		map_x;
	int		map_y;

	int		hit;
	int		side;

	int		step_x;
	int		step_y;

	float	side_dist_x;
	float	side_dist_y;

	float	perp_wall_dist;
	
	int		line_height;
	int		draw_start;
	int		draw_end;
	int  color;


	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1; // x-coordinate in camera space
		ray_dir_x = dda->dir_x + dda->plane_x * camera_x;
		ray_dir_y = dda->dir_y + dda->plane_y * camera_x;
		
		map_x = dda->pos_x;
		map_y = dda->pos_y;
		
		delta_dist_x = (ray_dir_x == 0) ? (float)INT64_MAX : fabs(1 / ray_dir_x); // TODO 1e30 -> INT_MAX
		delta_dist_y = (ray_dir_y == 0) ? (float)INT64_MAX : fabs(1 / ray_dir_y);

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (dda->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - dda->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (dda->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - dda->pos_y) * delta_dist_y;
		}
		
		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			printf("map_x: %d | map_y: %d\n", map_x, map_y);
			if (game->map->map_array[map_y][map_x] > 0)
			{
				
				hit = 1; 
			}
		}
		
		// Calculate distance project on camera direction (Euclidean distance would give fisheye effect)
        perp_wall_dist = (side == 0) ? (side_dist_x - delta_dist_x) : (side_dist_y - delta_dist_y);
        
        line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
        draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_start < 0)
		draw_start = 0;
        draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
		color = (game->map->map_array[map_y][map_x] == 1) ? create_rgb(0, 255, 0, 0) : create_rgb(255, 255, 255, 0);
        // color = (game->map->map_array[map_x][map_y] == 1) ? create_rgb(0, 255, 0, 0) : create_rgb(255, 255, 255, 0);
		printf("HERE\n");
		if (side == 1)
            color /= 2;
        draw_vertical_line(game, x, draw_start, draw_end, color);
        x++;
    }

}



void	init_dda(t_cube3d *game, t_dda *dda)
{
	ft_memset(dda, 0, sizeof(t_dda));
	dda->pos_x = game->player->pos_x;
	dda->pos_y = game->player->pos_y;	
	dda->dir_x = 1;
	dda->dir_y = 0;
	dda->plane_x = FOV_X;
	dda->plane_y = FOV_Y;
}

int	game_loop(t_cube3d *game)
{
	t_dda	dda;
	
	init_dda(game, &dda);
	
	// render(game, &dda);

	// mlx_loop_hook()  
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_loop(game->mlx_ptr);
	return 0;
}
