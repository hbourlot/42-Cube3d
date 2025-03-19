/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:55:38 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/19 16:04:04 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int key_press(int keycode, t_cube3d *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf_fd(1, "You pressed %d (Esc)\n", keycode);
		free_game(game);
	}
	if (keycode == XK_Right)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		// printf("game->render->dir_x: %f\n", game->render->dir_x);
		get_render()->dir_y += 0.05;
	}
	if (keycode == XK_Left)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		get_render()->dir_y -= 0.05;
		// printf("game->render->dir_x: %f\n", game->render->dir_x);
		// printf("game->render->dir_x: %f\n", game->render->side_dist_x);
	}
	return (0);
}