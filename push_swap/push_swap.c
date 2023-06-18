/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:45:55 by hdorado-          #+#    #+#             */
/*   Updated: 2023/06/18 15:31:30 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv)
{
	t_stack	*stack_a;

	if (argc == 1)
		return (0);
	if (populate_stack(stack_a, argc, argv) == 0)
	{
		error_clean(stack_a);
		return (0);
	}

}

int	populate_stack(t_stack *stack, int n_elements, char *elements)
{
	int	i;
	int	value;

	i = 1;
	while (i < n_elements)
	{
		if (atoi_check(elements[i]) == 0)
			return (0);
		if (add_position(stack, ft_atoi(elements[i])) == 0)
			return (0);
		i++;
	}

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
			if (nptr[i] != 32 || nptr[i] != '-' || nptr[i] != '+')
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

int	add_position(t_stack *stack, void *element)
{
	t_stack	*new_position;

	new_position = malloc(sizeof(t_stack));
	if (!new_position)
		return (0);
	new_position->value = element;
	if (!stack)
	{
		new_position->next = new_position;
		new_position->previous = new_position;
		stack = new_position;
	}
	else
	{
		new_position->previous = stack->previous;
		new_position->next = stack;
		stack->previous = new_position;
		stack = new_position->previous;
		stack = new_position;
		stack = new_position->next;
	}
	return (1);
}
