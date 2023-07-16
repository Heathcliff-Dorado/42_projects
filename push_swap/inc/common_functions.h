/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:22:51 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/16 21:54:22 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_FUNCTIONS_H
# define COMMON_FUNCTIONS_H

# include "../lib/libft/libft.h"

typedef struct s_stack
{
	struct s_stack		*previous;
	struct s_stack		*next;
	int					value;
}				t_stack;

//common_functions_3
int		ft_confirmation(t_stack **stack, int elements);
void	ft_free_array(char **elements);
//common_functions_2
int		add_position(t_stack **stack, int element);
long int		ft_atoli(const char *nptr);
void	ft_error_push_swap(t_stack **stack_a, t_stack **stack_b);
int		atoi_check(const char *nptr);
int		populate_stack(t_stack **stack, int n_elements, char **elements);
//common_functions
int		ft_clean(t_stack **stack);
int		ft_ranker(t_stack **source, int n_elements, int value);
int		modify_stack(t_stack **source, t_stack **dest, int n_elements);
int		populate_stack_str(t_stack **stack, int n_elements, char **elements);
int		ft_retrieve_value(int argc, char **argv, t_stack **stack_a);

#endif
