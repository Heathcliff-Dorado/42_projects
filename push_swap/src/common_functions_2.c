/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:00:49 by hdorado           #+#    #+#             */
/*   Updated: 2023/07/16 21:18:44 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common_functions.h"

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

void	ft_error_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a))
		ft_clean(stack_a);
	if ((*stack_b))
		ft_clean(stack_b);
	ft_putstr_fd("Error\n", 2);
}

long int	ft_atoli(const char *nptr)
{
	long int	i;
	long int	num;
	long int	sign;

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

int	atoi_check(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
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
	if (ft_atoli(nptr) > 2147483647 || ft_atoli(nptr) < -2147483648)
		return (0);
	return (1);
}

int	populate_stack(t_stack **stack, int n_elements, char **elements)
{
	int	i;

	i = 1;
	while (i < n_elements)
	{
		if (atoi_check(elements[i]) == 0)
			return (0);
		if (add_position(stack, ft_atoi(elements[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}
