/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:42 by joralves          #+#    #+#             */
/*   Updated: 2025/04/04 17:15:26 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_set_step(t_dda *dda, float x0, float y0)
{
	if (dda->dir_x < 0)
	{
		dda->step_x = -1;
		dda->initial_x = x0 - dda->grid_x * TILE_SIZE;
	}
	else
	{
		dda->step_x = 1;
		dda->initial_x = (dda->grid_x + 1) * TILE_SIZE - x0;
	}
	if (dda->dir_y < 0)
	{
		dda->step_y = -1;
		dda->initial_y = y0 - dda->grid_y * TILE_SIZE;
	}
	else
	{
		dda->step_y = 1;
		dda->initial_y = (dda->grid_y + 1) * TILE_SIZE - y0;
	}
}

void	init_dda(t_dda *dda, float x0, float y0, float angle)
{
	dda->grid_x = (int)(x0 / TILE_SIZE);
	dda->grid_y = (int)(y0 / TILE_SIZE);
	dda->dir_x = cos(angle);
	dda->dir_y = -sin(angle);
	if (dda->dir_x == 0)
		dda->dir_x = EPSILON;
	if (dda->dir_y == 0)
		dda->dir_y = EPSILON;
	dda->sx_norm = sqrt(1 + (dda->dir_y / dda->dir_x) * (dda->dir_y
				/ dda->dir_x));
	dda->sy_norm = sqrt(1 + (dda->dir_x / dda->dir_y) * (dda->dir_x
				/ dda->dir_y));
	dda->sx = TILE_SIZE * dda->sx_norm;
	dda->sy = TILE_SIZE * dda->sy_norm;
	dda_set_step(dda, x0, y0);
	dda->acum_x = dda->initial_x * dda->sx_norm;
	dda->acum_y = dda->initial_y * dda->sy_norm;
	dda->counter_x = 0;
	dda->counter_y = 0;
}

t_dda	dda(t_cub3d *game, float x0, float y0, float angle)
{
	t_dda	dda;

	dda.grid_int = game->map->map_world;
	init_dda(&dda, x0, y0, angle);
	while (dda.grid_int[dda.grid_y][dda.grid_x] == 0)
	{
		if (dda.acum_x <= dda.acum_y)
		{
			dda.grid_x += dda.step_x;
			dda.dist = dda.acum_x;
			dda.acum_x += dda.sx;
			dda.hitside = 1;
			dda.counter_x++;
		}
		else
		{
			dda.grid_y += dda.step_y;
			dda.dist = dda.acum_y;
			dda.acum_y = dda.acum_y + dda.sy;
			dda.hitside = 0;
			dda.counter_y++;
		}
		if (dda.grid_x < 0 || dda.grid_y < 0 || dda.grid_x >= game->map->width
			|| dda.grid_y >= game->map->height)
			break ;
	}
	return (dda);
}
