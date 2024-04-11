/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraf <mgraf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:25:38 by mgraf             #+#    #+#             */
/*   Updated: 2022/07/13 11:13:16 by mgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_open_file(char *path)
{
	int	fp;

	fp = open(path, O_RDONLY);
	if (fp == -1)
	{
		return (-1);
	}
	return (fp);
}

int	ft_characters(char *path)
{
	int		i;
	char	c;
	int		file;

	file = ft_open_file(path);
	if (file == -1)
		return (-1);
	i = 0;
	while (read(file, &c, 1))
		i++;
	close(file);
	return (i);
}

char	*ft_read_text(char *path, int *error)
{
	char	c;
	char	*buffer;
	int		count;
	int		file;
	int		i;

	count = ft_characters(path);
	if (check_error(count, error))
		return ("");
	buffer = malloc(sizeof(char) * (count + 1));
	file = ft_open_file(path);
	if (check_error(file, error))
		return ("");
	i = 0;
	while (read(file, &c, 1))
	{
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	close(file);
	return (buffer);
}

int	check_error(int test, int *error)
{
	if (test == -1)
	{
		*error = -1;
		return (-1);
	}
	return (0);
}
