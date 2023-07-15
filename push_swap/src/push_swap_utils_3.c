/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:51:14 by hdorado           #+#    #+#             */
/*   Updated: 2023/07/15 13:54:37 by hdorado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_r(t_stack **stack, int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("r%c\n", c);
		(*stack) = (*stack)->next;
		i++;
	}
}

//Check if stack_2 has a new max and keeps it as a reference
void	ft_new_max(t_stack **stack, t_stack **max, int elem_in_b)
{
	int	i;

	i = 0;
	while (i < elem_in_b)
	{
		if ((*stack)->value > (*max)->value)
			(*max) = (*stack);
		(*stack) = (*stack)->next;
		i++;
	}
}

int	ft_max(int moves, int counter)
{
	if (moves > counter)
		return (moves);
	return (counter);
}

int	ft_elem_in_b(t_stack **stack)
{
	int	elem_in_b;
	int	value;

	value = (*stack)->value;
	(*stack) = (*stack)->next;
	elem_in_b = 1;
	while (value != (*stack)->value)
	{
		elem_in_b++;
		(*stack) = (*stack)->next;
	}
	return (elem_in_b);
}

int	ft_get_min_moves(t_stack **stack, t_stack **max, int value)
{
	t_stack	*tmp;
	int		moves;

	moves = 0;
	tmp = (*stack);
	if (value > (*max)->value || value < (*max)->previous->value)
	{
		while ((*stack)->value != (*max)->value)
		{
			(*stack) = (*stack)->previous;
			moves++;
		}
	}
	else
	{
		while (value < (*stack)->value || value > (*stack)->previous->value)
		{
			(*stack) = (*stack)->previous;
			moves++;
		}
	}
	(*stack) = tmp;
	return (moves);
}
