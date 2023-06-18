/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:35:03 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/13 17:35:09 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_info	ft_zero_map(t_info info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.lines)
	{
		j = 0;
		while (j < info.length)
		{
			if (info.map[i][j] == info.c_empty)
			{
				ft_strcpy_nzb(&info.map[i][j], "1");
			}
			else if (info.map[i][j] == info.c_obstacle)
			{
				ft_strcpy_nzb(&info.map[i][j], "0");
			}
			j++;
		}
		i++;
	}
	return (info);
}

int	**ft_solver(t_info *info, int **array)
{
	int	c;
	int	r;
	int	max;

	array = create_int_array(info);
	array = populate_array(array, info);
	array = find_square(array, info->length, info->lines);
	max = find_max_position(info, array, &c, &r);
	info = change_map(info, c, r, max);
	return (array);
}

int	create_structure(char *text, t_info *info, int *error)
{
	*info = ft_extract_info(text, error);
	if (*error == -1)
		return (-1);
	*info = ft_malloc_map(*info, text);
	*info = ft_extract_map(*info, text);
	if (*error == -1)
	{
		return (-1);
	}
	if (ft_check(*info))
	{
		return (-1);
	}
	return (0);
}

int	ft_get_file(char *path)
{
	char	*text;
	t_info	info;
	int		**array;
	int		i;
	int		error;

	error = 0;
	text = ft_read_text(path, &error);
	if (error == -1)
		return (-1);
	if (create_structure(text, &info, &error))
		return (-1);
	free(text);
	i = 0;
	array = NULL;
	array = ft_solver(&info, array);
	i = 0;
	while (i < info.lines)
	{
		printf("%s\n", info.map[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		if (read_stdin())
			ft_putstr("map error\n");
	}
	else
	{	
		while (++i < argc)
		{
			if (ft_get_file(argv[i]) == -1)
			{
				ft_putstr("map error\n");
				continue ;
			}
		}
	}
	return (0);
}
