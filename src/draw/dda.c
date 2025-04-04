/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:42 by joralves          #+#    #+#             */
/*   Updated: 2025/04/04 13:30:02 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ray_lines(t_cub3d *game, t_dda *dda, float x0, float y0);
void	render_walls(t_cub3d *game, t_raycast *raycast, int color);
t_img	*get_texture(t_cub3d *game, t_raycast *raycast);
int		get_texture_color(t_img *tex, int x, int y);

// void	dda_set_step(t_dda *dda, float x0, float y0)
// {
// 	if (dda->dir_x < 0)
// 	{
// 		dda->step_x = -1;
// 		dda->initial_x = x0 - dda->grid_x * TILE_SIZE;
// 	}
// 	else
// 	{
// 		dda->step_x = 1;
// 		dda->initial_x = (dda->grid_x + 1) * TILE_SIZE - x0;
// 	}
// 	if (dda->dir_y < 0)
// 	{
// 		dda->step_y = -1;
// 		dda->initial_y = y0 - dda->grid_y * TILE_SIZE;
// 	}
// 	else
// 	{
// 		dda->step_y = 1;
// 		dda->initial_y = (dda->grid_y + 1) * TILE_SIZE - y0;
// 	}
// }

// void	init_dda(t_dda *dda, float x0, float y0, float angle)
// {
// 	dda->grid_x = (int)(x0 / TILE_SIZE);
// 	dda->grid_y = (int)(y0 / TILE_SIZE);
// 	dda->dir_x = cos(angle);
// 	dda->dir_y = -sin(angle);
// 	if (dda->dir_x == 0)
// 		dda->dir_x = EPSILON;
// 	if (dda->dir_y == 0)
// 		dda->dir_y = EPSILON;
// 	dda->sx_norm = sqrt(1 + (dda->dir_y / dda->dir_x) * (dda->dir_y
// 				/ dda->dir_x));
// 	dda->sy_norm = sqrt(1 + (dda->dir_x / dda->dir_y) * (dda->dir_x
// 				/ dda->dir_y));
// 	dda->sx = TILE_SIZE * dda->sx_norm;
// 	dda->sy = TILE_SIZE * dda->sy_norm;
// 	dda_set_step(dda, x0, y0);
// 	dda->acum_x = dda->initial_x * dda->sx_norm;
// 	dda->acum_y = dda->initial_y * dda->sy_norm;
// 	dda->counter_x = 0;
// 	dda->counter_y = 0;
// }

// t_dda	dda(t_cub3d *game, float x0, float y0, float angle)
// {
// 	t_dda	dda;

// 	dda.grid_int = game->map->map_world;
// 	init_dda(&dda, x0, y0, angle);
// 	while (dda.grid_int[dda.grid_y][dda.grid_x] == 0)
// 	{
// 		if (dda.acum_x <= dda.acum_y)
// 		{
// 			dda.grid_x += dda.step_x;
// 			dda.dist = dda.acum_x;
// 			dda.acum_x += dda.sx;
// 			dda.hitside = 1;
// 			dda.counter_x++;
// 		}
// 		else
// 		{
// 			dda.grid_y += dda.step_y;
// 			dda.dist = dda.acum_y;
// 			dda.acum_y = dda.acum_y + dda.sy;
// 			dda.hitside = 0;
// 			dda.counter_y++;
// 		}
// 		if (dda.grid_x < 0 || dda.grid_y < 0 || dda.grid_x >= game->map->width
// 			|| dda.grid_y >= game->map->height)
// 			break ;
// 	}
// 	return (dda);
// }

// void	cast_render_raycast(t_cub3d *game)
// {
// 	t_raycast	r;
// 	t_player	*p;
// 	t_img		*tex;
// 	int			x;
// 	int			color;
// 	double		ray_angle;
// 	float		hit_x;
// 	float		hit_y;
// 	float		wallX;
// 	int			tex_x;
// 	int			tex_y;
// 	float		step;
// 	float		tex_pos;

// 	p = &game->player;
// 	x = 0;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		ray_angle = p->angle + FOV / 2 - (x * FOV / SCREEN_WIDTH);
// 		r.dda = dda(game, p->x, p->y, ray_angle);
// 		r.p_dist = r.dda.dist * cos(ray_angle - p->angle);
// 		r.wall_h = (int)(SCREEN_HEIGHT / r.p_dist);
// 		r.draw_start = SCREEN_HEIGHT / 2 - r.wall_h / 2;
// 		if (r.draw_start < 0)
// 			r.draw_start = 0;
// 		r.draw_end = r.wall_h / 2 + SCREEN_HEIGHT / 2;
// 		if (r.draw_end >= SCREEN_HEIGHT)
// 			r.draw_end = SCREEN_HEIGHT - 1;
// 		tex = get_texture(game, &r);
// 		hit_x = p->x + r.dda.dist * r.dda.dir_x;
// 		hit_y = p->y + r.dda.dist * r.dda.dir_y;
// 		if (r.dda.hitside == 1)
// 			wallX = hit_y - r.dda.grid_y /* * TILE_SIZE */;
// 		else
// 			wallX = hit_x - r.dda.grid_x /* * TILE_SIZE */;
// 		wallX -= floor(wallX);
// 		printf("wallX %d \n", wallX);
// 		// if ((r.dda.hitside == 1 && r.dda.step_x == -1) || (r.dda.hitside == 0
// 		// 	&& r.dda.step_y == -1))
// 		// wallX = TILE_SIZE - wallX;
// 		tex_x = (int)(wallX * tex->width);
// 		tex_x = tex_x % tex->width;
// 		// Calcular paso y posición inicial de la textura
// 		step = (float)tex->height / r.wall_h;
// 		tex_pos = (r.draw_start - SCREEN_HEIGHT / 2 + r.wall_h / 2) * step;
// 		// Ajustar para recorte vertical
// 		if (r.draw_start < 0)
// 			tex_pos += -r.draw_start * step;
// 		// Dibujar la columna
// 		for (int y = r.draw_start; y < r.draw_end; y++)
// 		{
// 			tex_y = (int)tex_pos % tex->height;
// 			color = get_texture_color(tex, tex_x, tex_y);
// 			my_mlx_pixel_put(game, x, y, color);
// 			tex_pos += step;
// 		}
// 		x++;
// 	}
// }


int	get_texture_color(t_img *tex, int x, int y)
{
	int	color;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0x000000);
	color = *(int *)(tex->addr + (y * tex->size_line) + (x * (tex->bpp / 8)));
	return (color);
}

t_img	*get_texture(t_cub3d *game, t_raycast *raycast)
{
	t_img	*tex;

	if (raycast->dda.hitside == 0)
	{
		if (raycast->dda.dir_x > 0)
			tex = game->sprites->we;
		else
			tex = game->sprites->ea;
	}
	else
	{
		if (raycast->dda.dir_y > 0)
			tex = game->sprites->no;
		else
			tex = game->sprites->so;
	}
	return (tex);
}

// void	draw_ray_lines(t_cub3d *game, t_dda *dda, float x0, float y0)
// {
// 	// draw_line(game, x0, y0, x0 + dda->initialX * dda->stepX + TILE_SIZE
// 	// 	* (dda->counterX - 1) * dda->stepX, y0, 0x80CC80);
// 	// draw_line(game, x0, y0, x0, y0 + dda->initialY * dda->stepY + TILE_SIZE
// 	// 	* (dda->counterY - 1) * dda->stepY, 0xCC8080);
// 	draw_line(game, x0, y0, x0 + dda->initial_x * dda->step_x + TILE_SIZE
// 		* (dda->counter_x - 1) * dda->step_x, y0 + dda->initial_y * dda->step_y
// 		+ TILE_SIZE * (dda->counter_y - 1) * dda->step_y, 0x8080CC);
// }

// void	render_walls(t_cub3d *game, t_raycast *raycast, int color)
// {
// 	int x;
// 	int y;

// 	x = raycast->x_start;
// 	while (x < raycast->x_end)
// 	{
// 		y = 0;
// 		while (y < raycast->wall_height)
// 		{
// 			raycast->screen_y = raycast->draw_start + y;
// 			if (raycast->screen_y >= 0 && raycast->screen_y < GAME_HEIGHT)
// 				my_mlx_pixel_put(game, x, raycast->screen_y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }