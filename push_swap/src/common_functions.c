/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:51:50 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/15 14:27:10 by hdorado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common_functions.h"

//Same but if args are passed as a string
int	populate_stack_str(t_stack **stack, int n_elements, char **elements)
{
	int	i;

	i = 0;
	while (i < n_elements)
	{
		if (atoi_check(elements[i]) == 0)
			return (0);
		if (add_position(stack, ft_atoi(elements[i])) == 0)
			return (0);
		free(elements[i]);
		i++;
	}
	free(elements);
	return (1);
}

//Makes sure that the stack is freed, if there is any
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
	return (0);
}

int	ft_ranker(t_stack **source, int n_elements, int value)
{
	int	counter;
	int	new_value;

	counter = 2;
	new_value = 0;
	while (counter++ < n_elements)
	{
		if (value == (*source)->value)
			return (-1);
		else if (value > (*source)->value)
			new_value++;
		(*source) = (*source)->next;
	}
	return (new_value);
}

int	modify_stack(t_stack **source, t_stack **dest, int n_elements)
{
	int	new_value;
	int	counter;
	int	tmp;

	counter = 1;
	while (counter++ < n_elements)
	{
		tmp = (*source)->value;
		(*source) = (*source)->next;
		new_value = ft_ranker(source, n_elements, tmp);
		if (new_value < 0)
			return (0);
		if (add_position(dest, new_value) == 0)
			return (0);
		(*source) = (*source)->next;
	}
	(*source) = (*source)->previous;
	return (1);
}

int	ft_retrieve_value(int argc, char **argv, t_stack **stack_a)
{
	char	**str;

	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (str == 0)
			return (0);
		argc = 0;
		while (str[argc])
			argc++;
		if (populate_stack_str(stack_a, argc, str) == 0)
			return (0);
		argc++;
	}
	else if (populate_stack(stack_a, argc, argv) == 0)
		return (0);
	return (argc);
}
