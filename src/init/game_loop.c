/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 13:36:07 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_line(t_cub3d *game, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
		y++;
	}
	return ;
}

int draw(t_cub3d *game)
{
    render(SCREEN_WIDTH, SCREEN_HEIGHT, game->map->map_world);
}


int	game_loop(t_cub3d *game)
{

    game->render = init_render(game, game->player->pos_x, game->player->pos_y);
	// generate_textures(game->render);
	generate_textures(game->render, game->render->mlx_ptr);

	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
    mlx_loop_hook(game->mlx_ptr, draw, game);
	mlx_loop(game->mlx_ptr);
	return 0;
}
