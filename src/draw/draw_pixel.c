/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/13 10:06:15 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/// @brief Draws a pixel on a sprite at the given coordinates.
/// @param sprite Pointer to the sprite structure.
/// @param x X-coordinate of the pixel.
/// @param y Y-coordinate of the pixel.
/// @param color Integer representing the RGB color.
void	draw_pixel(t_sprite *sprite, int x, int y, int color)
{
	mlx_pixel_put(sprite->mlx_ptr, sprite->win_ptr, x, y, color);
}
