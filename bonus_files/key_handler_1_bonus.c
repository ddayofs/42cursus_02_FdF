/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:56:51 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/10 14:44:50 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ortho_projection(t_info *info)
{
	free(info->map_info);
	mlx_destroy_image(info->mlx, info->img.img);
	info->map_info = make_t_point_arr(info);
	move_to_center_of_plane(info);
	increase_coordinates(info, info->win_size.size_x / info->arr_size.width
		* 0.3, 0);
	move_to_center_of_window(info);
	make_n_put_img_to_win(info);
}

static void	mv_dots(t_info *info, int keycode)
{
	int		i;
	t_route	route;
	double	multiplier;

	multiplier = (info->win_size.size_x / info->arr_size.width * 0.3);
	route = info->route;
	route.up = 0;
	route.down = 0;
	route.left = 0;
	route.right = 0;
	if (keycode == 13)
		route.up = 1;
	else if (keycode == 0)
		route.left = 1;
	else if (keycode == 1)
		route.down = 1;
	else
		route.right = 1;
	i = 0;
	while (i < info->arr_size.size)
	{
		info->map_info[i].x += multiplier * (route.right - route.left);
		info->map_info[i].y += multiplier * (route.down - route.up);
		i++;
	}	
}

void	translate_coordinates(t_info *info, int keycode)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mv_dots(info, keycode);
	make_n_put_img_to_win(info);
}

void	magnifier(t_info *info, int keycode)
{
	double	db;

	mlx_destroy_image(info->mlx, info->img.img);
	move_to_origin(info);
	if (keycode == 30)
		db = 1.01;
	else
		db = 0.99;
	increase_coordinates(info, db, 0);
	move_to_center_of_window(info);
	make_n_put_img_to_win(info);
}

void	return_to_iso(t_info *info)
{
	free(info->map_info);
	mlx_destroy_image(info->mlx, info->img.img);
	info->map_info = make_t_point_arr(info);
	move_to_center_of_plane(info);
	increase_coordinates(info, info->win_size.size_x / info->arr_size.width
		* 0.3, 0);
	iso_projection(info);
	move_to_center_of_window(info);
	make_n_put_img_to_win(info);
}
