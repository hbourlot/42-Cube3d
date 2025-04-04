/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:59:35 by joralves          #+#    #+#             */
/*   Updated: 2025/04/04 22:32:38 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rotation(t_player *player)
{
	if (player->dir == 'N')
		player->angle = P2;
	if (player->dir == 'E')
		player->angle = 0;
	if (player->dir == 'W')
		player->angle = PI;
	if (player->dir == 'S')
		player->angle = P3;
}

void	init_player(t_cub3d *game, int x, int y)
{
	t_player	*player;

	player = &game->player;
	locate_spawn_point(&game->player, game->map);

	init_rotation(player);
	player->x = player->x * TILE_SIZE + TILE_SIZE / 2;
	player->y = player->y * TILE_SIZE + TILE_SIZE / 2;
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
}

void	normalize_angle(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
}
