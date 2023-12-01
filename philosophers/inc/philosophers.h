#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "../lib/libft/libft.h"

typedef struct s_conditions {
	int	t_eat;
	int	t_die;
	int	t_sleep;
	int	n_phil;
	int	req_eat;
}				t_conditions;
#endif
