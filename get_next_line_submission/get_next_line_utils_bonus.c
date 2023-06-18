/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:16:00 by hdorado-          #+#    #+#             */
/*   Updated: 2023/02/03 20:18:54 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_error(char **str, char **tmp)
{
	if (*str != NULL)
		free (*str);
	if (*tmp != NULL)
	{
		free (*tmp);
		*tmp = NULL;
	}
	return (NULL);
}

int	ft_search_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	counter;
	int	i;

	counter = 0;
	while (src[counter] != '\0')
		counter++;
	i = 0;
	if (size == 0)
		return (counter);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (counter);
}
