/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:22:22 by nseropia          #+#    #+#             */
/*   Updated: 2022/07/03 20:33:46 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	display(int **array)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			ft_putchar(array[j][i] + '0');
			write(1, " ", 1);
			i++;
		}
		ft_putchar(array[j][i] + '0');
		write(1, "\n", 1);
		j++;
	}
}
