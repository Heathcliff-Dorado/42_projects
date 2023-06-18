/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraf <mgraf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:40:50 by mgraf             #+#    #+#             */
/*   Updated: 2022/07/13 11:19:29 by mgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"
#include <stdio.h> // for printf

int	ft_min_size(t_info info)
{
	if ((info.map[0][0] != '\0'))
		return (1);
	else
		return (-1);
}

int	ft_printable(t_info info)
{
	if (info.c_empty < ' ' || info.c_empty > '~')
		return (-1);
	if (info.c_full < ' ' || info.c_full > '~')
		return (-1);
	if (info.c_obstacle < ' ' || info.c_obstacle > '~')
		return (-1);
	return (1);
}

int	ft_distinct(t_info info)
{
	if ((info.c_empty == info.c_full) || (info.c_empty == info.c_obstacle)
		|| info.c_obstacle == info.c_full)
		return (-1);
	else
		return (1);
}

int	ft_valid_map(t_info info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.lines)
	{
		j = 0;
		while (j < info.length)
		{
			if (info.map[i][j] != info.c_obstacle
				&& info.map[i][j] != info.c_empty)
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check(t_info info)
{
	if (ft_min_size(info) == -1
		|| ft_printable(info) == -1
		|| ft_distinct(info) == -1
		|| ft_valid_map(info) == -1
		|| info.length == -1)
	{
		free_info(info);
		return (-1);
	}
	return (0);
}
