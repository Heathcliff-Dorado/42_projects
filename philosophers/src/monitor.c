/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:01:28 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/12 17:24:58 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_loop(t_phil *philo)
{
	int	ret;

	ret = 1;
	pthread_mutex_lock(&philo->rules->dead_lock);
	if (philo->rules->dead == 1)
		ret = 0;
	pthread_mutex_unlock(&philo->rules->dead_lock);
	return (ret);
}

int	ft_check_dead(t_conditions *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_phil)
	{
		pthread_mutex_lock(&rules->meal_lock);
		if (get_time() - rules->phil[i].last_meal >= rules->tdie)
		{
			pthread_mutex_unlock(&rules->meal_lock);
			ft_write("died", i + 1, rules);
			pthread_mutex_lock(&rules->dead_lock);
			rules->dead = 1;
			pthread_mutex_unlock(&rules->dead_lock);
			return (1);
		}
		pthread_mutex_unlock(&rules->meal_lock);
		i++;
	}
	return (0);
}

int	ft_check_finished(t_conditions *rules)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pthread_mutex_lock(&rules->meal_lock);
	while (i < rules->n_phil)
	{
		if (rules->phil[i].n_meals >= rules->req_eat)
			j++;
		i++;
	}
	pthread_mutex_unlock(&rules->meal_lock);
	if (j == rules->n_phil)
	{
		pthread_mutex_lock(&rules->dead_lock);
		rules->dead = 1;
		pthread_mutex_unlock(&rules->dead_lock);
		return (1);
	}
	else
		return (0);
}

void	*ft_monitor(void *parameters)
{
	t_conditions	*rules;

	rules = (t_conditions *)parameters;
	while (1)
	{
		if (ft_check_dead(rules) == 1 || ft_check_finished(rules) == 1)
			break;
	}
	return (parameters);
}
