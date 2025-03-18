/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:18:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/18 09:23:59 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../lib/libft/inc/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/raycasting/inc/raycasting.h"
#include "definitions.h"
#include "error.h"
# include <X11/X.h>      // Button press
# include <X11/keysym.h> // Key device
#include <fcntl.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_sprite
{
	char				*addr;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img;
	int					width;
	int					height;
	int					color;
	int					bpp;
	int					size_line;
	int					endian;
}			t_sprite;

typedef struct s_img
{
	t_sprite	*no;
	t_sprite	*so;
	t_sprite	*we;
	t_sprite	*ea;
	t_sprite	*floor;
	t_sprite	*ceiling;
}			t_img;
typedef struct s_map
{
	const char	*path;
	char		**cub_array;
	char		**map_array;
	int			nbr_of_lines;
	int			width;
	int			height;
	const char	*no;
	const char	*so;
	const char	*we;
	const char	*ea;
	const char	*floor;
	const char	*ceiling;
}				t_map;

typedef struct s_player
{
	int			direction;
	int			pos_x;
	int			pos_y;
	char  dir;
}				t_player;

typedef struct s_cube3d
{
	t_map		*map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*name;
	t_img		*sprites;
	t_player	*player;

}				t_cube3d;

// ***************************************************************************
// **							Utils Functions      						**
// ***************************************************************************
int				key_press(int keycode, t_cube3d *game);


// ***************************************************************************
// **							map/parsing Functions 						**
// ***************************************************************************
bool			parse_floor_ceiling(t_map *map);
bool			parse_map(t_map *map);
bool			parse_texture(t_map *map);
bool			has_invalid_name(t_map *map);

// ***************************************************************************
// **							Initialize Functions 						**
// ***************************************************************************
int				init_s_map(t_map *map);
int				init_game(t_cube3d *game);
int				init_s_cube3d(t_cube3d **game, int argc, char *argv[]);
int				init_s_player(t_player *player, t_map *map);


// ***************************************************************************
// **							Draw Functions       						**
// ***************************************************************************
void			draw_pixel(t_sprite *sprite, int x, int y, int color);
int				create_rgb(int t, int r, int g, int b);
int				load_xpm(t_cube3d *game, char *sprite, t_sprite *img);

// ***************************************************************************
// **							Player Functions      						**
// ***************************************************************************
void			locate_spawn_point(t_player *player, t_map *map);


// ***************************************************************************
// **							Exit Functions      						**
// ***************************************************************************
void			free_game(t_cube3d *game);

// ***************************************************************************
// **							Map Functions   							**
// ***************************************************************************
int				cub_array(t_map *map);
int				parse_s_map(t_map *map);
int				open_cub(const char *path);
int				init_window(t_cube3d *game);
int				count_lines(const char *path);

int				game_loop(t_cube3d *game);
