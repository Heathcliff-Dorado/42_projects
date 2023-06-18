/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:50:10 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/25 20:42:21 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first(int a);
void	ft_middle(int a);

int	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
	{
		write(1, "Error, numbers must be positive\n", 31);
		return (1);
	}
	i = 1;
	ft_first(y);
	while (i < x -1)
	{
		ft_middle(y);
		i++;
	}
	ft_first(y);
	return(0);
}

void	ft_first(int a)
{
	int	j;

	j = 1;
	write(1, "o", 1);
	while (j < a - 1)
	{
		write(1, "-", 1);
		j++;
	}
	write(1, "o\n", 2);
}

void	ft_middle(int a)
{
	int	j;

	j = 1;
	write(1, "|", 1);
	while (j < a - 1)
	{
		write(1, " ", 1);
		j++;
	}
	write(1, "|\n", 2);
}
