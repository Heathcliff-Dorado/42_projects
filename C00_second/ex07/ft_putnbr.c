/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:59:19 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/26 16:24:56 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
	}
	if (nb > 9 || nb < -9)
	{
		if (nb < 0)
		{
			ft_putnbr((nb / 10) * -1);
		}
		else
		{
			ft_putnbr(nb / 10);
		}
	}
	if (nb >= 0)
	{
		ft_putchar((nb % 10) + '0');
	}
	else
	{
		ft_putchar((nb % 10) * -1 + '0');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
