/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:50:04 by joralves          #+#    #+#             */
/*   Updated: 2025/04/15 16:00:46 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture_door(t_map *map, t_ray *ray, t_dda *dda)
{
	t_door	*door;

	door = find_door(map, dda->map_x, dda->map_y);
	if (!door)
		return ;
	if (door->is_open)
		ray->tex_num = 5;
	else
		ray->tex_num = 4;
}

void	set_texture(t_map *map, t_ray *ray, t_dda *dda)
{
	if (ray->wall_hit == 1)
	{
		if (ray->hit_side == 0)
		{
			if (dda->dir_x > 0)
				ray->tex_num = 2;
			else
				ray->tex_num = 3;
		}
		else
		{
			if (dda->dir_y > 0)
				ray->tex_num = 0;
			else
				ray->tex_num = 1;
		}
	}
	if (ray->wall_hit == 2)
		set_texture_door(map, ray, dda);
}

t_img	*get_texture(t_cub3d *game, int tex_num)
{
	t_img	*tex;

	if (tex_num == 0)
		tex = game->sprites->so;
	if (tex_num == 1)
		tex = game->sprites->no;
	if (tex_num == 2)
		tex = game->sprites->ea;
	if (tex_num == 3)
		tex = game->sprites->we;
	if (tex_num == 4)
		tex = game->sprites->door_close;
	if (tex_num == 5)
		tex = game->sprites->door_open;
	return (tex);
}

int	get_texture_color(t_img *tex, int x, int y)
{
	int	color;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0x000000);
	color = *(int *)(tex->addr + (y * tex->size_line) + (x * (tex->bpp / 8)));
	return (color);
}
