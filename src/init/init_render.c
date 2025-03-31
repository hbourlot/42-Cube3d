/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:47:00 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 13:27:37 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_location(t_render *render_s, char dir)
{

	if (dir == 'N')
	{
		render_s->dir_x = 0;
		render_s->dir_y = -1;
	}
	if (dir == 'S')
	{
		render_s->dir_x = 0;
		render_s->dir_y = 1;
	}
	if (dir == 'W')
	{
		render_s->dir_x = -1;
		render_s->dir_y = 0;
	}
	if (dir == 'E')
	{
		render_s->dir_x = 1;
		render_s->dir_y = 0;
	}
}

t_render	*init_render(t_cub3d *game, int pos_x, int pos_y)
{
	t_render *render_s;

	render_s = get_render();

	if (render_s->pos_x == 0)
	{
		render_s->pos_x = pos_x;
		render_s->pos_y = pos_y;
		render_s->pos_x = 22;
		render_s->pos_y = 12;
		
		
	}
	init_location(render_s, game->player->dir);	
	render_s->dir_x = -1;
	render_s->dir_y = 0;

	render_s->plane_x = FOV_X;
	render_s->plane_y = FOV_Y;
	render_s->mlx_ptr = game->mlx_ptr;
	render_s->win_ptr = game->win_ptr;

	// Fix in a function
	render_s->img = &game->img;
	render_s->mlx_get_data_addr = mlx_get_data_addr; // mlx func*
	render_s->mlx_xpm_file_to_image = mlx_xpm_file_to_image; // mlx func*
	// load_all_textures(render_s, render_s->mlx_ptr);
	render_s->img->addr = mlx_get_data_addr(render_s->img->img_ptr, &render_s->img->bpp, &render_s->img->size_line, &render_s->img->endian);
	return (render_s);
}
