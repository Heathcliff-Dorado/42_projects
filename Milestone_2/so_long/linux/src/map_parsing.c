/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:40:06 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/03 20:43:18 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_um_new(char ***map, char **new_map, char *str, int i)
{
	new_map[i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!new_map[i])
		return (0);
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
	return (1);
}

int	ft_update_map(char ***map, t_layout *layout, char *str)
{
	int		i;
	char	**new_map;

	i = ft_map_length(map);
	new_map = ft_calloc(sizeof(char *), (i + 2));
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
	if (!ft_um_new(map, new_map, str, i))
		return (-4);
	layout->row++;
	return (1);
}

int	ft_check_map(int fd, t_layout *layout, char ***map)
{
	char	*str;
	int		ret;

	str = get_next_line(fd);
	if (!str)
		return (-5);
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
