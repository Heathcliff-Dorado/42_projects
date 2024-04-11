/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraf <mgraf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:38:11 by mgraf             #+#    #+#             */
/*   Updated: 2022/07/13 21:40:55 by mgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int	j;

	if (dest == (void *)0 || src == (void *)0)
		return ((void *)0);
	i = 0;
	while (dest[i] != '\0')
		i++;
	j = i;
	i = 0;
	while ((src[i] != '\0') && (i < nb))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_file_from_input(char *text)
{
	t_info	info;
	int		**array;
	int		i;
	int		error;

	error = 0;
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

int	read_stdin(void)
{
	int		just_read;
	char	*str;
	char	*prior;
	char	buffer[100];
	int		buffer_size;

	just_read = -1;
	str = malloc(sizeof(char) * 1);
	str[0] = '\0';
	while (just_read != 0)
	{
		prior = str;
		just_read = read(0, buffer, 100);
		buffer_size = buffer_size + just_read;
		str = malloc(sizeof(char) * buffer_size);
		ft_strcpy(str, prior);
		ft_strncat(str, buffer, just_read);
		free(prior);
	}
	if (ft_file_from_input(str))
		return (-1);
	return (0);
}
