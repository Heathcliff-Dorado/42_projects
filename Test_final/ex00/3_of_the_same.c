/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_of_the_same.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:11:54 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/03 20:43:19 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_last_number(int **array, int number);

void	three_of_the_same(int **array)
{
	int	number;
	int	i;
	int	count;

	number = 1;
	while (number < 5)
	{
		count = 0;
		i = 0;
		while (i < 16)
		{
			if (array[i / 4][i % 4] == number)
				count++;
			i++;
		}
		if (count == 3)
			put_last_number(array, number);
		number++;
	}
}

void	put_last_number(int **array, int number)
{
	int	i;
	int	j;
	int	number_in_cross;

	i = 0;
	while (i < 16)
	{
		j = 0;
		number_in_cross = 0;
		while (j < 4)
		{
			if (array[i / 4][j] == number)
				number_in_cross++;
			if (array[j][i % 4] == number)
				number_in_cross++;
			j++;
		}
		if (number_in_cross == 0)
			array[i / 4][i % 4] = number;
		i++;
	}
}
