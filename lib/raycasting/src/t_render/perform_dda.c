/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:41:48 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/26 15:44:46 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void print_dda_debug(t_render *render_s)
{
    printf("DDA Step: Map Position (%d, %d), Side: %d, Hit: %d\n",
           render_s->map_x, render_s->map_y, render_s->side, render_s->hit);
}

void perform_dda(t_render *render_s, char **map_world)
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
        // if (worldMap[render_s->map_y][render_s->map_x] > 0) // !USE: world map
        if (worldMap[render_s->map_x][render_s->map_y] > 0) // !USE: world map
            render_s->hit = 1;
        // if (map_world[render_s->map_y][render_s->map_x] == '1')
            // render_s->hit = 1;
        // print_dda_debug(render_s);
    }
}
