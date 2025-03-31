/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:44:08 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/25 17:07:15 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void print_initialize_ray_debug(t_render *render_s, int x)
{
    printf("\n-- INITIALIZE RAY DEBUG FOR COLUMN %d --\n", x);
    printf("Camera X: %f\n", render_s->camera_x);
    printf("Ray Direction: (%f, %f)\n", render_s->ray_dir_x, render_s->ray_dir_y);
    printf("Map Position: (%d, %d)\n", render_s->map_x, render_s->map_y);
    printf("Delta Distance: (%f, %f)\n", render_s->delta_dist_x, render_s->delta_dist_y);
}

void init_ray(t_render *render_s, int screen_width, int x)
{
    render_s->camera_x = 2 * x / (double)screen_width - 1;
    render_s->ray_dir_x = render_s->dir_x + render_s->plane_x * render_s->camera_x;
    render_s->ray_dir_y = render_s->dir_y + render_s->plane_y * render_s->camera_x;
    render_s->map_x = (int)render_s->pos_x;
    render_s->map_y = (int)render_s->pos_y;
    render_s->delta_dist_x = (render_s->ray_dir_x == 0) ? 1e30 : fabs(1 / render_s->ray_dir_x);
    render_s->delta_dist_y = (render_s->ray_dir_y == 0) ? 1e30 : fabs(1 / render_s->ray_dir_y);
    // print_initialize_ray_debug(render_s, x);
    // sleep(10);
}
