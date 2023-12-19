/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:55:25 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/19 15:22:46 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_phil *philo)
{
	ft_write("is thinking", philo->id, philo->rules);
	usleep(500);
}

void	ft_sleep(t_phil *philo)
{
	ft_write("is sleeping", philo->id, philo->rules);
	ft_usleep(philo->tsleep);
}

void	ft_start_eating(t_phil *philo)
{
	pthread_mutex_lock(&philo->rules->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->rules->meal_lock);
}

void	ft_eating(t_phil *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->fork_r);
		ft_write("has taken a fork", philo->id, philo->rules);
		pthread_mutex_lock(philo->fork_l);
		ft_write("has taken a fork", philo->id, philo->rules);
	}
	else
	{
		pthread_mutex_lock(philo->fork_l);
		ft_write("has taken a fork", philo->id, philo->rules);
		pthread_mutex_lock(philo->fork_r);
		ft_write("has taken a fork", philo->id, philo->rules);
	}
	ft_start_eating(philo);
	ft_write("is eating", philo->id, philo->rules);
	ft_usleep(philo->teat);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_lock(&philo->rules->meal_lock);
	philo->eating = 0;
	philo->n_meals++;
	pthread_mutex_unlock(&philo->rules->meal_lock);
}

void	*ft_rtn(void *parameters)
{
	t_phil	*philo;

	philo = (t_phil *)parameters;
	if (philo->rules->n_phil == 1)
	{
		pthread_mutex_lock(philo->fork_l);
		ft_write("has taken a fork", philo->id, philo->rules);
		ft_usleep(philo->tdie);
		pthread_mutex_unlock(philo->fork_l);
	}
	while (ft_loop(philo))
	{
		ft_thinking(philo);
		ft_eating(philo);
		ft_sleep(philo);
	}
	return (parameters);
}
