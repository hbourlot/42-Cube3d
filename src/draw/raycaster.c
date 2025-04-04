#include "cub3d.h"

void	render_walls(t_cub3d *game, t_raycast *raycast, int color, int x)
{
	// int	x;
	int	y;
	int screen_y;
	int column_width = (int)((float)GAME_WIDTH / (float)CANT_RAYS);
	if (column_width < 1)
		column_width = 1;
	int x_start =x*column_width;
	int x_end =(x+1)*column_width;
	while (x_start < x_end)
	{
		y = 0;
		while (y < raycast->wall_h)
		{
			screen_y = raycast->draw_start + y;
			if (screen_y >= 0 && screen_y < GAME_HEIGHT)
				my_mlx_pixel_put(game, x, screen_y, color);
			y++;
		}
		x_start++;
	}
}

void	cast_render_raycast(t_cub3d *game)
{
	t_raycast	r;
	t_player	*p;
	t_img		*tex;
	int			x;
	int			color;
	double		ray_angle;
	double alpha;

	p = &game->player;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		alpha = FOV / 2 - FOV / SCREEN_WIDTH * x;
		ray_angle = p->angle + alpha;
		r.dda = dda(game, p->x, p->y, ray_angle);
		print_ddainfo(r.dda);
		r.p_dist = r.dda.dist * cos(alpha);
		// r.wall_h = (int)(SCREEN_HEIGHT / r.p_dist);
		r.wall_h = (int)(WALL_SIZE*GAME_HEIGHT/r.p_dist);

		// r.draw_start = SCREEN_HEIGHT / 2 - r.wall_h / 2;
		r.draw_start = GAME_HEIGHT / 2 - r.wall_h / 2;
		if (r.draw_start < 0)
			r.draw_start = 0;
		r.draw_end = r.wall_h / 2 + SCREEN_HEIGHT / 2;
		if (r.draw_end >= SCREEN_HEIGHT)
			r.draw_end = SCREEN_HEIGHT - 1;
		tex = get_texture(game, &r);
		if(r.dda.hitside == 0)
		color = create_rgb(0, 255, 0, 0);
		else
		color = create_rgb(0, 0, 0,255);
		render_walls(game,&r,color,x);
		x++;
	}
}

// void	cast_render_raycast(t_cub3d *game)
// {
// 	t_raycast	r;
// 	t_player	*p;
// 	t_img		*tex;
// 	int			x;
// 	int			color;
// 	double		ray_angle;
// 	float		hit_x;
// 	float		hit_y;
// 	float		wallX;
// 	int			tex_x;
// 	int			tex_y;
// 	float		step;
// 	float		tex_pos;

// 	p = &game->player;
// 	x = 0;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		ray_angle = p->angle + FOV / 2 - (x * FOV / SCREEN_WIDTH);
// 		r.dda = dda(game, p->x, p->y, ray_angle);
// 		print_ddainfo(r.dda);
// 		r.p_dist = r.dda.dist * cos(ray_angle - p->angle);
// 		r.wall_h = (int)(SCREEN_HEIGHT / r.p_dist);
// 		r.draw_start = SCREEN_HEIGHT / 2 - r.wall_h / 2;
// 		if (r.draw_start < 0)
// 			r.draw_start = 0;
// 		r.draw_end = r.wall_h / 2 + SCREEN_HEIGHT / 2;
// 		if (r.draw_end >= SCREEN_HEIGHT)
// 			r.draw_end = SCREEN_HEIGHT - 1;
// 		tex = get_texture(game, &r);
// 		hit_x = p->x + r.dda.dist * r.dda.dir_x;
// 		hit_y = p->y + r.dda.dist * r.dda.dir_y;
// 		if (r.dda.hitside == 1)
// 			wallX = hit_y - r.dda.grid_y /* * TILE_SIZE */;
// 		else
// 			wallX = hit_x - r.dda.grid_x /* * TILE_SIZE */;
// 		wallX -= floor(wallX);
// 		printf("wallX %d \n", wallX);
// 		// if ((r.dda.hitside == 1 && r.dda.step_x == -1) || (r.dda.hitside == 0
// 		// 	&& r.dda.step_y == -1))
// 		// wallX = TILE_SIZE - wallX;
// 		tex_x = (int)(wallX * tex->width);
// 		tex_x = tex_x % tex->width;
// 		// Calcular paso y posición inicial de la textura
// 		step = (float)tex->height / r.wall_h;
// 		tex_pos = (r.draw_start - SCREEN_HEIGHT / 2 + r.wall_h / 2) * step;
// 		// Ajustar para recorte vertical
// 		if (r.draw_start < 0)
// 			tex_pos += -r.draw_start * step;
// 		// Dibujar la columna
// 		for (int y = r.draw_start; y < r.draw_end; y++)
// 		{
// 			tex_y = (int)tex_pos % tex->height;
// 			color = get_texture_color(tex, tex_x, tex_y);
// 			my_mlx_pixel_put(game, x, y, color);
// 			tex_pos += step;
// 		}
// 		x++;
// 	}
// }
