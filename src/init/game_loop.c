/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/19 16:03:10 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_vertical_line(t_cube3d *game, int x, int start, int end, int color)
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

int draw(t_cube3d *game)
{
    get_render()->render(SCREEN_WIDTH, SCREEN_HEIGHT, game->map->map_array);
}


int	game_loop(t_cube3d *game)
{
    t_render	*render;

    render = init_render(game, game->player->pos_x, game->player->pos_y);
	
    // game->render = &render_struct;
    // init_render(game->render, game->player->pos_x,  game->player->pos_y);

	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
    mlx_loop_hook(game->mlx_ptr, draw, game);
	mlx_loop(game->mlx_ptr);
	return 0;
}


// for (int i = 0; game->map->map_array[i]; i++)
// {
//     for (int j = 0; game->map->map_array[i][j]; j++)
//         printf("%c,", game->map->map_array[i][j]);
//     printf("\n");
// }