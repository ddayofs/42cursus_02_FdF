/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:58:21 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/10 14:19:02 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_t_info_rest(t_info *info)
{
	info->point.x = 0;
	info->point.y = 0;
	info->point.z = 0;
	info->point.color = 0;
	info->arr_size.width = 0;
	info->arr_size.height = 0;
	info->arr_size.size = 0;
	info->win_size.size_x = 1440;
	info->win_size.size_y = 900;
	info->route.up = 0;
	info->route.down = 0;
	info->route.left = 0;
	info->route.right = 0;
	info->map_info = NULL;
}

void	increase_coordinates(t_info *info, double a, double b)
{
	int		i;
	t_point	*map_info;

	map_info = info->map_info;
	i = 0;
	while (i < info->arr_size.size)
	{
		map_info[i].x = map_info[i].x * a + b;
		map_info[i].y = map_info[i].y * a + b;
		map_info[i].z = map_info[i].z * a + b;
		i++;
	}
}

int	win_close(t_info *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(0);
}
