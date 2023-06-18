/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxima_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:52:44 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/13 16:52:51 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_info
{
	int		lines;
	int		length;
	char	c_empty;
	char	c_obstacle;
	char	c_full;
	char	**map;
}	t_info;

int		find_maxima(t_info *map, int **array, int *col, int *row);
char	*ft_strcpy_nzb(char *dest, char *src);

int	find_max_position(t_info *map, int **array, int *col, int *row)
{
	int	max;

	max = find_maxima(map, array, col, row);
	*row = 0;
	while (*row < map->lines)
	{
		*col = 0;
		while (*col < map->length)
		{
			if (array[*row][*col] == max)
				return (array[*row][*col]);
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}

t_info	*change_map(t_info *map, int c, int r, int max)
{
	int	cx;
	int	rx;

	rx = max;
	while (rx > 0)
	{
		cx = max;
		while (cx > 0)
		{
			ft_strcpy_nzb(&map->map[r - (rx - 1)][c - (cx - 1)], &map->c_full);
			cx--;
		}
		rx--;
	}
	return (map);
}
