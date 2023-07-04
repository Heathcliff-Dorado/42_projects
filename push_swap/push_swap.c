/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:45:55 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/05 00:03:23 by hdorado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	add_position(t_stack **stack, int element)
{
	t_stack	*new_position;

	new_position = (t_stack *) malloc(sizeof(t_stack));
	if (!new_position)
		return (0);
	new_position->value = element;
	if ((*stack))
	{
		new_position->previous = (*stack)->previous;
		new_position->next = (*stack);
		(*stack)->previous->next = new_position;
		(*stack)->previous = new_position;
	}
	else
	{
		new_position->next = new_position;
		new_position->previous = new_position;
		(*stack) = new_position;
	}
	return (1);
}

int	modify_stack(t_stack **source, t_stack **dest, int n_elements)
{
	int	new_value;
	int	counter;
	int	counter_b;
	int	tmp;
	
	counter = 1;
	tmp = (*source)->value;
	(*source) = (*source)->next;
	while (counter < n_elements)
	{
		new_value = 0;
		counter_b = 2;
		while (counter_b < n_elements)
		{
			if (tmp == (*source)->value)
			{
				ft_printf("Error\n");
				return (0);
			}
			else if (tmp > (*source)->value)
				new_value++;
			(*source) = (*source)->next;
			counter_b++;
		}
		if (add_position(dest, new_value) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		counter++;
		(*source) = (*source)->next;
		tmp = (*source)->value;
		(*source) = (*source)->next;
	}
	(*source) = (*source)->previous;
	return (1);
}

int	atoi_check(const char *nptr)
{
	int	i;

	i = 0;
	while(nptr[i])
	{
		if (nptr[i] < 9 || nptr[i] > '9')
			return (0);
		if (nptr[i] > 13 && nptr[i] < '0')
		{
			if (nptr[i] != 32 && nptr[i] != '-' && nptr[i] != '+')
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - 48);
		i++;
	}
	return (sign * num);
}

int	ft_clean(t_stack **stack)
{
	t_stack	*tmp;
	
	if (!(*stack))
		return (0);
	(*stack)->next = NULL;
	(*stack) = (*stack)->previous;
	while ((*stack)->next)
	{
		tmp = (*stack)->previous;
		free((*stack));
		(*stack) = tmp;
	}
	free((*stack));
	return(0);
}

int	populate_stack(t_stack **stack, int n_elements, char **elements)
{
	int	i;

	i = 1;
	while (i < n_elements)
	{
		if (atoi_check(elements[i]) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		if (add_position(stack, ft_atoi(elements[i])) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);

}

void	ft_swap(t_stack **donor, t_stack **receiver)
{
	if (!(*receiver))
	{
		(*receiver) = (*donor);
		(*donor)->previous->next = (*donor)->next;
		(*donor)->next->previous = (*donor)->previous;
		(*donor) = (*donor)->next;
		(*receiver)->previous = (*receiver);
		(*receiver)->next = (*receiver);
	}
	else
	{
		(*donor)->previous->next = (*donor)->next;
		(*donor)->next->previous = (*donor)->previous;
		(*receiver)->previous->next = (*donor);
		(*donor)->previous = (*receiver)->previous;
		(*receiver)->previous = (*donor);
		(*donor) = (*donor)->next;
		(*receiver)->previous->next = (*receiver);
		(*receiver) = (*receiver)->previous;
	}
}

void	ft_push_swap(t_stack **stack_1, t_stack **stack_2, int elements)
{
	int	i;
	int j;

	i = 0;
	while (((elements - 1) >> i) | 0)
	{
		j = 0;
		while (j < elements)
		{
			if (((*stack_1)->value >> i) & 1)
			{
				ft_printf("ra\n");
				(*stack_1) = (*stack_1)->next;
			}
			else
			{
				ft_printf("pa\n");
				ft_swap(stack_1, stack_2);
			}
			j++;
		}
		while ((*stack_2) && ((*stack_2)->value != (*stack_2)->next->value))
		{
			ft_printf("pb\n");
			ft_swap(stack_2, stack_1);
		}
		if ((*stack_2))
		{
			ft_printf("pb\n");
			(*stack_1)->previous->next = (*stack_2);
			(*stack_2)->previous = (*stack_1)->previous;
			(*stack_1)->previous = (*stack_2);
			(*stack_2)->next = (*stack_1);
			(*stack_1) = (*stack_2);
			(*stack_2) = NULL;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	counter;

	counter = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		{
			//function for elements as part of a list with " "
		}
	if (populate_stack(&stack_a, argc, argv) == 0)
	{
		ft_clean(&stack_a);
		ft_printf("Error\n");
		return (0);
	}
	while (counter < argc)
	{
		ft_printf("The next value ranking %d followed by %d\n", stack_a->value, stack_a->next->value);
		stack_a = stack_a->next;
		counter++;
	}
	if (modify_stack(&stack_a, &stack_b, argc) == 0)
	{
		ft_clean(&stack_a);
		ft_clean(&stack_b);
		return (0);
	}
	ft_clean(&stack_a);
	stack_a = NULL;
	if (argc - 1 < 6)
	{
		//function for small list of elements
	}
	ft_push_swap(&stack_b, &stack_a, argc - 1);
	counter = 1;
	while (counter < argc)
	{
		ft_printf("The next value ranking %d followed by %d\n", stack_b->value, stack_b->next->value);
		stack_b = stack_b->next;
		counter++;
	}
	ft_clean(&stack_a);
	ft_clean(&stack_b);
}
