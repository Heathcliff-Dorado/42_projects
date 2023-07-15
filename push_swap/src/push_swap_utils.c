/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:54 by hdorado           #+#    #+#             */
/*   Updated: 2023/07/15 13:49:33 by hdorado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate_overlap (t_stack **stack_1, t_stack **stack_2, int index, int min_moves)
{
	int	overlap;
	int	value;

	value = ft_get_value(stack_1, index);
	overlap = ft_find_overlap(stack_2, value, index, min_moves);
	if (overlap && (index > 0))
		{
			ft_rx(stack_1, stack_2, overlap);
			ft_r(stack_1, index - overlap, 'a');
			ft_r(stack_2, min_moves - index, 'b');
		}
		else if (overlap && (index < 0))
		{
			ft_rrx(stack_1, stack_2, overlap);
			ft_rr(stack_1, -index - overlap, 'a');
			ft_rr(stack_2, min_moves + index, 'b');
		}
}

void	ft_prepare_push(t_stack **stack_1, t_stack **stack_2, int index, int min_moves)
{
	int	value;

	value = ft_get_value(stack_1, index);
	if (index == 0)
	{
		if (ft_check_down(stack_2, value, min_moves))
			ft_r(stack_2, min_moves, 'b');
		else
			ft_rr(stack_2, min_moves, 'b');
	}
	else
	{
		if (ft_find_overlap(stack_2, value, index, min_moves))
			ft_rotate_overlap (stack_1, stack_2, index, min_moves);
		else
			ft_rotate_no_overlap(index, stack_1, stack_2, min_moves);
	}
	ft_push(stack_1, stack_2, 'b');
}

//This function will decide which number to push from a to b
//based on how many rotations are needed to correctly place the number.
void	ft_movenumber(t_stack **stack_1, t_stack **stack_2, t_stack **max, int elem_in_b)
{
	int	counter;
	int	min;
	int	index;

	counter = 0;
	min = 2147483647;
	index = 0;
	while (counter++ < elem_in_b)
	{
		if (min > ft_cm_next(stack_2, stack_1, max, counter))
		{
			min = ft_cm_next(stack_2, stack_1, max, counter);
			index = counter;
		}
		if (min > ft_cm_previous(stack_2, stack_1, max, counter))
		{
			min = ft_cm_previous(stack_2, stack_1, max, counter);
			index = counter * -1;
		}
	}
	ft_prepare_push(stack_1, stack_2, index, min);
	ft_new_max(stack_2, max, elem_in_b + 1);
}

void	ft_s_r(t_stack **stack)
{
	ft_swap(stack, 'a');
	ft_r(stack, 1, 'a');
}

void	ft_s_rr(t_stack **stack)
{
	ft_swap(stack, 'a');
	ft_rr(stack, 1, 'a');
}
