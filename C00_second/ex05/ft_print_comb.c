/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:37:15 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/26 16:04:28 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	c;
	char	d;
	char	e;

	c = 47;
	while (c++ < '7')
	{
		d = c;
		while (d++ < '8')
		{
			e = d;
			while (e++ < '9')
			{
				write(1, &c, 1);
				write(1, &d, 1);
				write(1, &e, 1);
				if (c < '7')
				{
					write(1, ", ", 2);
				}
			}
		}
	}
}
