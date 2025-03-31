/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:58:32 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 14:27:03 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void texture_calculation(t_render *render_s, int x)
{
    double step;
    double tex_pos;
    int y;
    int tex_y;
    int color;
    char *dst;

    render_s->tex_num = worldMap[render_s->map_x][render_s->map_y] - 1;
    
    if (render_s->side == 0)
        render_s->wall_x = render_s->pos_y + render_s->perp_wall_dist * render_s->ray_dir_y;
    else
        render_s->wall_x = render_s->pos_x + render_s->perp_wall_dist * render_s->ray_dir_x;
    
    render_s->wall_x -= floor(render_s->wall_x);
    render_s->tex_x = (int)(render_s->wall_x * (double)tex_width);

    if (render_s->side == 0 && render_s->ray_dir_x > 0)
        render_s->tex_x = tex_width - render_s->tex_x - 1;
    if (render_s->side == 1 && render_s->ray_dir_y < 0)
        render_s->tex_x = tex_width - render_s->tex_x - 1;

    step = 1.0 * tex_height / render_s->line_height;
    tex_pos = (render_s->draw_start - SCREEN_HEIGHT / 2 + render_s->line_height / 2) * step;

    y = render_s->draw_start;
    while (y < render_s->draw_end)
    {
        tex_y = (int)tex_pos & (tex_height - 1);
        tex_pos += step;

        // color = ((int)(render_s->texture[render_s->tex_num][tex_height * tex_y + render_s->tex_x].x) << 16) |
        //         ((int)(render_s->texture[render_s->tex_num][tex_height * tex_y + render_s->tex_x].y) << 8) |
        //         ((int)(render_s->texture[render_s->tex_num][tex_height * tex_y + render_s->tex_x].z));

        // color = * (int * )(texture->addr + (tex_y * texture->size_line + tex_x *  (texture->bpp / 8)));
        
        color = *(int *)(render_s->texture[render_s->tex_num]->addr + (tex_y *  render_s->texture[render_s->tex_num]->size_line + render_s->tex_x * (render_s->texture[render_s->tex_num]->bpp / 8)));
        // printf("color: %d\n", color);
        // color = render_s->texture[render_s->tex_num][tex_height * tex_y + render_s->tex_x];
        if (render_s->side == 1)
            color = (color >> 1) & 8355711;

        render_s->buffer[y][x] = color;
		// dst = (char *)render_s->img_ptr + (y * render_s->size_line + render_s->tex_x * (render_s->bpp / 8));
		// *(int32_t *)dst = color;
        y++;
    }
}