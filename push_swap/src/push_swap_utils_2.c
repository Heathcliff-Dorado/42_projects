/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:50:21 by hdorado           #+#    #+#             */
/*   Updated: 2023/07/17 13:06:24 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	ft_printf("s%c\n", c);
}

void	ft_push(t_stack **donor, t_stack **receiver, char c)
{
	if ((*donor))
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
		ft_printf("p%c\n", c);
	}
}

void	ft_rrx(t_stack **stack_a, t_stack **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("rrr\n");
		(*stack_a) = (*stack_a)->previous;
		(*stack_b) = (*stack_b)->previous;
		i++;
	}
}

void	ft_rx(t_stack **stack_a, t_stack **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("rr\n");
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = (*stack_b)->next;
		i++;
	}
}

void	ft_rr(t_stack **stack, int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("rr%c\n", c);
		(*stack) = (*stack)->previous;
		i++;
	}
}
