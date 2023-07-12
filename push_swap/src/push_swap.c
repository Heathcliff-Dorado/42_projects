/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:45:55 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/12 14:09:14 by hdorado          ###   ########.fr       */
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

void	ft_r(t_stack **stack, int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("r%c\n", c);
		(*stack) = (*stack)->next;
		i++;
	}
}

//Check if stack_2 has a new max and keeps it as a reference
void	ft_new_max(t_stack **stack, t_stack **max, int elem_in_b)
{
	int	i;

	i = 0;
	while (i < elem_in_b)
	{
		if ((*stack)->value > (*max)->value)
			(*max) = (*stack);
		(*stack) = (*stack)->next;
		i++;
	}
}

int	ft_max(int moves, int counter)
{
	if (moves > counter)
		return (moves);
	return (counter);
}

int	ft_cm_next(t_stack **stack_2, t_stack **stack_1, t_stack **max, int index, int elem_in_b)
{
	t_stack	*tmp;
	int		i;
	int		value;
	int		moves;

	tmp = (*stack_1);
	i = 0;
	moves = 0;
	while (i < index)
	{
		(*stack_1) = (*stack_1)->next;
		i++;
	}
	value = (*stack_1)->value;
	(*stack_1) = tmp;
	tmp = (*stack_2);
	if (value > (*max)->value || value < (*max)->previous->value)
	{
		while ((*stack_2)->value != (*max)->value)
		{
			(*stack_2) = (*stack_2)->next;
			moves++;
		}
	}
	else
	{
		while (value < (*stack_2)->value || value > (*stack_2)->previous->value)
		{
			(*stack_2) = (*stack_2)->next;
			moves++;
		}
	}
	(*stack_2) = tmp;
	if ((elem_in_b - moves + index) < ft_max(moves, index))
		return (elem_in_b - moves + index);
	else
		return (ft_max(moves, index));
}

//Check count_moves_next for explanation
int	ft_cm_previous(t_stack **stack_2, t_stack **stack_1, t_stack **max, int counter, int elem_in_b)
{
	t_stack	*tmp;
	int		i;
	int		value;
	int		moves;

	tmp = (*stack_1);
	i = 0;
	moves = 0;
	while (i < counter)
	{
		(*stack_1) = (*stack_1)->previous;
		i++;
	}
	value = (*stack_1)->value;
	(*stack_1) = tmp;
	tmp = (*stack_2);
	if (value > (*max)->value || value < (*max)->previous->value)
	{
		while ((*stack_2)->value != (*max)->value)
		{
			(*stack_2) = (*stack_2)->previous;
			moves++;
		}
	}
	else
	{
		while (value < (*stack_2)->value || value > (*stack_2)->previous->value)
		{
			(*stack_2) = (*stack_2)->previous;
			moves++;
		}
	}
	(*stack_2) = tmp;
	if ((elem_in_b - moves + counter) < ft_max(moves, counter))
		return (elem_in_b - moves + counter);
	else
		return (ft_max(moves, counter));
}

//Saves the value stored index positions away
int	ft_check_stack_value(t_stack **stack, int index)
{
	int		i;
	t_stack	*tmp;
	int		value;

	i = 0;
	tmp = (*stack);
	if (index > 0)
	{
		while (i++ < index)
			(*stack) = (*stack)->next;
	}
	else
	{
		while (i-- > index)
			(*stack) = (*stack)->previous;
	}
	value = (*stack)->value;
	(*stack) = tmp;
	return (value);
}

//Check if the correct position is achieved moving with next
int	ft_check_down(t_stack **stack, int value, int index)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack);
	while (i++ < index)
		(*stack) = (*stack)->next;
	if (((*stack)->value > (*stack)->next->value) && ((*stack)->value > (*stack)->previous->value))
	{
		if ((value > (*stack)->value) || (value < (*stack)->previous->value))
		{
			(*stack) = tmp;
			return (1);
		}
	}
	else if ((value > (*stack)->value) && (value < (*stack)->previous->value))
	{
		(*stack) = tmp;
		return (1);
	}
	(*stack) = tmp;
	return (0);
}

//Check check_down to understand the code
int	ft_check_up(t_stack **stack, int value, int index)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack);
	while (i++ < index)
		(*stack) = (*stack)->previous;
	if (((*stack)->value > (*stack)->next->value) && ((*stack)->value > (*stack)->previous->value))
	{
		if ((value > (*stack)->value) || (value < (*stack)->previous->value))
		{
			(*stack) = tmp;
			return (1);
		}
	}
	else if ((value > (*stack)->value) && (value < (*stack)->previous->value))
	{
		(*stack) = tmp;
		return (1);
	}
	(*stack) = tmp;
	return (0);
}

//Checks how many rotations can be saved because they are in the same direction
int	ft_find_overlap(t_stack **stack_2, int value, int index, int min_moves)
{
	int	i;

	i = 0;
	if (abs(index) == min_moves)
	{
		if (index > 0)
		{
			while (i++ < index)
			{
				if (ft_check_down(stack_2, value, i))
					return (i);
			}
		}
		else
		{
			while (i-- > index)
			{
				if (ft_check_up(stack_2, value, abs(i)))
					return (abs(i));
			}
		}
	}
	else
	{
		if ((index > 0) && (ft_check_down(stack_2, value, min_moves) == 1))
			return (index);
		else if ((index < 0) && (ft_check_up(stack_2, value, abs(min_moves)) == 1))
			return (abs(index));
	}
	return (0);
}

void	ft_prepare_push(t_stack **stack_1, t_stack **stack_2, int index, int min_moves)
{
	int	value;
	int	overlap;

	value = ft_check_stack_value(stack_1, index);
	if (index == 0)
	{
		if (ft_check_down(stack_2, value, min_moves))
			ft_r(stack_2, min_moves, 'b');
		else
			ft_rr(stack_2, min_moves, 'b');
	}
	else
	{
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
		else if ((index > 0) && overlap == 0)
		{
			ft_r(stack_1, index, 'a');
			ft_rr(stack_2, min_moves - index, 'b');
		}
		else if ((index < 0) && overlap == 0)
		{
			ft_rr(stack_1, -index, 'a');
			ft_r(stack_2, min_moves + index, 'b');
		}
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
	while (counter < elem_in_b)
	{
		if (min > ft_cm_next(stack_2, stack_1, max, counter, elem_in_b))
		{
			min = ft_cm_next(stack_2, stack_1, max, counter, elem_in_b);
			index = counter;
		}
		counter++;
	}
	counter = 0;
	while (counter < elem_in_b)
	{
		if (min > ft_cm_previous(stack_2, stack_1, max, counter, elem_in_b))
		{
			min = ft_cm_previous(stack_2, stack_1, max, counter, elem_in_b);
			index = counter * -1;
		}
		counter++;
	}
	ft_prepare_push(stack_1, stack_2, index, min);
	ft_new_max(stack_2, max, elem_in_b + 1);
}

void	ft_special_condition(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->previous->value)
	{
		if ((*stack)->next->value > (*stack)->previous->value)
		{
			ft_swap(stack, 'a');
			ft_rr(stack, 1, 'a');
		}
		else
			ft_r(stack, 1, 'a');
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value < (*stack)->previous->value)
	{
		if ((*stack)->next->value > (*stack)->previous->value)
		{
			ft_swap(stack, 'a');
			ft_r(stack, 1, 'a');
		}
	}
	else
	{
		if ((*stack)->next->value > (*stack)->previous->value)
			ft_rr(stack, 1, 'a');
		else
			ft_swap(stack, 'a');
	}
}

void	ft_organize_3(t_stack **stack, int elm)
{
	if (elm == 3 || !(((*stack)->value == elm - 1)
			|| ((*stack)->next->value == elm - 1)
			|| ((*stack)->previous->value == elm - 1)))
		ft_special_condition(stack);
	else
	{
		if ((*stack)->value < (*stack)->next->value)
		{
			if ((*stack)->next->value < (*stack)->previous->value)
				ft_rr(stack, 1, 'a');
			else if ((*stack)->value < (*stack)->previous->value)
				ft_swap(stack, 'a');
			else
				ft_r(stack, 1, 'a');
		}
		else
		{
			if ((*stack)->value < (*stack)->previous->value)
			{
				ft_swap(stack, 'a');
				ft_rr(stack, 1, 'a');
			}
			else if ((*stack)->next->value > (*stack)->previous->value)
			{
				ft_swap(stack, 'a');
				ft_r(stack, 1, 'a');
			}
		}
	}
}

//Brings the second stack all the way up until it finds the max
void	ft_final_sort(t_stack **stack_2, t_stack **max)
{
	int		min;
	int		i;
	t_stack	*tmp;

	i = 0;
	min = 0;
	tmp = (*stack_2);
	while ((*stack_2)->value != (*max)->value)
	{
		(*stack_2) = (*stack_2)->next;
		i++;
	}
	(*stack_2) = tmp;
	while ((*stack_2)->value != (*max)->value)
	{
		(*stack_2) = (*stack_2)->previous;
		min++;
	}
	(*stack_2) = tmp;
	if (i > min)
		ft_rr(stack_2, min, 'b');
	else
		ft_r(stack_2, i, 'b');
}

//This function will organize the stacks using the mechanical turk algorithm
void	ft_push_swap(t_stack **s_1, t_stack **s_2, int el)
{
	int		i;
	t_stack	*max;

	i = 0;
	if (el > 3)
	{
		max = (*s_1);
		ft_push(s_1, s_2, 'b');
	}
	if (el > 4)
	{
		ft_push(s_1, s_2, 'b');
		if ((*s_2)->value < (*s_2)->next->value)
		{
			ft_swap(s_2, 'b');
			max = (*s_2);
		}
	}
	while (i < el - 5)
	{
		ft_movenumber(s_1, s_2, &max, 2 + i);
		i++;
	}
	if (el > 2)
	{
		ft_organize_3(s_1, el);
		i = 0;
		if (el != 3)
			ft_final_sort(s_2, &max);
		while (i < el - 3)
		{
			if ((*s_1)->value == (*s_1)->previous->value + 1)
				ft_rr(s_1, 1, 'a');
			else if (((*s_1)->value == (*s_2)->value + 1)
				|| (*s_2)->value == el - 1)
			{
				ft_push(s_2, s_1, 'a');
				i++;
			}
			else
				ft_rr(s_1, 1, 'a');
		}
	}
	while ((*s_1)->value != 0)
		ft_rr(s_1, 1, 'a');
	(*s_2) = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (str == 0)
		{
			ft_error_push_swap(&stack_a, &stack_b);
			return (0);
		}
		argc = 0;
		while (str[argc])
			argc++;
		if (populate_stack_str(&stack_a, argc, str) == 0)
		{
			ft_error_push_swap(&stack_a, &stack_b);
			return (0);
		}
		argc++;
	}
	else if (populate_stack(&stack_a, argc, argv) == 0)
	{
		ft_clean(&stack_a);
		return (0);
	}
	if (modify_stack(&stack_a, &stack_b, argc) == 0)
	{
		ft_error_push_swap(&stack_a, &stack_b);
		return (0);
	}
	ft_clean(&stack_a);
	stack_a = NULL;
	ft_push_swap(&stack_b, &stack_a, argc - 1);
	ft_clean(&stack_a);
	ft_clean(&stack_b);
}
