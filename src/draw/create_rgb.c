/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:10:45 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/12 17:10:58 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/// @brief Creates an RGB color value with transparency.
/// @param t Transparency (0-255, where 0 is fully opaque).
/// @param r Red component (0-255).
/// @param g Green component (0-255).
/// @param b Blue component (0-255).
/// @return The combined integer representing the color.
int		create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
