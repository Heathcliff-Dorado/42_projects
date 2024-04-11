/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:38:48 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/26 16:06:55 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	second = 1;
	while (first < 99)
	{
		while (second < 100)
		{
			ft_putchar((first / 10) + '0');
			ft_putchar((first % 10) + '0');
			write(1, " ", 1);
			ft_putchar((second / 10) + '0');
			ft_putchar((second % 10) + '0');
			if (first < 98)
			{
				write(1, ", ", 2);
			}
			second++;
		}
		first++;
		second = first + 1;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
