/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dots_dda_helper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:46:18 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/09 13:21:39 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

double	ft_fabs(double f)
{
	if (f >= 0)
		return (f);
	return (-f);
}

static int	add_color_diff(int p0_value, int p1_value, int i, int steps)
{
	return (p0_value + (p1_value - p0_value) * i / steps);
}

int	find_out_color(int i, t_dda_info dda_info)
{
	unsigned int	color;
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = add_color_diff((dda_info.p0_color >> 24) & 0xff,
			(dda_info.p1_color >> 24) & 0xff, i, dda_info.steps) << 24;
	r = add_color_diff((dda_info.p0_color >> 16) & 0xff,
			(dda_info.p1_color >> 16) & 0xff, i, dda_info.steps) << 16;
	g = add_color_diff((dda_info.p0_color >> 8) & 0xff,
			(dda_info.p1_color >> 8) & 0xff, i, dda_info.steps) << 8;
	b = add_color_diff((dda_info.p0_color >> 0) & 0xff,
			(dda_info.p1_color >> 0) & 0xff, i, dda_info.steps) << 0;
	color = t | r | g | b;
	return (color);
}
