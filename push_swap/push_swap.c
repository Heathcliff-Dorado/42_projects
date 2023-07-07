/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:45:55 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/07 21:59:00 by hdorado-         ###   ########.fr       */
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

/*void	ft_push_swap(t_stack **stack_1, t_stack **stack_2, int elements)
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
				ft_push(stack_1, stack_2, 'a');
			j++;
		}
		while ((*stack_2) && ((*stack_2)->value != (*stack_2)->next->value))
			ft_push(stack_2, stack_1, 'b');
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
}*/

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

void	ft_swap(t_stack **stack, char c)
{
	int tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	ft_printf("s%c\n", c);
}

void	ft_push(t_stack **donor, t_stack **receiver, char c)
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

	ft_printf("p%c\n", c);
}

// int	ft_find_min (int value, t_stack **stack_b, int *max, int *min)
// {
// 	int	min_count;
// 	t_stack	*tmp;

// 	tmp = (*stack_b);
// 	min_count = 0;
// 	if (value != *max || value != *min)
// 	{
// 		while (value < (*stack_b)->previous || value > (*stack_b)->next)
// 		{
// 			min_count++;
// 			(*stack_b)->next;
// 		}
// 	}
// }

void	ft_organize_3(t_stack **stack)
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

int ft_count_moves_down(t_stack **stack_2, t_stack **stack_1, t_stack **max, int counter, int elem_in_b)
{
	t_stack	*tmp;
	int	i;
	int value;
	int	moves;

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
		while (value > (*stack_2)->value || value < (*stack_2)->previous->value)
		{
			(*stack_2) = (*stack_2)->previous;
			moves++;
		}
	}
	(*stack_2) = tmp;
	if ((elem_in_b - moves + counter) < moves + counter - abs(moves - counter))
		return(elem_in_b - moves + counter);
	else
		return (moves + counter - abs(moves - counter));
}

int ft_count_moves(t_stack **stack_2, t_stack **stack_1, t_stack **max, int counter, int elem_in_b)
{
	t_stack	*tmp;
	int	i;
	int value;
	int	moves;

	tmp = (*stack_1);
	i = 0;
	moves = 0;
	while (i < counter)
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
		while (value > (*stack_2)->value || value < (*stack_2)->previous->value)
		{
			(*stack_2) = (*stack_2)->next;
			moves++;
		}
	}
	(*stack_2) = tmp;
	if ((elem_in_b - moves + counter) < moves + counter - abs(moves - counter))
		return(elem_in_b - moves + counter);
	else
		return (moves + counter - abs(moves - counter));
}

int	ft_check_stack_value(t_stack **stack, int index)
{
	int	i;
	t_stack	*tmp;
	int	value;

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

int	ft_check_down(t_stack **stack, int value, int index)
{
	int	i;
	t_stack *tmp;

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

int	ft_check_up(t_stack **stack, int value, int index)
{
	int	i;
	t_stack *tmp;

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
		if ((index > 0) && (ft_check_down(stack_2, value, index) == 1))
			return (index);
		else if ((index < 0) && (ft_check_up(stack_2, value, abs(index)) == 1))
			return (abs(index));
	}
	return (0);
}

void	ft_prepare_push(t_stack **stack_1, t_stack **stack_2, int index, int min_moves)
{
	int	value;
	t_stack	*tmp;
	int	overlap;

	tmp = (*stack_2);
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
		if (overlap &&(index > 0))
		{
			ft_rrx(stack_1, stack_2, overlap);
			ft_rr(stack_1, index - overlap, 'a');
			ft_rr(stack_2, min_moves - overlap, 'b');
		}
		else if (overlap && (index < 0))
		{
			ft_rx(stack_1, stack_2, overlap);
			ft_r(stack_1, -index - overlap, 'a');
			ft_r(stack_2, min_moves - overlap, 'b');
		}
		else if ((index > 0 ) && overlap == 0)
		{
			ft_rr(stack_1, index, 'a');
			ft_r(stack_2, min_moves - index, 'b');
		}
		else if ((index < 0 ) && overlap == 0)
		{
			ft_r(stack_1, -index, 'a');
			ft_rr(stack_2, min_moves + index, 'b');
		}
	}
	ft_printf("Arrives here\n");
	ft_push(stack_1, stack_2, 'a');
}

void	ft_movenumber(t_stack **stack_1, t_stack **stack_2, t_stack **max, int elem_in_b)
{
	int	counter;
	int min_moves;
	int	index;

	counter = 0;
	min_moves = 2147483647;
	index = 0;
	//This function counts how many moves it takes to move an element and finds the cheapest option
	while (counter < elem_in_b)
	{
		if (min_moves > ft_count_moves(stack_2, stack_1, max, counter, elem_in_b))
		{
			min_moves = ft_count_moves(stack_2, stack_1, max, counter, elem_in_b);
			index = counter;
		}
		counter++;
	}
	counter = 0;
	while (counter < elem_in_b)
	{
		if (min_moves > ft_count_moves_down(stack_2, stack_1, max, counter, elem_in_b))
		{
			min_moves = ft_count_moves_down(stack_2, stack_1, max, counter, elem_in_b);
			index = counter * -1;
		}
		counter++;
	}
	ft_prepare_push(stack_1, stack_2, index, min_moves);
}

void	ft_final_sort(t_stack **stack_2)
{
	int	min;
	int	i;
	t_stack	*tmp;

	tmp = (*stack_2);
	//tbc
	while ((*stack_2)->value != (*stack_2)->next->value + 1)
	{
		
	}
}

void	ft_push_swap(t_stack **stack_1, t_stack **stack_2, int elements)
{
	int	i;
	t_stack	*max;

	i = 0;
	if (elements > 4)
	{
		if ((*stack_1)->value > (*stack_1)->next->value)
			ft_swap(stack_1, 'a');
		ft_push(stack_1, stack_2, 'a');
		max = (*stack_1);
		ft_push(stack_1, stack_2, 'a');
	}
	if (elements == 4)
		ft_swap(stack_1, 'a');
	while (i < elements - 5)
	{
		ft_printf("Moving #%d\n", i);
		ft_movenumber(stack_1, stack_2, &max, 2 + i);
		i++;
	}
	if (elements > 3)
	{
		ft_organize_3(stack_1);
		ft_printf("leaves organize 3\n");
		i = 0;
		ft_final_sort(stack_2);
		while (i < elements - 3)
		{
			if ((*stack_1)->value == (*stack_1)->previous->value + 1)
				ft_rr(stack_1, 1, 'a');
			if ((*stack_1)->value == (*stack_2)->value + 1)
			{
				ft_push(stack_2, stack_1, 'b');
				i++;
			}
		}
	}
	while ((*stack_1)->value != 0)
		ft_rr(stack_1, 1, 'a');
	(*stack_2) = NULL;
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
	// if (argc == 2)
	// 	{
	// 		//function for elements as part of a list with " "
	// 	}
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
	counter = 1;
	while (counter < argc)
	{
		ft_printf("The next value ranking %d followed by %d\n", stack_b->value, stack_b->next->value);
		stack_b = stack_b->next;
		counter++;
	}

	ft_clean(&stack_a);
	stack_a = NULL;
	// if (argc - 1 < 6)
	// {
	// 	//function for small list of elements
	// }
	ft_push_swap(&stack_b, &stack_a, argc - 1);
	counter = 1;
	while (counter < argc)
	{
		ft_printf("The next value ranking %d followed by %d\n", stack_b->value, stack_b->next->value);
		stack_b = stack_b->next;
		counter++;
	}
	ft_clean(&stack_a);
	//Check in school if there are memory leaks, as cleaning stack b gives me error, does it even exist anymore?
	ft_clean(&stack_b);
}
