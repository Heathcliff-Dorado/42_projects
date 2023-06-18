/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:25:11 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/05 11:43:55 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 31 && str[i] <= 126)
		{
			ft_putchar(str[i]);
			i++;
		}
		else
		{
			ft_putchar(92);
			ft_putchar((str[i] / 16) + '0');
			if ((str[i] % 16) < 10)
				ft_putchar((str[i] % 16) + '0');
			else
				ft_putchar((str[i] % 16) + 87);
			i++;
		}
	}
}
