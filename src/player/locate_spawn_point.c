/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_spawn_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:13:30 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/22 11:52:44 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	locate_spawn_point(t_player *player, t_map *map)
{
	int i;
	int	j;
	int	tot;

	i  = 0;
	while (map->map_array[i])
	{
		j = 0;
		tot = 0;
		while (map->map_array[i][j])
		{
			if (ft_strchr(IPL, map->map_array[i][j]))
				tot++;
			if (ft_strchr(VPL, map->map_array[i][j]))
			{
				player->dir = map->map_array[i][j];
				player->pos_x = j - tot;
				player->pos_y = i;
			}
			j++;
		}
		i++;
	}
}
