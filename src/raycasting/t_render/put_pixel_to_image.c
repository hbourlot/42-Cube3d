/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:00:16 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 00:36:05 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void put_pixel_to_image(t_img *img, int x, int y, int color)
{
    int pixel_index;

    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
        return;
    
    pixel_index = (y * img->size_line) + (x * (img->bpp / 8));
    *(int *)(img->addr + pixel_index) = color;
}
