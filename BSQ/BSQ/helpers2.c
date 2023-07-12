/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:23:26 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/13 17:23:30 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*ft_strcpy_nzb(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	free_info(t_info info)
{
	int	i;

	i = 0;
	while (i < info.lines)
	{
		free(info.map[i]);
		i++;
	}
	free(info.map);
}
