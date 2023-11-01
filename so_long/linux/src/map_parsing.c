/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:40:06 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/01 22:33:00 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_surroundings(char **map, int i, int j, t_layout *layout)
{
	int	valid;

	valid = 0;
	if (map[i][j] == '1' || map[i][j] == 'X')
	{
		map[i][j] = 'X';
		return (0);
	}
	if (map[i][j] == 'P')
		return (1);
	map[i][j] = 'X';
	if (i > 0 && valid == 0)
		valid = ft_check_surroundings(map, i - 1, j, layout);
	if (i < layout->row && valid == 0)
		valid = ft_check_surroundings(map, i + 1, j, layout);
	if (j > 0 && valid == 0)
		valid = ft_check_surroundings(map, i, j - 1, layout);
	if (j < layout->col && valid == 0)
		valid = ft_check_surroundings(map, i, j + 1, layout);
	return (valid);
}

void	ft_freemap(char ***map)
{
	int	nrow;

	nrow = 0;
	while ((*map)[nrow])
		nrow++;
	while (nrow > 0)
	{
		free((*map)[nrow - 1]);
		nrow--;
	}
	free(*map);
}

int	ft_dupmap(char **src, char ***dst)
{
	int	nrow;
	int	i;

	nrow = 0;
	while (src[nrow])
		nrow++;
	*dst = malloc(sizeof(char *) * (nrow + 1));
	if (!(*dst))
		return (-4);
	i = 0;
	while (i < nrow)
	{
		(*dst)[i] = ft_strdup(src[i]);
		if (!(*dst)[i])
			return (-4);
		i++;
	}
	(*dst)[i] = NULL;
	return (1);
}

int	ft_valid_path(char ***map, t_layout *layout)
{
	int		i;
	int		j;
	char	**dupmap;

	i = 0;
	while (i < layout->row)
	{
		j = 0;
		while (j < layout->col)
		{
			if ((*map)[i][j] == 'E' || (*map)[i][j] == 'C')
			{
				dupmap = NULL;
				if (ft_dupmap((*map), &dupmap) == -4)
					return (-4);
				if (!ft_check_surroundings(dupmap, i, j, layout))
					return (-8);
				ft_freemap(&dupmap);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_icons(char ***map, t_layout *layout)
{
	int	i;
	int	j;

	i = 0;
	while (i < layout->row)
	{
		j = 0;
		while (j < layout->col)
		{
			if ((*map)[i][j] != '0' && (*map)[i][j] != '1')
			{
				if ((*map)[i][j] == 'E')
					layout->exit++;
				else if ((*map)[i][j] == 'P')
					layout->player++;
				else if ((*map)[i][j] == 'C')
					layout->collect++;
				else
					return (-7);
			}
			j++;
		}
		i++;
	}
	if (layout->player != 1 || layout->exit != 1 || layout->collect < 1)
		return (-6);
	return (1);
}

int	is_map_right(char ***map, t_layout *layout)
{
	int	i;
	int	ret;

	i = 0;
	while (i < layout->row)
	{
		if ((int) ft_strlen((*map)[i]) != layout->col ||
			(*map)[i][0] != '1' || (*map)[i][layout->col - 1] != '1')
			return (-5);
		i++;
	}
	i = 0;
	while (i < layout->col)
	{
		if ((*map)[0][i] != '1' || (*map)[layout->row - 1][i] != '1')
			return (-5);
		i++;
	}
	ret = parse_icons(map, layout);
	if (ret < 0)
		return (ret);
	ret = ft_valid_path(map, layout);
	if (ret < 0)
		return (ret);
	return (1);
}

int	ft_update_map(char ***map, t_layout *layout, char *str)
{
	int		i;
	int		len;
	char	**new_map;

	len = 0;
	if (*map)
	{
		while ((*map)[len])
			len++;
	}
	new_map = ft_calloc(sizeof(char *), (len + 2));
	if (!new_map)
		return (-4);
	i = 0;
	if (*map)
	{
		while ((*map)[i])
		{
			new_map[i] = ft_calloc(ft_strlen((*map)[i]) + 1, sizeof(char));
			if (!new_map[i])
				return (-4);
			ft_strlcpy(new_map[i], (*map)[i], ft_strlen((*map)[i]) + 1);
			i++;
		}
	}
	new_map[i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!new_map[i])
		return (-4);
	ft_strlcpy(new_map[i], str, ft_strlen(str));
	i = 0;
	if (*map)
	{
		while ((*map)[i])
		{
			free((*map)[i]);
			i++;
		}
	}
	free((*map));
	(*map) = new_map;
	layout->row++;
	return (1);
}

int	ft_check_map(int fd, t_layout *layout, char ***map)
{
	char	*str;
	int		ret;

	str = get_next_line(fd);
	layout->col = ft_strlen(str) - 1;
	while (str)
	{
		ret = ft_update_map(map, layout, str);
		if (ret < 0)
			return (ret);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	ret = is_map_right(map, layout);
	if (ret < 0)
		return (ret);
	return (1);
}

int	ft_open_map(char *directory, t_layout *layout, char ***map)
{
	int	len;
	int	fd;
	int	ret;

	len = ft_strlen(directory);
	if (ft_strncmp(".ber", directory + len - 4, 4))
		return (-2);
	fd = open(directory, O_RDONLY);
	if (fd < 0)
		return (-3);
	ret = ft_check_map(fd, layout, map);
	close(fd);
	if (ret < 0)
		return (ret);
	return (1);
}

int	parse_map(int argc, char **argv, t_layout *layout, char ***map)
{
	int	ret;

	if (argc != 2)
		return (-1);
	ret = ft_open_map(argv[1], layout, map);
	if (ret < 0)
		return (ret);
	return (1);
}

void	ft_newlayout(t_layout *layout)
{
	layout->row = 0;
	layout->col = 0;
	layout->exit = 0;
	layout->player = 0;
	layout->collect = 0;
}
