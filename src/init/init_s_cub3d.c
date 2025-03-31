/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:11:01 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 01:06:16 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int init_s_cub3d(t_cub3d **game, int argc, char *argv[])
{
	static t_cub3d 		data;
	static t_map		map;
	static t_sprite    sprites;
	static t_player		player;
	
	ft_memset(&data, 0, sizeof(t_cub3d));
	*game = &data;
	(*game)->map = &map;
	(*game)->sprites = &sprites;
	(*game)->player = &player;
	data.map->path = argv[1];
	if (init_s_map(data.map) < 0 || init_s_player(data.player, data.map))
		return (-1);
	return (0);
}
