/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:51:20 by hdorado           #+#    #+#             */
/*   Updated: 2023/07/17 13:06:51 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_overlap_equal(int index, t_stack **stack_2, int value)
{
	int	i;

	i = 0;
	if (index > 0)
	{
		while (i++ < index)
		{
			if (ft_check_down(stack_2, value, i))
				return (i);
		}
	}
	else
	{
		while (i-- > index)
		{
			if (ft_check_up(stack_2, value, abs(i)))
				return (abs(i));
		}
	}
	return (0);
}

//Checks how many rotations can be saved because they are in the same direction
int	ft_find_overlap(t_stack **stack_2, int value, int index, int min)
{
	if (abs(index) == min)
		return (ft_overlap_equal(index, stack_2, value));
	else
	{
		if ((index > 0) && (ft_check_down(stack_2, value, min) == 1))
			return (index);
		else if ((index < 0) && (ft_check_up(stack_2, value, abs(min)) == 1))
			return (abs(index));
	}
	return (0);
}

void	ft_rotate_no_overlap(int index, t_stack **s_1, t_stack **s_2, int min)
{
	if (index > 0)
	{
		ft_r(s_1, index, 'a');
		ft_rr(s_2, min - index, 'b');
	}
	else if (index < 0)
	{
		ft_rr(s_1, -index, 'a');
		ft_r(s_2, min + index, 'b');
	}
}

void	ft_special_condition(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->previous->value)
	{
		if ((*stack)->next->value > (*stack)->previous->value)
			ft_s_rr(stack);
		else
			ft_r(stack, 1, 'a');
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value < (*stack)->previous->value)
	{
		if ((*stack)->next->value > (*stack)->previous->value)
			ft_s_r(stack);
	}
	else
	{
		if ((*stack)->next->value > (*stack)->previous->value)
			ft_rr(stack, 1, 'a');
		else
			ft_swap(stack, 'a');
	}
}

void	ft_organize_3(t_stack **stack, int elm)
{
	if (elm == 3 || !(((*stack)->value == elm - 1)
			|| ((*stack)->next->value == elm - 1)
			|| ((*stack)->previous->value == elm - 1)))
		ft_special_condition(stack);
	else
	{
		if ((*stack)->value < (*stack)->next->value)
		{
			if ((*stack)->next->value < (*stack)->previous->value)
				ft_rr(stack, 1, 'a');
			else if ((*stack)->value < (*stack)->previous->value)
				ft_swap(stack, 'a');
			else
				ft_r(stack, 1, 'a');
		}
		else
		{
			if ((*stack)->value < (*stack)->previous->value)
				ft_s_rr(stack);
			else if ((*stack)->next->value > (*stack)->previous->value)
				ft_s_r(stack);
		}
	}
}
