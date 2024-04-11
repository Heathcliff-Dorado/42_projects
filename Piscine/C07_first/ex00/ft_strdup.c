/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:41:51 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/14 11:42:32 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;
	int		i;

	length = 0;
	while (src[length])
		length++;
	copy = malloc(sizeof(char) * (length + 1));
	if (!copy)
		return (0);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	char	str[] = "Hello world!";
	char	*dest;

	dest = ft_strdup(str);
	printf("Source: %s\nDest: %s\n", str, dest);
}*/
