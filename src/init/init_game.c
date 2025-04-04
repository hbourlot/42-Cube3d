/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:00:36 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/04 22:23:01 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_cub3d *game, int argc, char *argv[])
{
	if (init_window(game) < 0)
		return (-1);
	init_player(game, 1, 1);
	init_dirt_sprite(game);
	if (init_s_sprite(game))
		return (1);
	if (game_loop(game))
		return (-1);
	return (0);
}
