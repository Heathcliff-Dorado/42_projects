/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:51:17 by hdorado           #+#    #+#             */
/*   Updated: 2023/07/17 13:06:35 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//Saves the value stored index positions away

int	ft_get_value(t_stack **stack, int index)
{
	int		i;
	t_stack	*tmp;
	int		value;

	i = 0;
	tmp = (*stack);
	if (index > 0)
	{
		while (i++ < index)
			(*stack) = (*stack)->next;
	}
	else
	{
		while (i-- > index)
			(*stack) = (*stack)->previous;
	}
	value = (*stack)->value;
	(*stack) = tmp;
	return (value);
}

int	ft_cm_next(t_stack **s_2, t_stack **s_1, t_stack **max, int index)
{
	int		value;
	int		moves;
	int		elem_in_b;

	value = ft_get_value(s_1, index);
	moves = ft_get_min_moves(s_2, max, value);
	elem_in_b = ft_elem_in_b(s_2);
	if ((moves + index) < ft_max(elem_in_b - moves, index))
		return (moves + index);
	else
		return (ft_max(elem_in_b - moves, index));
}

//Check count_moves_next for explanation
int	ft_cm_pr(t_stack **s_2, t_stack **s_1, t_stack **max, int counter)
{
	int		value;
	int		moves;
	int		elem_in_b;

	value = ft_get_value(s_1, -counter);
	moves = ft_get_min_moves(s_2, max, value);
	elem_in_b = ft_elem_in_b(s_2);
	if ((elem_in_b - moves + counter) < ft_max(moves, counter))
		return (elem_in_b - moves + counter);
	else
		return (ft_max(moves, counter));
}

//Check if the correct position is achieved moving with next
int	ft_check_down(t_stack **stack, int value, int index)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack);
	while (i++ < index)
		(*stack) = (*stack)->next;
	if (((*stack)->value > (*stack)->next->value)
		&& ((*stack)->value > (*stack)->previous->value))
	{
		if ((value > (*stack)->value) || (value < (*stack)->previous->value))
		{
			(*stack) = tmp;
			return (1);
		}
	}
	else if ((value > (*stack)->value) && (value < (*stack)->previous->value))
	{
		(*stack) = tmp;
		return (1);
	}
	(*stack) = tmp;
	return (0);
}

//Check check_down to understand the code
int	ft_check_up(t_stack **stack, int value, int index)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack);
	while (i++ < index)
		(*stack) = (*stack)->previous;
	if (((*stack)->value > (*stack)->next->value)
		&& ((*stack)->value > (*stack)->previous->value))
	{
		if ((value > (*stack)->value) || (value < (*stack)->previous->value))
		{
			(*stack) = tmp;
			return (1);
		}
	}
	else if ((value > (*stack)->value) && (value < (*stack)->previous->value))
	{
		(*stack) = tmp;
		return (1);
	}
	(*stack) = tmp;
	return (0);
}
