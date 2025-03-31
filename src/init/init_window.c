/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:59:04 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 00:04:31 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_window(t_cub3d *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        return (ft_printf_fd(2, ME_MF), -1);
    // mlx_get_screen_size(game->mlx_ptr, &game->map->width, &game->map->height);
    game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Cube-3d");
    if (!game->win_ptr)
        return (ft_printf_fd(2, ME_NW), -1);
    game->img.img_ptr = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->img.img_ptr)
        return (ft_printf_fd(2, ME_NW), -1);
    return (0);
}
