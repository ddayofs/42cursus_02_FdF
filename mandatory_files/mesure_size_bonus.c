/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesure_size_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:58:01 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/09 16:28:59 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	free_splits_ret_width(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (i);
}

static int	align_chk(char **splitted, t_arr_size *arr_size)
{
	if (arr_size->width != free_splits_ret_width(splitted))
	{
		ft_putstr_fd("map is not aligned\n", 2);
		return (1);
	}
	return (0);
}

char	*trim_str_from_gnl(int fd)
{
	char	*new_line;
	char	*ret;

	new_line = get_next_line(fd);
	if (!new_line)
		return (NULL);
	ret = ft_strtrim(new_line, " \n");
	if (!ret)
		exit(1);
	free(new_line);
	return (ret);
}

static void	record_width_height(int fd, t_arr_size *arr_size)
{
	char	*new_line;
	char	**splitted;

	new_line = trim_str_from_gnl(fd);
	if (!new_line)
		exit(1);
	splitted = ft_split(new_line, ' ');
	if (!splitted)
		exit(1);
	arr_size->width = free_splits_ret_width(splitted);
	while (1)
	{
		(arr_size->height)++;
		free(new_line);
		new_line = trim_str_from_gnl(fd);
		if (!new_line)
			break ;
		splitted = ft_split(new_line, ' ');
		if (!splitted)
			exit(1);
		if (align_chk(splitted, arr_size))
			exit(1);
	}
}

void	record_arr_size(t_info *info)
{
	t_arr_size	*arr_size;
	char		*file_name;
	int			fd;

	arr_size = &(info->arr_size);
	file_name = info->file_name;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("There's no \"", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd("\" file", 2);
		exit(1);
	}
	record_width_height(fd, arr_size);
	close(fd);
	arr_size->size = (arr_size->width) * (arr_size->height);
}
