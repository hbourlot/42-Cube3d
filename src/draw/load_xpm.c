/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:58:08 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/12 17:09:44 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/// @brief Loads an XPM image and stores it in a sprite structure.
/// @param game Pointer to the main game structure.
/// @param sprite Path to the XPM file.
/// @param img Structure where the image will be stored.
/// @return 0 on success, -1 on failure.
int	load_xpm(t_cube3d *game, char *sprite, t_sprite *img)
{
	img->mlx_ptr = game->mlx_ptr;
	img->win_ptr = game->win_ptr;
	img->img =	mlx_xpm_file_to_image(img->mlx_ptr, sprite, &img->width, &img->height);
	if (!img->img)
	{
		// or return -1 or free everything and close game.
		ft_printf_fd(2, "Sprite: '%s' failed to load\n", sprite);
		free_game(game);
		return (-1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	if (!img->addr)
	{
		ft_printf_fd(2, "Sprite: '%s' failed to load\n", sprite);
		free_game(game);
		return (-1);
	}
	return (0);
}
