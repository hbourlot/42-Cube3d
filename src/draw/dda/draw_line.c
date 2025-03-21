/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:05:59 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/19 22:55:01 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_line(void *game, t_matrix *se_points, int x0, int y0)
{
	int			steps;
	float		x_inc;
	float		y_inc;
	int			i;
	int			color;
	t_cube3d	*cube;

	steps = dda_steps(dda_dx(se_points), dda_dy(se_points));
	cube = (t_cube3d *)game;
	x_inc = dda_dx(se_points) / (float)steps;
	y_inc = dda_dy(se_points) / (float)steps;
	i = 0;
	color = create_rgb(0, 155, 120, 0);
	while (i <= steps)
	{
		mlx_pixel_put(cube->mlx_ptr, cube->win_ptr, round(x0), round(y0), color);
		x0 += x_inc;
		y0 += y_inc;
		i++;
	}
}
