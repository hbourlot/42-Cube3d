/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/31 17:25:37 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Draws a pixel on a sprite at the given coordinates.
/// @param sprite Pointer to the sprite structure.
/// @param x X-coordinate of the pixel.
/// @param y Y-coordinate of the pixel.
/// @param color Integer representing the RGB color.
void	draw_pixel(t_img *img, int x, int y, int color)
{
	mlx_pixel_put(img->mlx_ptr, img->win_ptr, x, y, color);
}
