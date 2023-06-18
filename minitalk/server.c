/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:54:20 by hdorado-          #+#    #+#             */
/*   Updated: 2023/06/18 13:50:53 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*Listen to a signal continuously. When a signal is received, 
 * if it was SIGUSR1 put a 1 in position bit, if it was SIGUSR2, 
 * leave the 0. After receiving 8 signals, reinitialize everything 
 * to 0 and start again*/

void	ft_receive(int sig)
{
	static int	bit;
	static char	c;

	if (sig == SIGUSR1)
	{
		c |= (1 << bit);
		bit++;
	}
	else
		bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	int	ret;

	ret = 0;
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_receive);
		signal(SIGUSR2, ft_receive);
	}
	return (0);
}
