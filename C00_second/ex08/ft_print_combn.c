/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:13:00 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/26 16:25:57 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive(int i, int n, int number[], int recursion);
void	ft_putchar(char c);

void	ft_print_combn(int n)
{
	int	i;
	int	number[10];
	int	recursion_count;

	i = 0;
	recursion_count = 0;
	if (n > 0)
	{
		while (i < 11 - n)
		{
			number[0] = i;
			ft_recursive(i + 1, n - 1, number, recursion_count + 1);
			i++;
		}
	}
}

void	ft_recursive(int i, int n, int number[], int recursion)
{
	int	k;

	if (n > 0)
	{
		while (i < 11 - n)
		{
			number[recursion] = i;
			ft_recursive(i + 1, n - 1, number, recursion + 1);
			i++;
		}
	}
	else if (n == 0)
	{
		k = 0;
		while (k < recursion)
		{
			ft_putchar(number[k] + '0');
			k++;
		}
		if (number[0] < 10 - recursion)
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
