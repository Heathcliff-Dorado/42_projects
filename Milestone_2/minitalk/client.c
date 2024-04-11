/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:04:32 by hdorado-          #+#    #+#             */
/*   Updated: 2023/06/18 13:48:40 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (1 << bit & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Error, please provide PID and message\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("Error, PID is not valid\n");
		return (0);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	return (0);
}
