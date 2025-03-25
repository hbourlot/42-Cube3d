/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:31:15 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/25 12:00:50 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void print_dda_debug(t_render *render_s)
{
    printf("DDA Step: Map Position (%d, %d), Side: %d, Hit: %d\n",
           render_s->map_x, render_s->map_y, render_s->side, render_s->hit);
}

static void print_initialize_ray_debug(t_render *render_s, int x)
{
    printf("\n-- INITIALIZE RAY DEBUG FOR COLUMN %d --\n", x);
    printf("Camera X: %f\n", render_s->camera_x);
    printf("Ray Direction: (%f, %f)\n", render_s->ray_dir_x, render_s->ray_dir_y);
    printf("Map Position: (%d, %d)\n", render_s->map_x, render_s->map_y);
    printf("Delta Distance: (%f, %f)\n", render_s->delta_dist_x, render_s->delta_dist_y);
}

static void print_step_debug(t_render *render_s)
{
    printf("\n-- STEP & SIDE DIST DEBUG --\n");
    printf("Step: (%d, %d)\n", render_s->step_x, render_s->step_y);
    printf("Side Distance: (%f, %f)\n", render_s->side_dist_x, render_s->side_dist_y);
}

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

static void initialize_ray(t_render *render_s, int screen_width, int x)
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

static void set_step_and_side_dist(t_render *render_s)
{
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
    // print_step_debug(render_s);
}

static void perform_dda(t_render *render_s, char **map_world)
{
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
        if (map_world[render_s->map_y][render_s->map_x] == '1')
            render_s->hit = 1;
        // print_dda_debug(render_s);
    }
}

void calculate_wall_height(t_render *render_s, int screen_height)
{
    render_s->perp_wall_dist = (render_s->side == 0) 
        ? (render_s->side_dist_x - render_s->delta_dist_x) 
        : (render_s->side_dist_y - render_s->delta_dist_y);
    render_s->line_height = (int)(screen_height / render_s->perp_wall_dist);
    render_s->draw_start = -render_s->line_height / 2 + screen_height / 2;
    if (render_s->draw_start < 0)
        render_s->draw_start = 0;
    render_s->draw_end = render_s->line_height / 2 + screen_height / 2;
    if (render_s->draw_end >= screen_height)
        render_s->draw_end = screen_height - 1;

}

void update_timing(t_render *render_s)
{
    render_s->old_time = render_s->time;
    render_s->time = get_ticks(); 
    
    double frameTime = (render_s->time - render_s->old_time) / 1000.0;

    render_s->move_speed = frameTime * 15.0;  
    render_s->rot_speed = frameTime * 8.0;
}

void render(int screen_width, int screen_height, char **map_world)
{
    t_render *render_s = get_render();
    int x = 0;
    
    update_timing(render_s);
    render_s->wall_points = (t_matrix){0};
    while (x < screen_width)
    {
        initialize_ray(render_s, screen_width, x);
        set_step_and_side_dist(render_s);
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
