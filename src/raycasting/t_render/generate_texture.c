/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:01:50 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 15:17:39 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

// /// @brief Loads an XPM texture into memory using MiniLibX.
// /// @param render_s The rendering structure containing texture data.
// /// @param path Path to the XPM file.
// /// @param index Texture index in the array.
// /// @param mlx Pointer to the MiniLibX instance.
static void load_texture(t_render *render_s, char *path, int index, void *mlx)
{
	int		*width;
	int		*height;
	int		*bpp;
	int		i;

	bpp = &render_s->texture[index]->bpp;
	width =	&render_s->texture[index]->width;
	height = &render_s->texture[index]->height;
	render_s->texture[index]->img_ptr = render_s->mlx_xpm_file_to_image(mlx, path, width, height);
	if (!render_s->texture[index]->img_ptr)
	{
		printf("Failed to load texture: %s\n", path);
		return;
	}
	render_s->texture[index]->addr = render_s->mlx_get_data_addr(render_s->texture[index]->img_ptr,
		 &render_s->texture[index]->bpp, 
		 &render_s->texture[index]->size_line,
		 &render_s->texture[index]->endian);
}

/// @brief Loads all textures from XPM files.
/// @param render_s The rendering structure.
/// @param mlx Pointer to the MiniLibX instance.
void generate_textures(t_render *render_s, void *mlx)
{
	load_texture(render_s, "./texture/wall/grass_block.xpm", 0, mlx);
	load_texture(render_s, "./texture/wall/wall1.xpm", 1, mlx);
	load_texture(render_s, "./texture/wall/wall2.xpm", 2, mlx);
	load_texture(render_s, "./texture/wall/grass_block.xpm", 3, mlx);
	load_texture(render_s, "./texture/wall/grass_block.xpm", 4, mlx);
	load_texture(render_s, "./texture/wall/wall1.xpm", 5, mlx);
	load_texture(render_s, "./texture/wall/wall3.xpm", 6, mlx);
	load_texture(render_s, "./texture/wall/wall3.xpm", 7, mlx);
}


// void	generate_textures(t_render *render_s)
// {
// 	int	value[5];
// 	int	x;
// 	int	y;
// 	int	xorcolor;
// 	int	ycolor;
// 	int	xycolor;


// 	x = 0;
// 	while (x < tex_width)
// 	{
// 		y = 0;
// 		while (y < tex_height)
// 		{
// 			xorcolor = (x * 256 / tex_width) ^ (y * 256 / tex_height);
// 			ycolor = y * 256 / tex_height;
// 			xycolor = y * 128 / tex_height + x * 128 / tex_width;
	
// 			render_s->texture[0][tex_width * y + x] = 65536 * 254 * (x != y && x != tex_width - y);
// 			render_s->texture[1][tex_width * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
// 			render_s->texture[2][tex_width * y + x] = 256 * xycolor + 65536 * xycolor;
// 			render_s->texture[3][tex_width * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor;
// 			render_s->texture[4][tex_width * y + x] = 256 * xorcolor;
// 			render_s->texture[5][tex_width * y + x] = 65536 * 192 * (x % 16 && y % 16);
// 			render_s->texture[6][tex_width * y + x] = 65536 * ycolor;
// 			render_s->texture[7][tex_width * y + x] = 128 + 256 * 128 + 65536 * 128;
// 			y++;
// 		}
// 		x++;
// 	}
// }