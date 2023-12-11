/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:55:25 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/11 22:20:40 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*ft_routine(void *parameters)
{
	t_phil	*philo;

	philo = (t_conditions *)parameters;
	philo->start = get_time();
	if (philo->id % 2)
		ft_thinking(philo); //DO!!
	while (ft_loop(philo))
	{
		pthread_mutex_lock(&philo->fork_l);
		ft_write("has taken a fork", philo->id, philo->rules);
		pthread_mutex_lock(&philo->fork_r);
		ft_write("has taken a fork", philo->id, philo->rules);
		ft_eating(philo); //DO!!
		pthread_mutex_unlock(&philo->fork_l);
		pthread_mutex_unlock(&philo->fork_r);
		ft_thinking(philo);
	}
}
