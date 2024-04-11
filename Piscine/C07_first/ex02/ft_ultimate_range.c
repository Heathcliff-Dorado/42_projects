/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:18:45 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/14 11:43:24 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
		return (0);
	array = malloc(sizeof(int) * (max - min));
	if (!array)
		return (-1);
	i = min;
	while (i < max)
	{
		array[i - min] = i;
		i++;
	}
	*range = array;
	return (max - min);
}
/*
int	main(void)
{
	int	*range;
	int	i;
	int	error;

	i = 0;
	error = ft_ultimate_range(&range, 2, 6);
	while(range[i])
	{
		printf("%d, ", range[i]);
		i++;
	}
	printf("Return: %d\n", error);
}*/
