/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:31:15 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/25 15:51:49 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


static void print_debug(t_render *render_s, int x)
{
    printf("\n-- DEBUG INFO FOR COLUMN %d --\n", x);
    printf("Camera X: %f\n", render_s->camera_x);
    printf("Ray Direction: (%f, %f)\n", render_s->ray_dir_x, render_s->ray_dir_y);
    printf("Map Position: (%d, %d)\n", render_s->map_x, render_s->map_y);
    printf("Step: (%d, %d)\n", render_s->step_x, render_s->step_y);
    printf("Side Distance: (%f, %f)\n", render_s->side_dist_x, render_s->side_dist_y);
    printf("Delta Distance: (%f, %f)\n", render_s->delta_dist_x, render_s->delta_dist_y);
    printf("Hit: %d, Side: %d\n", render_s->hit, render_s->side);
    printf("Perp Wall Distance: %f\n", render_s->perp_wall_dist);
    printf("Draw Start-End: (%d, %d)\n", render_s->draw_start, render_s->draw_end);
    // sleep(4);
}

void render(int screen_width, int screen_height, char **map_world)
{
    t_render *render_s = get_render();
    int x = 0;
    
    update_timing(render_s);
    render_s->wall_points = (t_matrix){0};
    while (x < screen_width)
    {
        init_ray(render_s, screen_width, x);
        step_and_side_dist(render_s);
        perform_dda(render_s, map_world);
        calculate_wall_height(render_s, screen_height);
        // print_debug(render_s, x);

        render_s->wall_points.m[0][0] = x;
        render_s->wall_points.m[1][0] = render_s->draw_start;
        render_s->wall_points.m[0][1] = x;
        render_s->wall_points.m[1][1] = render_s->draw_end;
        render_s->draw_line(render_s->game, &render_s->wall_points, x, render_s->draw_start);
        x++;
    }
}
