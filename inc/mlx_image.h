/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:49:37 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/31 18:50:13 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_img
{
	char				*addr;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					width;
	int					height;
	int					color;
	int					bpp;
	int					size_line;
	int					endian;
}			t_img;
