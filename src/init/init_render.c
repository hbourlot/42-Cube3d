/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:47:00 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/26 12:26:18 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

t_render	*init_render(t_cube3d *game, int pos_x, int pos_y)
{
	t_render *render_s;

	render_s = get_render();

	if (render_s->pos_x == 0)
	{
		render_s->pos_x = pos_x;
		render_s->pos_y = pos_y;
		
	}
	// init_location(render_s, game->player->dir);	
	render_s->dir_x = -1;
	render_s->dir_y = 0;
	render_s->plane_x = FOV_X;
	render_s->plane_y = FOV_Y;
	render_s->render = render;
	render_s->draw_line = draw_line;
	render_s->game = game;
	return (render_s);
}
