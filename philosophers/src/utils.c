/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:56:45 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/12 17:01:54 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

u_int64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_write(char *str, int i, t_conditions *rules)
{
	u_int64_t time;

	pthread_mutex_lock(&rules->writing);
	time = get_time() - rules->phil[i - 1].start;
	//time = 200;
	pthread_mutex_lock(&rules->dead_lock);
	if (rules->dead != 1)
	{
		printf("%d %d %s\n", (int) time, i, str);
	}
	pthread_mutex_unlock(&rules->dead_lock);
	pthread_mutex_unlock(&rules->writing);
}
