/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraf <mgraf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:22:30 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/13 11:13:13 by mgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy_nzb(char *dest, char *src);
int		check_min(int **array, int nrow, int i);

typedef struct s_info
{
	int		lines;
	int		length;
	char	c_empty;
	char	c_obstacle;
	char	c_full;
	char	**map;
}	t_info;

int	**create_int_array(t_info *map)
{
	int	**array;
	int	i;

	array = malloc(sizeof(int *) * map->lines);
	i = 0;
	while (i < map->lines)
	{
		array[i] = malloc(sizeof(int) * map->length);
		i++;
	}
	return (array);
}

int	**populate_array(int **array, t_info *map)
{
	int	i;

	i = 0;
	while (i < map->lines * map->length)
	{
		if (map->map[i / map->length][i % map->length] == map->c_empty)
			array[i / map->length][i % map->length] = 1;
		else
			array[i / map->length][i % map->length] = 0;
		i++;
	}
	return (array);
}

int	**find_square(int **array, int nrow, int ncol)
{
	int	i;
	int	min;

	i = 0;
	while (i < nrow * ncol)
	{
		if (array[i / nrow][i % nrow] != 0)
		{
			min = check_min(array, nrow, i);
			if (min == 10000)
				min = 0;
			array[i / nrow][i % nrow] = array[i / nrow][i % nrow] + min;
		}
		i++;
	}
	return (array);
}

int	check_min(int **array, int nrow, int i)
{
	int	min;

	min = 10000;
	if ((i / nrow) != 0)
	{
		if (array[(i / nrow) - 1][i % nrow] < min)
			min = array[(i / nrow) - 1][i % nrow];
	}
	else
		min = 0;
	if ((i % nrow) != 0)
	{
		if (array[i / nrow][(i % nrow) - 1] < min)
			min = array[i / nrow][(i % nrow) - 1];
		if ((i / nrow) != 0)
		{
			if ((min < 0) || array[(i / nrow) - 1][(i % nrow) - 1] < min)
				min = array[(i / nrow) - 1][(i % nrow) - 1];
		}
	}
	else
		min = 0;
	return (min);
}

int	find_maxima(t_info *map, int **array, int *col, int *row)
{
	int	max;

	max = 0;
	*row = 0;
	while (*row < map->lines)
	{
		*col = 0;
		while (*col < map->length)
		{
			if (array[*row][*col] > max)
				max = array[*row][*col];
			(*col)++;
		}
		(*row)++;
	}
	return (max);
}
