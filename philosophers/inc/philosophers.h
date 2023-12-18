/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:15:36 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/18 21:53:11 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "../lib/libft/libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_phil	t_phil;

typedef struct s_conditions {
	u_int64_t		teat;
	u_int64_t		tdie;
	u_int64_t		tsleep;
	int				n_phil;
	int				req_eat;
	int				dead;
	pthread_t		tpid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_phil			*ph;
}				t_conditions;

typedef struct s_phil {
	int				id;
	int				n_meals;
	int				dead;
	int				eating;
	u_int64_t		teat;
	u_int64_t		tdie;
	u_int64_t		tsleep;
	u_int64_t		start;
	u_int64_t		last_meal;
	pthread_t		thr;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	t_conditions	*rules;
}				t_phil;

//Functions in main
void		ft_init_phil(t_conditions *rules);
int			ft_alloc(t_conditions *rules);
void		ft_start(t_conditions *rules);
void		ft_clear_mutex(t_conditions *rules);
//Functions in arg_check.c
long int	ft_atoli(const char *str);
int			ft_valid_atoi(char *str);
int			ft_last_arg(int argc, char **argv);
int			ft_check_args(int argc, char **argv, t_conditions *rules);
//Functions in monitor
int			ft_loop(t_phil *philo);
int			ft_check_dead(t_conditions *rules);
int			ft_check_finished(t_conditions *rules);
void		*ft_monitor(void *parameters);
//Functions in routine
void		ft_usleep(u_int64_t time);
void		ft_thinking(t_phil *philo);
void		ft_sleep(t_phil *philo);
void		ft_eating(t_phil *philo);
void		*ft_rtn(void *parameters);
//Functions in utils
u_int64_t	get_time(void);
void		ft_write(char *str, int i, t_conditions *rules);

#endif
