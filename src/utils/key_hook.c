/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:55:38 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/24 22:01:37 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


static void move_up(int keycode, char **map_world, t_render *render)
{
    int new_pos_x = (int)(render->pos_x + render->dir_x * render->move_speed);
    int new_pos_y = (int)(render->pos_y + render->dir_y * render->move_speed);
    
    if (map_world[new_pos_x][(int)render->pos_y] == '0')
        render->pos_x += render->dir_x * render->move_speed;
    if (map_world[(int)render->pos_x][new_pos_y] == '0')
		render->pos_y += render->dir_y * render->move_speed;
}

static void move_down(int keycode, char **map_world, t_render *render)
{
    int new_pos_x;
    int new_pos_y;
	
	
	new_pos_x = (int)(render->pos_x - render->dir_x * render->move_speed);
	new_pos_y = (int)(render->pos_y - render->dir_y * render->move_speed);
    if (map_world[new_pos_x][(int)render->pos_y] == '0')
        render->pos_x -= render->dir_x * render->move_speed;
    if (map_world[(int)render->pos_x][new_pos_y] == '0')
		render->pos_y -= render->dir_y * render->move_speed;
}

static void rotate_right(int keycode, t_render *render)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;
	
	
	old_dir_x = render->dir_x;
	old_plane_x = render->plane_x;
	rot_speed = render->rot_speed;
	render->dir_x = render->dir_x * cos(-rot_speed) - render->dir_y * sin(-rot_speed);
	render->dir_y = old_dir_x * sin(-rot_speed) + render->dir_y * cos(-rot_speed);
	render->plane_x = render->plane_x * cos(-rot_speed) - render->plane_y * sin(-rot_speed);
	render->plane_y = old_plane_x * sin(-rot_speed) + render->plane_y * cos(-rot_speed);
}

static void rotate_left(int keycode, t_render *render)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	old_dir_x = render->dir_x;
	old_plane_x = render->plane_x;
	rot_speed = render->rot_speed;
	render->dir_x = render->dir_x * cos(rot_speed) - render->dir_y * sin(rot_speed);
	render->dir_y = old_dir_x * sin(rot_speed) + render->dir_y * cos(rot_speed);
	render->plane_x = render->plane_x * cos(rot_speed) - render->plane_y * sin(rot_speed);
	render->plane_y = old_plane_x * sin(rot_speed) + render->plane_y * cos(rot_speed);	
}
int key_press(int keycode, t_cube3d *game)
{
	char 		**map_world;
	t_render	*render;

	map_world = game->map->map_world;
	render = game->render;
	
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (keycode == XK_Up)
		move_up(keycode, map_world, render);
	if (keycode == XK_Down)
		move_down(keycode, map_world, render);
	if (keycode == XK_Escape)
	{
		ft_printf_fd(1, "You pressed %d (Esc)\n", keycode);
		free_game(game);
	}
	if (keycode == XK_Right)
		rotate_right(keycode, render);
	if (keycode == XK_Left)
		rotate_left(keycode, render);
	return (0);
}
