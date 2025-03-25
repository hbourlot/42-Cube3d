/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:49:09 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/25 17:51:56 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

// void calculate_wall_height(t_render *render_s, int screen_height)
// {
//     render_s->perp_wall_dist = (render_s->side == 0) 
//         ? (render_s->side_dist_x - render_s->delta_dist_x) 
//         : (render_s->side_dist_y - render_s->delta_dist_y);
//     render_s->line_height = (int)(screen_height / render_s->perp_wall_dist);
//     render_s->draw_start = -render_s->line_height / 2 + screen_height / 2;
//     if (render_s->draw_start < 0)
//         render_s->draw_start = 0;
//     render_s->draw_end = render_s->line_height / 2 + screen_height / 2;
//     if (render_s->draw_end >= screen_height)
//         render_s->draw_end = screen_height - 1;

// }

void calculate_wall_height(t_render *render_s, int screen_height)
{
    if (render_s->side == 0)
        render_s->perp_wall_dist = render_s->side_dist_x - render_s->delta_dist_x;
    else
        render_s->perp_wall_dist = render_s->side_dist_y - render_s->delta_dist_y;    
    render_s->line_height = (int)(screen_height / render_s->perp_wall_dist);
    render_s->draw_start = -render_s->line_height / 2 + screen_height / 2;
    if (render_s->draw_start < 0)
        render_s->draw_start = 0;
        
    render_s->draw_end = render_s->line_height / 2 + screen_height / 2;

    if (render_s->draw_end >= screen_height)
        render_s->draw_end = screen_height - 1;

}
