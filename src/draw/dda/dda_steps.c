/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:05:03 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/19 15:36:14 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	dda_steps(int delta_x, int delta_y)
{
	if (abs(delta_x) > abs(delta_y))
		return (abs(delta_x));
	return (abs(delta_y));
}
