#ifndef COMMON_FUNCTIONS_H
# define COMMON_FUNCTIONS_H

typedef struct s_stack
{
	struct s_stack		*previous;
	struct s_stack		*next;
	int			value;
}				t_stack;

# include "include/libft/libft.h"

#endif