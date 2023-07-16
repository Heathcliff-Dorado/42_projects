/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:54 by hdorado           #+#    #+#             */
/*   Updated: 2023/07/16 14:42:38 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate_overlap(t_stack **s_1, t_stack **s_2, int index, int min)
{
	int	overlap;
	int	value;

	value = ft_get_value(s_1, index);
	overlap = ft_find_overlap(s_2, value, index, min);
	if (overlap && (index > 0))
	{
		ft_rx(s_1, s_2, overlap);
		ft_r(s_1, index - overlap, 'a');
		ft_r(s_2, min - index, 'b');
	}
	else if (overlap && (index < 0))
	{
		ft_rrx(s_1, s_2, overlap);
		ft_rr(s_1, -index - overlap, 'a');
		ft_rr(s_2, min + index, 'b');
	}
}

void	ft_prepare_push(t_stack **s_1, t_stack **s_2, int index, int min)
{
	int	value;

	value = ft_get_value(s_1, index);
	if (index == 0)
	{
		if (ft_check_down(s_2, value, min))
			ft_r(s_2, min, 'b');
		else
			ft_rr(s_2, min, 'b');
	}
	else
	{
		if (ft_find_overlap(s_2, value, index, min))
			ft_rotate_overlap (s_1, s_2, index, min);
		else
			ft_rotate_no_overlap(index, s_1, s_2, min);
	}
	ft_push(s_1, s_2, 'b');
}

//This function will decide which number to push from a to b
//based on how many rotations are needed to correctly place the number.
void	ft_movenumber(t_stack **s_1, t_stack **s_2, t_stack **max, int el_b)
{
	int	counter;
	int	min;
	int	index;

	counter = 0;
	min = 2147483647;
	index = 0;
	while (counter++ < el_b)
	{
		if (min > ft_cm_next(s_2, s_1, max, counter))
		{
			min = ft_cm_next(s_2, s_1, max, counter);
			index = counter;
		}
		if (min > ft_cm_pr(s_2, s_1, max, counter))
		{
			min = ft_cm_pr(s_2, s_1, max, counter);
			index = counter * -1;
		}
	}
	ft_prepare_push(s_1, s_2, index, min);
	ft_new_max(s_2, max, el_b + 1);
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
