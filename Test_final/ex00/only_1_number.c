/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_1_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:08:11 by nseropia          #+#    #+#             */
/*   Updated: 2022/07/03 20:43:35 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find_number(int **array, int position);
int	ft_counting(int number, int **array, int position);

void	ft_only_1_option(int **array)
{
	int	i;
	int	solution;

	i = 0;
	while (i < 16)
	{
		if (array[i / 4][i % 4] == 0)
		{
			solution = ft_find_number(array, i);
			if ((solution < 5) && (solution > 0))
				array[i / 4][i % 4] = solution;
		}
		i++;
	}
}

int	ft_find_number(int **array, int position)
{
	int	potential;
	int	number;
	int	count;

	potential = 0;
	number = 1;
	while (number < 5)
	{
		count = ft_counting(number, array, position);
		if (count == 0)
		{
			if (potential == 0)
				potential = number;
			else
				potential = 10;
		}
		number++;
	}
	return (potential);
}

int	ft_counting(int number, int **array, int position)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (j < 4)
	{
		if (array[position / 4][j] == number)
			count++;
		if (array[j][position % 4] == number)
			count++;
		j++;
	}
	return (count);
}
