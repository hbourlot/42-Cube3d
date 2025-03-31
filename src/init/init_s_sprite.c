/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:43:58 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 13:04:12 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// static int	init_sprite(t_cub3d *game, t_img **sprite, char *path)
// {
// 	t_img	*new;

// 	new = malloc(sizeof(t_img));
// 	if (!new)
// 		return (printf("Error: Malloc failed for%s texture\n", path), -1);
// 	new->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &new->width,
// 			&new->height);
// 	if (!new->img_ptr)
// 	{
// 		free(new);
// 		return (printf("Error: Failed to load XPM file %s\n", path), -1);
// 	}
// 	new->addr = mlx_get_data_addr(new->img_ptr, &new->bpp, &new->size_line,
// 			&new->endian);
// 	if (!new->addr)
// 	{
// 		mlx_destroy_image(game->mlx_ptr, new->img_ptr);
// 		free(new);
// 		return (printf("Error: Failed to get texture data address\n"), -1);
// 	}
// 	*sprite = new;
// 	return (SUCCESS);
// }

// int	init_s_sprite(t_cub3d *game)
// {
// 	if (init_sprite(game, &game->sprites->no, (char *)game->map->no))
// 		return (ft_printf_fd(2, ME_MALLOC), -1);
// 	if (init_sprite(game, &game->sprites->so, (char *)game->map->so))
// 		return (ft_printf_fd(2, ME_MALLOC), -1);
// 	if (init_sprite(game, &game->sprites->ea, (char *)game->map->ea))
// 		return (ft_printf_fd(2, ME_MALLOC), -1);
// 	if (init_sprite(game, &game->sprites->we, (char *)game->map->we))
// 		return (ft_printf_fd(2, ME_MALLOC), -1);
// 	return (SUCCESS);
// }



/// @brief Loads an XPM texture into memory using MiniLibX.
/// @param render_s The rendering structure containing texture data.
/// @param path Path to the XPM file.
/// @param index Texture index in the array.
/// @param mlx Pointer to the MiniLibX instance.
static void load_texture(t_render *render_s, char *path, int index, void *mlx)
{
	// int	width;
	// int	height;
	// int	*data;
	// int	i;

	// render_s->img[index].img_ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	// if (!render_s->img[index].img_ptr)
	// {
	// 	printf("Failed to load texture: %s\n", path);
	// 	return;
	// }
	// // render_s->texture[index] = (t_vec3 *)malloc(sizeof(t_vec3) * width * height);
	// // if (!render_s->texture[index])
	// // 	return;
	// data = (int *)mlx_get_data_addr(render_s->img[index].img_ptr, &i, &i, &i);
	// i = 0;
	// while (i < width * height)
	// {
	// 	render_s->texture[index][i].x = ((data[i] >> 16) & 0xFF) / 255.0;
	// 	render_s->texture[index][i].y = ((data[i] >> 8) & 0xFF) / 255.0;
	// 	render_s->texture[index][i].z = (data[i] & 0xFF) / 255.0;
	// 	i++;
	// }
}

/// @brief Loads all textures from XPM files.
/// @param render_s The rendering structure.
/// @param mlx Pointer to the MiniLibX instance.
void load_all_textures(t_render *render_s, void *mlx)
{
	load_texture(render_s, "./texture/wall/grass_block.xpm", 0, mlx);
	load_texture(render_s, "./texture/wall/grass_block.xpm", 1, mlx);
	load_texture(render_s, "./texture/wall/grass_block.xpm", 2, mlx);
	load_texture(render_s, "./texture/wall/wall1.xpm", 3, mlx);
	load_texture(render_s, "./texture/wall/wall2.xpm", 4, mlx);
	load_texture(render_s, "./texture/wall/wall1.xpm", 5, mlx);
	load_texture(render_s, "./texture/wall/wall3.xpm", 6, mlx);
	load_texture(render_s, "./texture/wall/wall3.xpm", 7, mlx);
}