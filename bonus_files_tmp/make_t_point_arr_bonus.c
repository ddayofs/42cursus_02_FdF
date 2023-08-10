/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_t_point_arr_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:19:29 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/07 19:18:26 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	init_zdot_and_color(char *str, t_point *ret, int idx)
{
	char	**splitted_2;

	ret[idx].color = 0xFFFFFF;
	if (ft_strchr(str, ','))
	{
		splitted_2 = ft_split(str, ',');
		ret[idx].z = ft_atoi(splitted_2[0]);
		ret[idx].color = make_base_10(splitted_2[1]);
		free_splits(splitted_2);
	}
	else
		ret[idx].z = ft_atoi(str);
}

static void	init_xdot_ydot(int i, int j, int idx, t_point *ret)
{
	ret[idx].x = j;
	ret[idx].y = i;
}

static void	init_ret(t_point *ret, int fd, t_arr_size *arr_size)
{
	int		idx;
	int		i;
	int		j;
	char	*new_line;
	char	**splitted;

	i = -1;
	while (++i < arr_size->height)
	{
		new_line = trim_str_from_gnl(fd);
		if (!new_line)
			break ;
		splitted = ft_split(new_line, ' ');
		free(new_line);
		if (!splitted)
			exit(1);
		j = -1;
		while (++j < arr_size->width)
		{
			idx = arr_size->width * i + j;
			init_xdot_ydot(i, j, idx, ret);
			init_zdot_and_color(splitted[j], ret, idx);
		}
		free_splits(splitted);
	}
}

t_point	*make_t_point_arr(t_info *info)
{
	t_point	*ret;
	int		fd;

	ret = (t_point *)malloc(sizeof(t_point) * info->arr_size.size);
	if (!ret)
		exit(1);
	fd = open(info->file_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	init_ret(ret, fd, &(info->arr_size));
	close(fd);
	return (ret);
}
