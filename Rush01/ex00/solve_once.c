/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_once.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:16:56 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/03 16:05:07 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_sum(int i, int *conditions, int **array);
void	add_first_number(int **array, int i, int number);
void	number4(int **array, int i);

void	ft_solve_once(int **array, int *conditions)
{
	int	i;

	i = 0;
	while (conditions[i])
	{
		if (conditions[i] == 4)
			number4(array, i);
		i++;
	}
	i = 0;
	while (conditions[i])
	{
		if (conditions[i] == 1)
			add_first_number(array, i, 4);
		i++;
	}
	ft_sum(0, conditions, array);
	ft_sum(8, conditions, array);
}

void	ft_sum(int i, int *conditions, int **array)
{
	int	x;

	x = 0;
	while (i + x <= i + 3)
	{
		if ((conditions[x + i] + conditions[x + i + 4]) == 3)
		{
			if (conditions[x + i] == 2)
				add_first_number(array, x + i, 3);
			else
				add_first_number(array, x + i + 4, 3);
		}
		x++;
	}
}

void	add_first_number(int **array, int i, int number)
{
	if (i < 4)
		array[0][i % 4] = number;
	else if ((i > 3) && (i < 8))
		array[3][i % 4] = number;
	else if ((i > 7) && (i < 12))
		array[i % 4][0] = number;
	else if (i > 11)
		array[i % 4][3] = number;
}

void	number4(int **array, int i)
{
	if (i < 4)
	{
		array[0][i % 4] = 1;
		array[1][i % 4] = 2;
		array[2][i % 4] = 3;
	}
	else if ((i < 8) && (i > 3))
	{
		array[3][i % 4] = 1;
		array[2][i % 4] = 2;
		array[1][i % 4] = 3;
	}
	else if ((i > 7) && (i < 12))
	{
		array[i % 4][0] = 1;
		array[i % 4][1] = 2;
		array[i % 4][2] = 3;
	}
	else if (i > 11)
	{
		array[i % 4][3] = 1;
		array[i % 4][2] = 2;
		array[i % 4][1] = 3;
	}
}
