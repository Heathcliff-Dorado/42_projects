/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:47:32 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/12 14:09:10 by hdorado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_confirmation(t_stack **stack, int elements)
{
	int	i;

	i = -1;
	while (++i < elements)
	{
		if ((*stack)->value != i)
			return (0);
		(*stack) = (*stack)->next;
	}
	return (1);
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
