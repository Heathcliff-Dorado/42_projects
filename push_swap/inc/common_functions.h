/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:22:51 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/12 13:08:07 by hdorado          ###   ########.fr       */
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

int		add_position(t_stack **stack, int element);
int		ft_atoli(const char *nptr);
int		atoi_check(const char *nptr);
int		populate_stack(t_stack **stack, int n_elements, char **elements);
int		ft_clean(t_stack **stack);
int		modify_stack(t_stack **source, t_stack **dest, int n_elements);
int		populate_stack_str(t_stack **stack, int n_elements, char **elements);
void	ft_error_push_swap(t_stack **stack_a, t_stack **stack_b);

#endif
