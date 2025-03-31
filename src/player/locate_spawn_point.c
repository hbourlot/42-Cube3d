/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_spawn_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:13:30 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/31 17:17:55 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	locate_spawn_point(t_player *player, t_map *map)
{
	int i;
	int	j;
	int	tot;

	i  = 0;
	while (map->map_world[i])
	{
		j = 0;
		tot = 0;
		while (map->map_world[i][j])
		{
			if (ft_strchr(IPL, map->map_world[i][j]))
				tot++;
			if (ft_strchr(VPL, map->map_world[i][j]))
			{
				player->dir = map->map_world[i][j];
				player->pos_x = j - tot;
				player->pos_y = i;
			}
			j++;
		}
		i++;
	}
}
