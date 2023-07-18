/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:45:55 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/18 23:57:49 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Brings the second stack all the way up until it finds the max
void	ft_final_sort(t_stack **stack_2, t_stack **max)
{
	int		min;
	int		i;
	t_stack	*tmp;

	i = 0;
	min = 0;
	tmp = (*stack_2);
	while ((*stack_2)->value != (*max)->value)
	{
		(*stack_2) = (*stack_2)->next;
		i++;
	}
	(*stack_2) = tmp;
	while ((*stack_2)->value != (*max)->value)
	{
		(*stack_2) = (*stack_2)->previous;
		min++;
	}
	(*stack_2) = tmp;
	if (i > min)
		ft_rr(stack_2, min, 'b');
	else
		ft_r(stack_2, i, 'b');
}

void	ft_pushswap_large(t_stack **s_1, t_stack **s_2, t_stack **max, int el)
{
	int	i;

	ft_organize_3(s_1, el);
	i = 0;
	if (el != 3)
		ft_final_sort(s_2, max);
	while (i < el - 3)
	{
		if ((*s_1)->value == (*s_1)->previous->value + 1)
			ft_rr(s_1, 1, 'a');
		else if (((*s_1)->value == (*s_2)->value + 1)
			|| (*s_2)->value == el - 1)
		{
			ft_push(s_2, s_1, 'a');
			i++;
		}
		else
			ft_rr(s_1, 1, 'a');
	}
}

//This function will organize the stacks using the mechanical turk algorithm
void	ft_push_swap(t_stack **s_1, t_stack **s_2, int el)
{
	int		i;
	t_stack	*max;

	i = 0;
	max = (*s_1);
	if (el > 3)
		ft_push(s_1, s_2, 'b');
	if (el > 4)
	{
		ft_push(s_1, s_2, 'b');
		max = (*s_2);
		if ((*s_2)->value < (*s_2)->next->value)
		{
			ft_swap(s_2, 'b');
			max = (*s_2);
		}
	}
	while (i++ < el - 5)
		ft_movenumber(s_1, s_2, &max, 2 + i);
	if (el > 2)
		ft_pushswap_large(s_1, s_2, &max, el);
	while ((*s_1)->value != 0)
		ft_rr(s_1, 1, 'a');
	(*s_2) = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	argc = ft_retrieve_value(argc, argv, &stack_a);
	if (argc == 0 || modify_stack(&stack_a, &stack_b, argc) == 0)
	{
		ft_error_push_swap(&stack_a, &stack_b);
		return (0);
	}
	ft_clean(&stack_a);
	stack_a = NULL;
	if (ft_confirmation(&stack_b, argc - 1) == 0)
		ft_push_swap(&stack_b, &stack_a, argc - 1);
	ft_clean(&stack_a);
	ft_clean(&stack_b);
}
