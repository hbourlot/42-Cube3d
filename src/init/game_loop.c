/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/18 11:40:08 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	dda_steps(int delta_x, int delta_y)
{
	if (abs(delta_x) > abs(delta_y))
		return (abs(delta_x));
	return (abs(delta_y));
}

int	dda_dx(t_matrix *se_points)
{
	return (se_points->m[0][1] - se_points->m[0][0]);
}

int dda_dy(t_matrix *se_points)
{
	return (se_points->m[1][1] - se_points->m[1][0]);
}
void dda(t_cube3d *game, t_matrix *se_points, int x0, int y0)
{
	int		steps;
	float	x_inc;
	float	y_inc;
	int		i;

	steps = dda_steps(dda_dx(se_points), dda_dy(se_points));

	x_inc = dda_dx(se_points) / (float)steps;
	y_inc = dda_dy(se_points) / (float)steps;
	i = 0;
	while (i <= steps)
	{
		int color = create_rgb(0, 255, 0, 0);
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, round(x0), round(y0), color);
		x0 += x_inc;
		y0 += y_inc;
		i++;
	}
}

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

void render(t_cube3d *game, t_dda *dda_s)
{
    int x;
    double camera_x;
    double ray_dir_x, ray_dir_y;
    double delta_dist_x, delta_dist_y;
    int map_x, map_y;
    int step_x, step_y;
    float side_dist_x, side_dist_y;
    int hit, side;
    float perp_wall_dist;
    int line_height, draw_start, draw_end;
    t_matrix wall_points;

    x = 0;
    while (x < SCREEN_WIDTH)
    {
        camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        ray_dir_x = dda_s->dir_x + dda_s->plane_x * camera_x;
        ray_dir_y = dda_s->dir_y + dda_s->plane_y * camera_x;

        map_x = (int)dda_s->pos_x;
        map_y = (int)dda_s->pos_y;

        delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
        delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (dda_s->pos_x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - dda_s->pos_x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (dda_s->pos_y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - dda_s->pos_y) * delta_dist_y;
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

            if (game->map->map_array[map_y][map_x] > 0)
                hit = 1;
        }

        perp_wall_dist = (side == 0) ? (side_dist_x - delta_dist_x) : (side_dist_y - delta_dist_y);
        line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
        draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_end >= SCREEN_HEIGHT)
            draw_end = SCREEN_HEIGHT - 1;

        int color = (game->map->map_array[map_y][map_x] == 1) ? create_rgb(255, 0, 0, 0) : create_rgb(255, 255, 255, 0);
        if (side == 1)
            color /= 2;

        wall_points.m[0][0] = x;
        wall_points.m[1][0] = draw_start;
        wall_points.m[0][1] = x;
        wall_points.m[1][1] = draw_end;
        dda(game, &wall_points, x, draw_start);
		// draw_vertical_line(game, x, draw_start, draw_end, color);
        x++;
    }
}

void	init_dda(t_cube3d *game, t_dda *dda)
{
	ft_memset(dda, 0, sizeof(t_dda));
	dda->pos_x = game->player->pos_x;
	dda->pos_y = game->player->pos_y;	
	dda->dir_x = 0;
	dda->dir_y = -1;
	dda->plane_x = FOV_X;
	dda->plane_y = FOV_Y;
	// printf("dda->pos_x: %f | dda->pos_y: %f\n", dda->pos_x, dda->pos_y);
}

int	game_loop(t_cube3d *game)
{
	t_dda	dda_struct;
	
	init_dda(game, &dda_struct);
	
	render(game, &dda_struct);

	// mlx_loop_hook()  
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_loop(game->mlx_ptr);
	return 0;
}
