/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:29:34 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/28 14:43:59 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void    texture_calculation(t_render *render_s)
{
    render_s->tex_num = worldMap[render_s->map_x][render_s->map_y] - 1;
    
    if (render_s->side == 0)
        render_s->wall_x = render_s->pos_y + render_s->perp_wall_dist * render_s->ray_dir_y;
    else
        render_s->wall_x = render_s->pos_x + render_s->perp_wall_dist * render_s->ray_dir_x;
    
    render_s->wall_x -= floor(render_s->wall_x);

    render_s->tex_x = (int)(render_s->wall_x * (double)texWidth);
    
    if (render_s->side == 0 && render_s->ray_dir_x > 0)
        render_s->tex_x =  texWidth - render_s->tex_x - 1;
    if (render_s->side == 1 && render_s->ray_dir_y < 0)
        render_s->tex_x =  texWidth - render_s->tex_x - 1;

}