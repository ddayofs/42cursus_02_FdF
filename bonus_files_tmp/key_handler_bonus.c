/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:04:13 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/07 19:31:41 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"


void	ortho_projection(t_info *info, t_mlx_data *mlx_data, t_data *img)
{
	int	x;
	int	y;

	mlx_destroy_image(mlx_data->mlx, mlx_data->mlx_win);
	printf("here\n");
	init_t_info_rest(info);
	x = info->win_size.size_x;
	y = info->win_size.size_y;
	img->img = mlx_new_image(mlx_data->mlx, x, y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	record_arr_size(info);
	info->map_info = make_t_point_arr(info);
	move_to_center_of_plane(info);
	// increase_coordinates(info, info->win_size.size_x / info.arr_size->width
	// 	* 0.2, 0);
	move_to_center_of_window(info);
	put_dots(info, *img);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, img->img, 0, 0);
}

// void	parallel_mov(int keycode, t_info *info, t_mlx_data *mlx_data, t_data *img)
// {
// 	if (keycode == )
// }


int	key_handler(int keycode, t_info *info, t_mlx_data *mlx_data, t_data *img)
{
	//exit : ESC
	// printf("ohyeah");
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
		exit(0);
	}
	// ortho_projection : O
	// else if (keycode == 31)
	// {
	// 	ortho_projection(info, mlx_data, img);
	// }
	return (0);
}

