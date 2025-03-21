/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:47:00 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/19 22:56:41 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_render	*init_render(t_cube3d *game, int pos_x, int pos_y)
{
	t_render *render_s;

	render_s = get_render();

	render_s->pos_x = pos_x;
	render_s->pos_y = pos_y;	
	render_s->dir_x = 1;
	render_s->dir_y = 0;
	render_s->plane_x = FOV_X;
	render_s->plane_y = FOV_Y;
	render_s->render = render;
	render_s->draw_line = draw_line;
	render_s->game = game;
	return (render_s);
}
