#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "../lib/libft/libft.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_conditions {
	u_int64_t		teat;
	u_int64_t		tdie;
	u_int64_t		tsleep;
	int				n_phil;
	int				req_eat;
	int				finished;
	int				dead;
	pthread_t		*tpid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_phil			*phil;
}				t_conditions;

typedef struct s_phil {
	int				id;
	int				dead;
	int				n_meals;
	u_int64_t		teat;
	u_int64_t		tdie;
	u_int64_t		tsleep;
	u_int64_t		start;
	u_int64_t		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	t_conditions	*rules;
}				t_phil;

//Functions in main
int	ft_valid_atoi(char *str);
int	ft_check_args(int argc, char **argv, t_conditions *rules);
void	ft_init_phil(t_conditions *rules);
int	ft_alloc(t_conditions *rules);
int	ft_start(t_conditions *rules);
//Functions in monitor
int	ft_check_dead(t_conditions *rules);
void	*ft_monitor(void *parameters);
//Functions in routine
void	*ft_routine(void *parameters);
//Functions in utils
u_int64_t	get_time(void);
void	ft_write(char *str, int i, t_conditions *rules);

#endif
