/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:13:49 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/19 15:07:27 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_phil(t_conditions *rules)
{
	int	i;

	i = 0;
	rules->dead = 0;
	while (i < rules->n_phil)
	{
		rules->ph[i].id = i + 1;
		rules->ph[i].n_meals = 0;
		rules->ph[i].eating = 0;
		rules->ph[i].teat = rules->teat;
		rules->ph[i].tdie = rules->tdie;
		rules->ph[i].tsleep = rules->tsleep;
		rules->ph[i].start = get_time();
		rules->ph[i].last_meal = get_time();
		if (i == 0)
			rules->ph[0].fork_l = &rules->forks[rules->n_phil - 1];
		else
			rules->ph[i].fork_l = &rules->forks[i - 1];
		rules->ph[i].fork_r = &rules->forks[i];
		rules->ph[i].rules = rules;
		i++;
	}
}

int	ft_alloc(t_conditions *rules)
{
	int	i;

	i = 0;
	rules->forks = ft_calloc(sizeof(pthread_mutex_t), rules->n_phil);
	if (!rules->forks)
		return (0);
	while (i < rules->n_phil)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	rules->ph = ft_calloc(sizeof(t_phil), rules->n_phil);
	if (!rules->ph)
	{
		i = 0;
		while (i < rules->n_phil)
		{
			pthread_mutex_destroy(&rules->forks[i]);
			i++;
		}
		free(rules->forks);
		return (0);
	}
	ft_init_phil(rules);
	return (1);
}

void	ft_start(t_conditions *rules)
{
	int	i;

	i = 0;
	pthread_create(&rules->tpid, NULL, ft_monitor, (void *)rules);
	while (i < rules->n_phil)
	{
		pthread_create(&rules->ph[i].thr, NULL, ft_rtn, (void *)&rules->ph[i]);
		i++;
	}
	i = 0;
	pthread_join(rules->tpid, NULL);
	while (i < rules->n_phil)
	{
		pthread_join(rules->ph[i].thr, NULL);
		i++;
	}
}

void	ft_clear_mutex(t_conditions *rules)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&rules->dead_lock);
	pthread_mutex_destroy(&rules->meal_lock);
	pthread_mutex_destroy(&rules->writing);
	while (i < rules->n_phil)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	free (rules->forks);
	free (rules->ph);
}

int	main(int argc, char **argv)
{
	int				i;
	t_conditions	rules;

	if (!(argc == 5 || argc == 6))
	{
		write(2, "Invalid number of arguments\n", 28);
		return (0);
	}
	i = 1;
	pthread_mutex_init(&rules.writing, NULL);
	pthread_mutex_init(&rules.meal_lock, NULL);
	pthread_mutex_init(&rules.dead_lock, NULL);
	if (!ft_check_args(argc, argv, &rules))
	{
		write(2, "Error, incorrect arguments\n", 27);
		return (0);
	}
	if (!ft_alloc(&rules))
	{
		write(2, "Error in memory allocation\n", 27);
		return (0);
	}
	ft_start(&rules);
	ft_clear_mutex(&rules);
	return (0);
}
