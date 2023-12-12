/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:55:25 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/12 17:07:13 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_usleep(u_int64_t time)
{
	u_int64_t start;

	start = get_time();
	while (get_time() - start < time)
		usleep(500);
}

void	ft_thinking(t_phil *philo)
{
	ft_write("is thinking", philo->id, philo->rules);
}

void	ft_sleep(t_phil *philo)
{
	ft_write("is sleeping", philo->id, philo->rules);
	ft_usleep(philo->tsleep);
}

void	ft_eating(t_phil *philo)
{
	pthread_mutex_lock(&philo->rules->meal_lock);
	philo->last_meal = get_time();
	philo->n_meals++;
	pthread_mutex_unlock(&philo->rules->meal_lock);
	ft_write("is eating", philo->id, philo->rules);
	ft_usleep(philo->teat);
	pthread_mutex_lock(&philo->rules->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->rules->meal_lock);
}

void	*ft_routine(void *parameters)
{
	t_phil	*philo;

	philo = (t_phil *)parameters;
	if (philo->id % 2)
	{
		while (ft_loop(philo))
		{
			pthread_mutex_lock(philo->fork_l);
			ft_write("has taken a fork", philo->id, philo->rules);
			pthread_mutex_lock(philo->fork_r);
			ft_write("has taken a fork", philo->id, philo->rules);
			ft_eating(philo);
			pthread_mutex_unlock(philo->fork_l);
			pthread_mutex_unlock(philo->fork_r);
			ft_sleep(philo);
			ft_thinking(philo);
		}
	}
	else
	{
		while (ft_loop(philo))
		{
			pthread_mutex_lock(philo->fork_r);
			ft_write("has taken a fork", philo->id, philo->rules);
			pthread_mutex_lock(philo->fork_l);
			ft_write("has taken a fork", philo->id, philo->rules);
			ft_eating(philo);
			pthread_mutex_unlock(philo->fork_r);
			pthread_mutex_unlock(philo->fork_l);
			ft_sleep(philo);
			ft_thinking(philo);
		}
	}
	return (parameters);
}
