/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:58:40 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/10 14:47:45 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_n_put_img_to_win(t_info *info)
{
	int	x;
	int	y;

	x = info->win_size.size_x;
	y = info->win_size.size_y;
	info->img.img = mlx_new_image(info->mlx, x, y);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_per_pixel,
			&info->img.line_length, &info->img.endian);
	put_dots(info, info->img);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img.img, 0, 0);
}

int	key_handler(int keycode, t_info *info)
{
	if (keycode == 53)
		win_close(info);
	else if (keycode == 18)
		ortho_projection(info);
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		translate_coordinates(info, keycode);
	else if (keycode == 126 || keycode == 125 || keycode == 123
		|| keycode == 124)
		rotate_coordinates(info, keycode);
	else if (keycode == 33 || keycode == 30)
		magnifier(info, keycode);
	else if (keycode == 34)
		return_to_iso(info);
	return (0);
}
