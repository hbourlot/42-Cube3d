/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:55:38 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 14:05:20 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void move_up(int keycode, char **map_world, t_render *render_s)
{
    int new_pos_x;
    int new_pos_y;
	int	pos_y;
	
	pos_y = (int)render_s->pos_y;
	
	new_pos_x = (int)(render_s->pos_x + render_s->dir_x * render_s->move_speed);
	new_pos_y= (int)(render_s->pos_y + render_s->dir_y * render_s->move_speed);
    
	printf("new_pos_x: %d\n", new_pos_x);
	printf("new_pos_y: %d\n", new_pos_y);
	printf("pos_y: %d\n", pos_y);
	printf("pos_y: %d\n", (int)render_s->pos_y);
	// printf("pos_y: %d\n", pos_y);
    if (worldMap[new_pos_x][pos_y] == 0)
        render_s->pos_x += render_s->dir_x * render_s->move_speed;
    if (worldMap[(int)render_s->pos_x][new_pos_y] == 0)
		render_s->pos_y += render_s->dir_y * render_s->move_speed;
}

static void move_down(int keycode, char **map_world, t_render *render)
{
    int new_pos_x;
    int new_pos_y;

	new_pos_x = (int)(render->pos_x - render->dir_x * render->move_speed);
	new_pos_y = (int)(render->pos_y - render->dir_y * render->move_speed);
    if (worldMap[new_pos_x][(int)render->pos_y] == 0)
        render->pos_x -= render->dir_x * render->move_speed;
    if (worldMap[(int)render->pos_x][new_pos_y] == 0)
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
int key_press(int keycode, t_cub3d *game)
{
	char 		**map_world;
	t_render	*render;

	map_world = game->map->map_world;
	// render = get_render();
	render = game->render;
	
	clear_window(render->img);
	// mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (keycode == XK_Up || keycode == XK_w)
		move_up(keycode, map_world, render);
	if (keycode == XK_Down || keycode == XK_s)
		move_down(keycode, map_world, render);
	if (keycode == XK_Escape)
	{
		ft_printf_fd(1, "You pressed %d (Esc)\n", keycode);
		free_game(game);
	}
	if (keycode == XK_Right || keycode == XK_d)
		rotate_right(keycode, render);
	if (keycode == XK_Left || keycode == XK_a)
		rotate_left(keycode, render);
	return (0);
}
