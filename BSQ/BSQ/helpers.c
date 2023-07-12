/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraf <mgraf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:34:41 by mgraf             #+#    #+#             */
/*   Updated: 2022/07/13 11:13:15 by mgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_length(char *text)
{
	int	i;

	i = 0;
	while (text[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_count_lines(char *text)
{
	int	count;

	count = 0;
	while (*text != '\0')
	{
		if (*text == '\n')
			count++;
		text++;
	}
	return (count + 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (s1[i] == '\0')
		return (s1[i] - s2[i]);
	return (0);
}

int	ft_simple_atoi(char *str)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + str[i] - '0';
		else if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (n);
}
