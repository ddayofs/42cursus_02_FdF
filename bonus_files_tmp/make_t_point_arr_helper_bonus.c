/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_t_point_arr_helper_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:04:33 by donglee2          #+#    #+#             */
/*   Updated: 2023/08/04 17:28:38 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_splits(char **splitted)
{
	int	i;

	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
}

static char	*to_lower(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if ('A' <= *ptr && *ptr <= 'Z')
			*ptr += 'a' - 'A';
		ptr++;
	}
	return (str);
}

static int	replace_char_to_int(char c)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	make_base_10(char *base_16)
{
	char	*tmp;
	int		i;
	int		integer;
	int		num;

	tmp = ft_substr(base_16, 2, ft_strlen(base_16));
	if (!tmp)
		exit(1);
	tmp = to_lower(tmp);
	i = 0;
	while (tmp[i])
	{
		num = replace_char_to_int(tmp[i]);
		if (num == -1)
		{
			ft_putstr_fd("parse error\n", 2);
			printf("[%s]\n", base_16);
			printf("[%c]\n", tmp[i]);
			exit(1);
		}
		integer = integer * 16 + num;
		i++;
	}
	free(tmp);
	return (integer);
}
