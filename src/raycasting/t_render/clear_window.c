/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:49:08 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 00:37:38 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void clear_window(t_img *img)
{
    int x, y;

    y = 0;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            put_pixel_to_image(img, x, y, 0x000000); // Set to black
            x++;
        }
        y++;
    }
}
