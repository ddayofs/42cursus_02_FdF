/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_coordinates_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:42:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/09 13:21:10 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_to_center_of_plane(t_info *info)
{
	int		i;
	int		size;
	t_point	*map_info;

	map_info = info->map_info;
	size = info->arr_size.size;
	i = 0;
	while (i < size)
	{
		map_info[i].x -= (double)(info->arr_size.width) / 2;
		map_info[i].y -= (double)(info->arr_size.height) / 2;
		i++;
	}
}

void	move_to_center_of_window(t_info *info)
{
	t_point	*map_info;
	int		win_x;
	int		win_y;
	int		size;
	int		i;

	map_info = info->map_info;
	win_x = info->win_size.size_x;
	win_y = info->win_size.size_y;
	size = info->arr_size.size;
	i = 0;
	while (i < size)
	{
		map_info[i].x += (double)win_x / 2;
		map_info[i].y += (double)win_y / 2;
		i++;
	}
}

// static void	rec_mini_x_y(double *mini_x, double *mini_y, t_info *info)
// {
// 	t_point	*map_info;
// 	int		arr_size;
// 	int		i;

// 	map_info = info->map_info;
// 	arr_size = info->arr_size.size;
// 	i = 0;
// 	while (i < arr_size)
// 	{
// 		if (map_info[i].x < *mini_x)
// 			*mini_x = map_info[i].x;
// 		if (map_info[i].y < *mini_y)
// 			*mini_y = map_info[i].y;
// 		i++;
// 	}
// }

// static void	compensate_mini_x_y(double mini_x, double mini_y, t_info *info)
// {
// 	t_point	*map_info;
// 	int		arr_size;
// 	int		i;

// 	mini_x = -mini_x;
// 	mini_y = -mini_y;
// 	map_info = info->map_info;
// 	arr_size = info->arr_size.size;
// 	i = 0;
// 	while (i < arr_size)
// 	{
// 		map_info[i].x += mini_x;
// 		map_info[i].y += mini_y;
// 	}
// }

// void	move_to_center_of_window_(t_info *info)
// {
// 	double	mini_x;
// 	double	mini_y;

// 	mini_x = 0.0;
// 	mini_y = 0.0;
// 	rec_mini_x_y(&mini_x, &mini_y, info);
// 	if (mini_x < 0 || mini_y < 0)
// 		compensate_mini_x_y(mini_x, mini_y, info);
// }
