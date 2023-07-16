/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:47:32 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/16 21:24:16 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_do_push(t_stack **donor, t_stack **receiver)
{
	{
		(*donor)->previous->next = (*donor)->next;
		(*donor)->next->previous = (*donor)->previous;
		if (!(*receiver))
		{
			(*receiver) = (*donor);
			(*donor) = (*donor)->next;
			(*receiver)->previous = (*receiver);
			(*receiver)->next = (*receiver);
		}
		else
		{
			(*receiver)->previous->next = (*donor);
			(*donor)->previous = (*receiver)->previous;
			(*receiver)->previous = (*donor);
			(*donor) = (*donor)->next;
			(*receiver)->previous->next = (*receiver);
			(*receiver) = (*receiver)->previous;
		}
	}
}

void	ft_rrotate_both(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a) = (*stack_a)->previous;
	(*stack_b) = (*stack_b)->previous;
}

void	ft_rrotate(t_stack **stack)
{
	(*stack) = (*stack)->previous;
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
}

void	ft_rotate(t_stack **stack)
{
	(*stack) = (*stack)->next;
}
