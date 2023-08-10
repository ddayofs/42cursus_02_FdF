/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:13:34 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/10 14:45:04 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	rotate_by_z_axis(t_point *map_info, int size, int keycode)
{
	int			i;
	double		x;
	double		y;
	double		angle;

	if (keycode == 123)
		angle = -(M_PI / 45);
	else
		angle = M_PI / 45;
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

static void	rotate_by_x_axis(t_point *map_info, int size, int keycode)
{
	int			i;
	double		y;
	double		z;
	double		angle;

	if (keycode == 126)
		angle = M_PI / 45;
	else
		angle = -(M_PI / 45);
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

void	move_to_origin(t_info *info)
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
		map_info[i].x -= (double)win_x / 2;
		map_info[i].y -= (double)win_y / 2;
		i++;
	}
}

void	rotate_coordinates(t_info *info, int keycode)
{
	move_to_origin(info);
	mlx_destroy_image(info->mlx, info->img.img);
	if (keycode == 126 || keycode == 125)
		rotate_by_x_axis(info->map_info, info->arr_size.size, keycode);
	else
		rotate_by_z_axis(info->map_info, info->arr_size.size, keycode);
	move_to_center_of_window(info);
	make_n_put_img_to_win(info);
}
