/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:18:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/01 11:17:39 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "definitions.h"
# include "error.h"
// # include <X11/X.h>      // Button press
// # include <X11/keysym.h> // Key device
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	const char	*path;
	char		**cub_array;
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
}				t_player;

typedef struct s_cube3d
{
	t_map		map;
	void		*mlx_ptr;
	void		*mlx_win;
	char		*name;

}				t_cube3d;

// ***************************************************************************
// **							Parsing Functions							**
// ***************************************************************************
int				parse_s_map(t_map *map);
bool			parse_texture(t_map *map);
bool			parse_fc(t_map *map);
bool			invalid_file_name(t_map *data);


// ***************************************************************************
// **							Initialize Functions 						**
// ***************************************************************************
int				init_s_map(t_map *map);
t_cube3d		*init_s_cube3d(int argc, char *argv[]);

// ***************************************************************************
// **								Draw Functions   						**
// ***************************************************************************

// ***************************************************************************
// **								Exit Functions   						**
// ***************************************************************************
void			free_data(t_cube3d *data);

// ***************************************************************************
// **								Map Functions   						**
// ***************************************************************************
int				open_cub(const char *path);
int				init_window(t_cube3d *data);
int				cub_array(t_map *map);
int				count_lines(const char *path);

int				game_loop(t_cube3d *data);

#endif