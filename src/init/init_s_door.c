/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:17 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 01:49:59 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_door	*find_door(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i < map->num_doors)
	{
		if (map->doors[i].x == x && map->doors[i].y == y)
			return (&map->doors[i]);
		i++;
	}
	return (NULL);
}

static void	count_doors(t_map *map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_world[y][x] == 2)
				count++;
			x++;
		}
		y++;
	}
	map->num_doors = count;
}

static void	init_doors_aux(t_map *map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map_world[y][x] == 2)
			{
				map->doors[i].x = x;
				map->doors[i].y = y;
				map->doors[i].is_open = 0;
				i++;
			}
		}
	}
}

int	init_doors(t_map *map)
{
	count_doors(map);
	if (map->num_doors == 0)
		return (0);
	map->doors = ft_calloc((map->num_doors + 1), sizeof(t_door));
	if (!map->doors)
		return (-1);
	init_doors_aux(map);
	return (0);
}
