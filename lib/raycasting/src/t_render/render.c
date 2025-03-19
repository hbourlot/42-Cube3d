/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:31:15 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/19 16:02:27 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void render(int screen_width, int screen_height, char **map_array)
{
    t_render    *render_s;

    render_s = get_render();
    int x;

    x = 0;
    render_s->wall_points = (t_matrix){0};
    while (x < screen_width)
    {
        render_s->camera_x = 2 * x / (double)screen_width - 1;
        render_s->ray_dir_x = render_s->dir_x + render_s->plane_x * render_s->camera_x;
        render_s->ray_dir_y = render_s->dir_y + render_s->plane_y * render_s->camera_x;

        render_s->map_x = (int)render_s->pos_x;
        render_s->map_y = (int)render_s->pos_y;

        render_s->delta_dist_x = (render_s->ray_dir_x == 0) ? 1e30 : fabs(1 / render_s->ray_dir_x);
        render_s->delta_dist_y = (render_s->ray_dir_y == 0) ? 1e30 : fabs(1 / render_s->ray_dir_y);
        // render_s->delta_dist_x = fabs(1 / render_s->ray_dir_x);
        // render_s->delta_dist_y = fabs(1 / render_s->ray_dir_y);

        if (render_s->ray_dir_x < 0)
        {
            render_s->step_x = -1;
            render_s->side_dist_x = (render_s->pos_x - render_s->map_x) * render_s->delta_dist_x;
        }
        else
        {
            render_s->step_x = 1;
            render_s->side_dist_x = (render_s->map_x + 1.0 - render_s->pos_x) * render_s->delta_dist_x;
        }
        if (render_s->ray_dir_y < 0)
        {
            render_s->step_y = -1;
            render_s->side_dist_y = (render_s->pos_y - render_s->map_y) * render_s->delta_dist_y;
        }
        else
        {
            render_s->step_y = 1;
            render_s->side_dist_y = (render_s->map_y + 1.0 - render_s->pos_y) * render_s->delta_dist_y;
        }

        render_s->hit = 0;
        while (render_s->hit == 0)
        {
            if (render_s->side_dist_x < render_s->side_dist_y)
            {
                render_s->side_dist_x += render_s->delta_dist_x;
                render_s->map_x += render_s->step_x;
                render_s->side = 0;
            }
            else
            {
                render_s->side_dist_y += render_s->delta_dist_y;
                render_s->map_y += render_s->step_y;
                render_s->side = 1;
            }
            if (map_array[render_s->map_y][render_s->map_x] == '1')
                render_s->hit = 1;
        }
        render_s->perp_wall_dist = (render_s->side == 0) ? (render_s->side_dist_x - render_s->delta_dist_x) : (render_s->side_dist_y - render_s->delta_dist_y);
        render_s->line_height = (int)(screen_height / render_s->perp_wall_dist);
        render_s->draw_start = -render_s->line_height / 2 + screen_height / 2;
        if (render_s->draw_start < 0)
            render_s->draw_start = 0;
        render_s->draw_end = render_s->line_height / 2 + screen_height / 2;
        if (render_s->draw_end >= screen_height)
            render_s->draw_end = screen_height - 1;

        // int color = (map_array[render_s->map_y][render_s->map_x] == 1) ? create_rgb(255, 0, 0, 0) : create_rgb(255, 255, 255, 0);
        // if (render_s->side == 1)
        //     color /= 2;

        render_s->wall_points.m[0][0] = x;
        render_s->wall_points.m[1][0] = render_s->draw_start;
        render_s->wall_points.m[0][1] = x;
        render_s->wall_points.m[1][1] = render_s->draw_end;
        render_s->dda_algorithm(render_s->game, &render_s->wall_points, x, render_s->draw_start);
		// draw_vertical_line(game, x, render_s->draw_start, render_s->draw_end, color);
        x++;
    }
}
