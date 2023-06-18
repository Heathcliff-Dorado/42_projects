/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraf <mgraf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:14:43 by mgraf             #+#    #+#             */
/*   Updated: 2022/07/13 11:29:10 by mgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

t_info	ft_malloc_map(t_info info, char *text)
{
	int	i;

	info.length = ft_check_ll(text);
	info.map = malloc(sizeof (char *) * (info.lines + 1));
	i = 0;
	while (i < info.lines)
	{
		info.map[i] = malloc(sizeof(char) * (info.length + 1));
		ft_strcpy_nzb(&info.map[i][info.length +1], "\0");
		i++;
	}
	return (info);
}

t_info	ft_extract_info(char *text, int *error)
{
	int		length;
	char	*line;
	t_info	*info;

	line = ft_first_line(text);
	length = ft_length(line);
	if (length > 3)
	{
		info = malloc(sizeof (t_info));
		(*info).c_empty = line[length -3];
		(*info).c_obstacle = line[length -2];
		(*info).c_full = line[length -1];
		line[length -3] = '\0';
		(*info).lines = ft_simple_atoi(line);
		free(line);
		return (*info);
	}
	else
	{
		*error = -1;
		info = NULL;
		return (*info);
	}
}

char	*ft_first_line(char *text)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc (sizeof (char) * 100);
	while (text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

t_info	ft_extract_map(t_info info, char *text)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (text[i] != '\n')
		i++;
	i++;
	j = 0;
	count = 0;
	while (text[i] != '\0' && count < info.lines)
	{
		if (text[i] == '\n')
		{	
			ft_strcpy(&info.map[count][j], "\0");
			count++;
			j = -1;
		}
		else
			ft_strcpy(&info.map[count][j], &text[i]);
		i++;
		j++;
	}
	return (info);
}
