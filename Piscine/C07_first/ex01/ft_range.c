/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:54:31 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/14 11:38:46 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (0);
	range = malloc(sizeof(int) * (max - min));
	i = min;
	while (i < max)
	{
		range[i - min] = i;
		i++;
	}
	return (range);
}
/*
int	main(void)
{
	int	*range;
	int	i;

	i = 0;
	range = ft_range(2, 6);
	while(range[i])
	{
		printf("%d, ", range[i]);
		i++;
	}
}*/
