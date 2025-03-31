/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_timing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:48:02 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 15:18:37 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void update_timing(t_render *render_s)
{
    render_s->old_time = render_s->time;
    render_s->time = get_ticks(); 
    
    double frameTime = (render_s->time - render_s->old_time) / 1000.0;

    render_s->move_speed = frameTime * 5.0;  
    render_s->rot_speed = frameTime * 2.0;
}
