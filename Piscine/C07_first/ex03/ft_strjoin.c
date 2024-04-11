/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:43:56 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/14 12:07:36 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
/*#include<stdio.h>*/

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (*str)
	{
		a++;
		str++;
	}
	return (a);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = ft_strlen(dest);
	while (*src != 0)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		length;
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	i = -1;
	length = 0;
	while (++i < size)
		length += ft_strlen(strs[i]);
	length = length + ((size - 1) * ft_strlen(sep));
	str = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < (size - 1))
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
		i++;
	}
	ft_strcat(str, strs[i]);
	return (str);
}
/*
int	main(void)
{
	char	**strs;
	char	*str;
	
	strs = malloc(sizeof(char *) * 3);
	strs[0] = malloc(sizeof(char) * 10);
	strs[1] = malloc(sizeof(char) * 10);
	strs[2] = malloc(sizeof(char) * 10);
	strs[0] = "Hello you";
	strs[1] = "Hello you";
	strs[2] = "Hello you";
	str = ft_strjoin(3, strs, ", ");
	printf("%s\n", str);
}*/
