/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/14 01:35:44 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw(t_cub3d *game)
{
	render(game, &game->player);
	draw_map2d(game, game->map);
	return (0);
}

int	game_loop(t_cub3d *game)
{
	mouse_handler(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_loop_hook(game->mlx_ptr, draw, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
