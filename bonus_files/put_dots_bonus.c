/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dots_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:38:35 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/09 13:21:35 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	put_dots_on_x_axis(t_point *map_info,
		t_arr_size arr_size, t_win_size win_size, t_data img)
{
	int	i;

	i = 0;
	while (i < arr_size.size)
	{
		if ((i + 1) % arr_size.width != 0)
			dda(map_info[i], map_info[i + 1], win_size, img);
		i++;
	}
}

static void	put_dots_on_y_axis(t_point *map_info,
		t_arr_size arr_size, t_win_size win_size, t_data img)
{
	int	i;

	i = 0;
	while (i + arr_size.width < arr_size.size)
	{
		dda(map_info[i], map_info[i + arr_size.width], win_size, img);
		i++;
	}
}

void	put_dots(t_info *info, t_data img)
{
	put_dots_on_x_axis(info->map_info, info->arr_size, info->win_size, img);
	put_dots_on_y_axis(info->map_info, info->arr_size, info->win_size, img);
}
