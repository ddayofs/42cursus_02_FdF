/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:59:21 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/10 14:51:57 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	int		x;
	int		y;

	if (args_chk(argc, argv, &info))
		return (1);
	init_t_info_rest(&info);
	record_arr_size(&info);
	info.map_info = make_t_point_arr(&info);
	move_to_center_of_plane(&info);
	increase_coordinates(&info, info.win_size.size_x / info.arr_size.width
		* 0.3, 0);
	iso_projection(&info);
	move_to_center_of_window(&info);
	x = info.win_size.size_x;
	y = info.win_size.size_y;
	info.mlx = mlx_init();
	info.mlx_win = mlx_new_window(info.mlx, x, y, "MLX created");
	// info.img.img = mlx_new_image(info.mlx, x, y);
	// info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel,
	// 		&info.img.line_length, &info.img.endian);
	// put_dots(&info, info.img);
	// mlx_put_image_to_window(info.mlx, info.mlx_win, info.img.img, 0, 0);
	make_n_put_img_to_win(&info);
	mlx_hook(info.mlx_win, 17, 0, win_close, &info);
	mlx_hook(info.mlx_win, 2, 0, key_handler, &info);
	mlx_loop(info.mlx);
}
