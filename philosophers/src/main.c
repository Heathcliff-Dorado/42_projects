/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:13:49 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/11 22:16:12 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/*Things I might need to solve:
-Does it matter if the time to eat/die/etc is bigger than an int, or should I store it in u_int64_t directly?*/
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
	if (argc == 6)
	{
		if (ft_valid_atoi(argv[5]))
			rules->req_eat = ft_atoi(argv[5]);
		else
			return (0);
	}
	else
		rules->req_eat = -1;
	return (1);
}

void	ft_init_phil(t_conditions *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_phil)
	{
		rules->phil[i].id = i + 1;
		rules->phil[i].dead = 0;
		rules->phil[i].n_meals = 0;
		rules->phil[i].teat = rules->teat;
		rules->phil[i].tdie = rules->tdie;
		rules->phil[i].tsleep = rules->tsleep;
		rules->phil[i].rules = rules;
		pthread_mutex_init(&rules->meal_lock, NULL);
		pthread_mutex_init(&rules->dead_lock, NULL);
		rules->phil[i].last_meal = get_time();
		if (i == 0)
			rules->phil[0].fork_l = &rules->forks[rules->n_phil - 1];
		else
			rules->phil[i].fork_l = &rules->forks[i - 1];
		rules->phil[i].fork_r = &rules->forks[i];
		i++;
	}
}

int	ft_alloc(t_conditions *rules)
{
	int	i;

	i = 0;
	rules->tpid = ft_calloc(sizeof(pthread_t), rules->n_phil);
	if (!rules->tpid)
		return (0);
	rules->forks = ft_calloc(sizeof(pthread_mutex_t), rules->n_phil);
	if (!rules->forks)
		return (0);
	while (i < rules->n_phil)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	rules->phil = ft_calloc(sizeof(t_phil), rules->n_phil);
	if (!rules->phil)
		return (0);
	ft_init_phil(rules);
	return (1);
}

int	ft_start(t_conditions *rules)
{
	int	i;

	i = 0;
	pthread_create(&rules->tpid, NULL, ft_monitor, (void *)rules);
	while (i < rules->n_phil)
	{
		pthread_create(&rules->phil[i].thread, NULL, ft_routine, (void *)&rules->phil[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_conditions	rules;

	if (argc != 5 || argc != 6)
		return (0);
	i = 1;
	rules.finished = 0;
	pthread_mutex_init(&rules.writing, NULL);
	if (!ft_check_args(argc, argv, &rules))
		return (0);
	ft_alloc(&rules);
	ft_start(&rules);
}
