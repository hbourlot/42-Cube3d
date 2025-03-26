/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:51 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/26 12:18:46 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL2/SDL.h>  // SDL headers for timing
#include <time.h>

// Including path to dda function
// #include "../../../inc/cube3d.h"



#define FOV_X 0
#define FOV_Y 0.66


#define mapWidth 24
#define mapHeight 24

extern int worldMap[mapWidth][mapHeight];


typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}			t_ray;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}			t_sphere;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}			t_color;

typedef	struct s_matrix
{
	float	m[4][4];
}			t_matrix;

typedef struct s_dda
{
	double	pos_x;		// x start position
	double	pos_y;		// y start position
	double	dir_x;		// initial direction vector
	double	dir_y;		// initial direction vector
	double	plane_x;	// the 2d raycaster version of camera plane
	double	plane_y;	// the 2d raycaster version of camera plane
	double	time;		// time of current frame
	double	old_time;	// time of previous frame
}			t_dda;


typedef struct s_render
{
	void		*game;
	double		pos_x;		// x start position
	double		pos_y;		// y start position
	double		dir_x;		// initial direction vector
	double		dir_y;		// initial direction vector
	double		plane_x;	// the 2d raycaster version of camera plane
	double		plane_y;	// the 2d raycaster version of camera plane
	double		time;		// time of current frame
	double		old_time;	// time of previous frame
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	float		side_dist_x;
	float		side_dist_y;
	int			hit;
	int			side;
	float		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
	t_matrix	wall_points;
	void		(*render)(int screen_width, int screen_height, char **map_world);
	void		(*draw_line)(void *game, t_matrix *se_points, int x0, int y0);
}			t_render;


t_vec3		normalize(t_vec3 v);
t_vec3		add(t_vec3 a, t_vec3 b);
t_vec3		cross(t_vec3 a, t_vec3 b);
t_vec3		subtract(t_vec3 a, t_vec3 b);

float		magnitude(t_vec3 v);
float		dot(t_vec3 a, t_vec3 b);

void		multiply_matrix_vector(float result[4], t_matrix m, float v[4]);
t_matrix	identify_matrix();
t_matrix	translation_matrix(float tx, float ty, float tz);
t_matrix	rotation_matrix_z(float angle);

t_render	*get_render();
void		render(int screen_width, int screen_height, char **map_world);
void 		perform_dda(t_render *render_s, char **map_world);
void		init_ray(t_render *render_s, int screen_width, int x);
void		update_timing(t_render *render_s);
void 		step_and_side_dist(t_render *render_s);
void 		calculate_wall_height(t_render *render_s, int screen_height);



unsigned int get_ticks();
