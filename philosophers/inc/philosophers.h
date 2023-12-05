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
	int				dead;
	int				finished;
	pthread_t		*tpid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	t_phil			*phil;
}				t_conditions;

typedef struct s_phil {
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_muted_t	*fork_r;
}				t_phil;
#endif
