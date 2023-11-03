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

int	icons_check(char ***map, t_layout *layout, int i, int j)
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
	return (0);
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
			if (!icons_check((*map), layout, i, j))
				return (-7);
			j++;
		}
		i++;
	}
	if (layout->player != 1 || layout->exit != 1 || layout->collect < 1)
		return (-6);
	return (1);
}
