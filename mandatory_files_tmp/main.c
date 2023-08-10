/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:59:21 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/06 14:52:16 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	make_iso_projected_coordinates(t_info *info)
{
	init_t_info_rest(info);
	record_arr_size(info);
	info->map_info = make_t_point_arr(info);
	move_to_center_of_plane(info);
	increase_coordinates(info, info->win_size.size_x / info->arr_size.width
		* 0.2, 0);
	iso_projection(info);
	move_to_center_of_window(info);
}

static void	print_out(t_info info, t_mlx_data mlx_data, t_data img)
{
	put_dots(&info, img);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, img.img, 0, 0);
	mlx_hook(mlx_data.mlx_win, 17, 0, win_close, &mlx_data);
	mlx_hook(mlx_data.mlx_win, 2, 0, win_close_2, &mlx_data);
	mlx_loop(mlx_data.mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx_data	mlx_data;
	t_data		img;
	t_info		info;
	int			x;
	int			y;

	if (args_chk(argc, argv, &info))
		return (1);
	make_iso_projected_coordinates(&info);
	x = info.win_size.size_x;
	y = info.win_size.size_y;
	mlx_data.mlx = mlx_init();
	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, x, y, "MLX created");
	img.img = mlx_new_image(mlx_data.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	print_out(info, mlx_data, img);
	free(info.map_info);
}
