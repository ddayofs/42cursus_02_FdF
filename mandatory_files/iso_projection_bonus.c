/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:00:20 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/09 21:13:10 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	rotate_by_z_axis(t_point *map_info, int size)
{
	int			i;
	double		x;
	double		y;
	double		angle;

	angle = -(M_PI / 4);
	i = -1;
	while (++i < size)
	{
		x = map_info[i].x;
		y = map_info[i].y;
		map_info[i].x = x * cos(angle) - y * sin(angle);
		map_info[i].y = x * sin(angle) + y * cos(angle);
	}
	return ;
}

static void	rotate_by_x_axis(t_point *map_info, int size)
{
	int			i;
	double		y;
	double		z;
	double		angle;

	angle = M_PI / 2 - atan(1.0 / sqrt(2.0));
	i = -1;
	while (++i < size)
	{
		y = map_info[i].y;
		z = map_info[i].z;
		map_info[i].y = y * cos(angle) - z * sin(angle);
		map_info[i].z = y * sin(angle) + z * cos(angle);
	}
	return ;
}

void	iso_projection(t_info *info)
{
	t_point		*map_info;
	int			size;

	map_info = info->map_info;
	size = info->arr_size.size;
	rotate_by_z_axis(map_info, size);
	rotate_by_x_axis(map_info, size);
	return ;
}
