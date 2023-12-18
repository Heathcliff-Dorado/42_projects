/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:51:10 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/18 21:53:13 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long int	ft_atoli(const char *str)
{
	long int	i;
	long int	num;
	long int	sign;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + (str[i] - 48);
		i++;
	}
	return (sign * num);
}

int	ft_valid_atoi(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] || ft_atoli(str) > 2147483647)
		return (0);
	return (1);
}

int	ft_last_arg(int argc, char **argv)
{
	if (argc == 6)
	{
		if (ft_valid_atoi(argv[5]))
			return (ft_atoi(argv[5]));
		else
			return (0);
	}
	else
		return (-1);
}

int	ft_check_args(int argc, char **argv, t_conditions *rules)
{
	if (ft_valid_atoi(argv[1]) && ft_atoi(argv[1]))
		rules->n_phil = ft_atoi(argv[1]);
	else
		return (0);
	if (ft_valid_atoi(argv[2]) && ft_atoi(argv[2]))
		rules->tdie = (u_int64_t) ft_atoi(argv[2]);
	else
		return (0);
	if (ft_valid_atoi(argv[3]) && ft_atoi(argv[3]))
		rules->teat = (u_int64_t) ft_atoi(argv[3]);
	else
		return (0);
	if (ft_valid_atoi(argv[4]) && ft_atoi(argv[4]))
		rules->tsleep = (u_int64_t) ft_atoi(argv[4]);
	else
		return (0);
	rules->req_eat = ft_last_arg(argc, argv);
	if (!rules->req_eat)
		return (0);
	return (1);
}
