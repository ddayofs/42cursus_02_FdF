/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:17:55 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/04 17:40:29 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	args_chk(int argc, char *argv[], t_info *info)
{
	char	*last_dot;

	if (argc != 2)
	{
		ft_putstr_fd("needs only 2 arguments including program name\n", 2);
		return (1);
	}
	last_dot = ft_strrchr(argv[1], '.');
	if (last_dot)
	{
		if (!ft_strcmp(last_dot, ".fdf\0"))
		{
			info->file_name = argv[1];
			return (0);
		}
	}
	ft_putstr_fd("not a valid file form\n", 2);
	return (1);
}
