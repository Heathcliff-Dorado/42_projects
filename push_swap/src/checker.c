/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:24:22 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/16 14:34:57 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_do_swap(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

int	ft_rotate_checker(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strlen(str) == 4)
	{
		if (ft_strncmp(str, "rrr\n", 4) == 0)
			ft_rrotate_both(stack_a, stack_b);
		else if (ft_strncmp(str, "rra\n", 4) == 0)
			ft_rrotate(stack_a);
		else if (ft_strncmp(str, "rrb\n", 4) == 0)
			ft_rrotate(stack_b);
		else
			return (0);
	}
	else
	{
		if (ft_strncmp(str, "rr\n", 3) == 0)
			ft_rotate_both(stack_a, stack_b);
		else if (ft_strncmp(str, "ra\n", 3) == 0)
			ft_rotate(stack_a);
		else if (ft_strncmp(str, "rb\n", 3) == 0)
			ft_rotate(stack_b);
		else
			return (0);
	}
	return (1);
}

int	ft_command(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str[0] == 'r')
	{
		if (ft_rotate_checker(stack_a, stack_b, str) == 0)
			return (0);
	}
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_do_swap(stack_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_do_swap(stack_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		ft_do_swap(stack_a);
		ft_do_swap(stack_b);
	}
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_do_push(stack_a, stack_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_do_push(stack_b, stack_a);
	else
		return (0);
	return (1);
}

int	ft_read_lines(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_strlen(str) > 4 || ft_strlen(str) < 3)
		{
			ft_error_push_swap(stack_a, stack_b);
			return (0);
		}
		if (ft_command(stack_b, stack_a, str) == 0)
		{
			ft_error_push_swap(stack_a, stack_b);
			return (0);
		}
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	argc = ft_retrieve_value(argc, argv, &stack_a);
	if (argc == 0 || modify_stack(&stack_a, &stack_b, argc) == 0)
	{
		ft_error_push_swap(&stack_a, &stack_b);
		return (0);
	}
	if (ft_read_lines(&stack_a, &stack_b) == 0)
		return (0);
	if (stack_a)
		ft_clean(&stack_a);
	if (ft_confirmation(&stack_b, argc - 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_clean(&stack_b);
	return (0);
}
