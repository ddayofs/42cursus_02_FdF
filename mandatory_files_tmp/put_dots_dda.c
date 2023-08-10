/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dots_dda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:11:27 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/06 12:32:06 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	dda_put_pixel(t_dda_info dda_info, t_point	p0,
		t_win_size win_size, t_data img)
{
	double	x;
	double	y;
	int		color;
	int		i;

	x = p0.x;
	y = p0.y;
	i = -1;
	color = p0.color;
	while (++i < dda_info.steps)
	{
		if (0 < round(x) && round(x) < win_size.size_x
			&& 0 < round(y) && round(y) < win_size.size_y)
			my_mlx_pixel_put(&img, round(x), round(y), color);
		x += dda_info.x_inc;
		y += dda_info.y_inc;
	}
}

static void	dda_put_last_pixel(t_point	p1,
		t_win_size win_size, t_data img)
{
	double		x;
	double		y;
	int			color;

	x = p1.x;
	y = p1.y;
	color = p1.color;
	if (0 < round(x) && round(x) < win_size.size_x
		&& 0 < round(y) && round(y) < win_size.size_y)
		my_mlx_pixel_put(&img, round(x), round(y), color);
}

void	dda(t_point p0, t_point p1, t_win_size win_size, t_data img)
{
	double		dx;
	double		dy;
	t_dda_info	dda_info;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	dda_info.p0_color = p0.color;
	dda_info.p1_color = p1.color;
	if (ft_fabs(dx) > ft_fabs(dy))
		dda_info.steps = (int)ft_fabs(dx);
	else
		dda_info.steps = (int)ft_fabs(dy);
	dda_info.x_inc = dx / dda_info.steps;
	dda_info.y_inc = dy / dda_info.steps;
	dda_put_pixel(dda_info, p0, win_size, img);
	dda_put_last_pixel(p1, win_size, img);
}
