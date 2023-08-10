/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:09:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/04 16:52:57 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../00libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include <stdio.h>

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}t_mlx_data;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_dda_info
{
	double	x_inc;
	double	y_inc;
	int		steps;
	int		p0_color;
	int		p1_color;
}t_dda_info;

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}t_point;

typedef struct s_arr_size
{
	int		width;
	int		height;
	int		size;
}t_arr_size;

typedef struct s_win_size
{
	int	size_x;
	int	size_y;
}t_win_size;

typedef struct s_info
{
	t_point		*map_info;
	t_point		point;
	t_arr_size	arr_size;
	t_win_size	win_size;
	char		*file_name;
}t_info;

//arguments_chk.c
int		args_chk(int argc, char *argv[], t_info *info);

//coordinate_coordinates.c
void	move_to_center_of_plane(t_info *info);
void	move_to_center_of_window(t_info *info);

//isoprojection.c
void	iso_projection(t_info *info);

//main_helper.c
void	init_t_info_rest(t_info *info);
void	increase_coordinates(t_info *info, double a, double b);
int		win_close_2(int keycode, t_mlx_data *mlx_data);
int		win_close(t_mlx_data *mlx_data);

// make_t_point_arr.c
t_point	*make_t_point_arr(t_info *info);

// make_t_point_arr_helper.c
void	free_splits(char **splitted);
int		make_base_10(char *base_16);

//measure_size.c
char	*trim_str_from_gnl(int fd);
void	record_arr_size(t_info *info);

//mlx.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//put_dots.c
void	put_dots(t_info *info, t_data img);

//put_dots_dda_helper.c
double	ft_fabs(double f);
int		find_out_color(int i, t_dda_info dda_info);

//put_dots_dda.c
void	dda(t_point p0, t_point p1, t_win_size win_size, t_data img);

#endif
