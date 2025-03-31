/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:05:59 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 12:45:01 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_color()
{
	t_render	*render_s;
    int    		color;
	
	render_s = get_render();

    switch (worldMap[render_s->map_x][render_s->map_y])
    {
    case 1:
        color = create_rgb(0, 255, 0, 0);       
        break;
    case 2:
        color = create_rgb(0, 0, 255, 0);
        break;
    case 3:
        color = create_rgb(0, 0, 0, 255);
        break;
    case 4:
        color = create_rgb(0, 255, 255, 255);
        break;
    default:
        color = create_rgb(0, 255, 255, 0); // yellow
        break;
    }
	return (color);
}

static int	dda_dx(t_matrix *se_points)
{
	return (se_points->m[0][1] - se_points->m[0][0]);
}

static int dda_dy(t_matrix *se_points)
{
	return (se_points->m[1][1] - se_points->m[1][0]);
}

static int	dda_steps(int delta_x, int delta_y)
{
	if (abs(delta_x) > abs(delta_y))
		return (abs(delta_x));
	return (abs(delta_y));
}

void draw_line(t_render *render_s, t_matrix *se_points, int x0, int y0)
{
	int			steps;
	float		x_inc;
	float		y_inc;
	int			i;
	int			color;

	steps = dda_steps(dda_dx(se_points), dda_dy(se_points));
	x_inc = dda_dx(se_points) / (float)steps;
	y_inc = dda_dy(se_points) / (float)steps;
	i = 0;
	color = create_rgb(0, 155, 120, 0);
	while (i <= steps)
	{
		// mlx_pixel_put(render_s->mlx_ptr, render_s->win_ptr, x0, y0, set_color());

		
		put_pixel_to_image(render_s->img, x0, y0, render_s->buffer[y0][x0]);
		// mlx_pixel_put(cube->mlx_ptr, cube->win_ptr, round(x0), round(y0), color);
		x0 += x_inc;
		y0 += y_inc;
		i++;
	}
	mlx_put_image_to_window(render_s->mlx_ptr, render_s->win_ptr, render_s->img->img_ptr, 0, 0);
}
