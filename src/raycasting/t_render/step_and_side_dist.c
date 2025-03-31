/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_and_side_dist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:50:08 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/25 15:51:55 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void print_step_debug(t_render *render_s)
{
    printf("\n-- STEP & SIDE DIST DEBUG --\n");
    printf("Step: (%d, %d)\n", render_s->step_x, render_s->step_y);
    printf("Side Distance: (%f, %f)\n", render_s->side_dist_x, render_s->side_dist_y);
}

void step_and_side_dist(t_render *render_s)
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
