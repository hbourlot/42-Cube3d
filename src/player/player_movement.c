/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:53:30 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 15:02:21 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player, int keycode, int signal)
{
	float	rot_speed;

	if (signal == KEY_SIGNAL)
		rot_speed = KEY_ROT_SPEED * 5;
	else if (signal == MOUSE_SIGNAL)
		rot_speed = MOUSE_ROT_SPEED * 1.5;
	if (keycode == XK_a || keycode == XK_Left)
		player->angle += rot_speed;
	if (keycode == XK_d || keycode == XK_Right)
		player->angle -= rot_speed;
	normalize_angle(&player->angle);
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
}

void	move_player(t_map *map, t_player *player, int keycode)
{
	float	new_x;
	float	new_y;

	new_x = player->x;
	new_y = player->y;
	if (keycode == XK_w || keycode == XK_Up)
	{
		new_x += player->pdx;
		new_y += player->pdy;
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		new_x -= player->pdx;
		new_y -= player->pdy;
	}
	check_collision(player, map, new_x, new_y);
}

void	mouse_handler(t_cub3d *game)
{
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, S_WIDTH / 2, S_HEIGHT / 2);
	game->mouse_x = S_WIDTH / 2;
	game->mouse_y = S_HEIGHT / 2;
	mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask, mouse_signal,
		game);
}
