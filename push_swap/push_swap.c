/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:45:55 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/11 12:51:44 by hdorado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "common_functions.h"

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

//Counts how many rotations are needed when we are moving the stack index times to the next element
int ft_count_moves_next(t_stack **stack_2, t_stack **stack_1, t_stack **max, int index, int elem_in_b)
{
	t_stack	*tmp;
	int	i;
	int value;
	int	moves;

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
	//Checks if the value is the new max or the new min. If it is, rotate the stack until the max is found
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
        //Rotate the stack until the value immediately smaller than our value is at the top
		while (value < (*stack_2)->value || value > (*stack_2)->previous->value)
		{
			(*stack_2) = (*stack_2)->next;
			moves++;
		}
	}
	(*stack_2) = tmp;
	//There are two options here: Rotating b is cheaper using next (moves) or previous (elem_in_b - moves)
    //If it uses next, both stacks can be rotated together to save a move, so it will only need to be the max between moves or index
    //If the opposite is truth, both stacks must be moved independently
    //Therefore, return the cheapest of both options
	if ((elem_in_b - moves + index) < ft_max(moves, index))
		return(elem_in_b - moves + index);
	else
		return (ft_max(moves, index));
}

//Check count_moves_next for explanation
int ft_count_moves_previous(t_stack **stack_2, t_stack **stack_1, t_stack **max, int counter, int elem_in_b)
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
		while (value < (*stack_2)->value || value > (*stack_2)->previous->value)
		{
			(*stack_2) = (*stack_2)->previous;
			moves++;
		}
	}
	(*stack_2) = tmp;
    if ((elem_in_b - moves + counter) < ft_max(moves, counter))
		return(elem_in_b - moves + counter);
	else
		return (ft_max(moves, counter));
}

//Saves the value stored index positions away
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

//Check if the correct position is achieved moving with next
int	ft_check_down(t_stack **stack, int value, int index)
{
	int	i;
	t_stack *tmp;

	i = 0;
	tmp = (*stack);
	//Moves the stack to the corresponding position
    while (i++ < index)
		(*stack) = (*stack)->next;
    //If the position is the max (i.e. both up and down are smaller numbers), check if the value is the new max or min
	if (((*stack)->value > (*stack)->next->value) && ((*stack)->value > (*stack)->previous->value))
	{
		if ((value > (*stack)->value) || (value < (*stack)->previous->value))
			{
				(*stack) = tmp;
				return (1);
			}
	}
    //If the value is bigger than the current value and smaller than the next one, it's also correct
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

//Checks how many rotations can be saved because they are in the same direction
int	ft_find_overlap(t_stack **stack_2, int value, int index, int min_moves)
{
	int	i;

	i = 0;
    //If the index and min moves is the same, it's either there is overlap or the second is not rotated
	if (abs(index) == min_moves)
	{
		if (index > 0)
		{
			while (i++ < index)
			{
                //Checks down all potential positions in 2 until it finds the correct one, that is the overlap
				if (ft_check_down(stack_2, value, i))
					return (i);
			}
		}
        //Same but in the opposite direction
		else
		{
			while (i-- > index)
			{
				if (ft_check_up(stack_2, value, abs(i)))
					return (abs(i));
			}
		}
	}
    //If min_moves is bigger than index, either they overalp index positions or none, so all moves go to rotate stack b
	else
	{
		if ((index > 0) && (ft_check_down(stack_2, value, min_moves) == 1))
			return (index);
		else if ((index < 0) && (ft_check_up(stack_2, value, abs(min_moves)) == 1))
			return (abs(index));
	}
	return (0);
}

//With the info on what is the cheapest option, rotate the stack and push the number
void	ft_prepare_push(t_stack **stack_1, t_stack **stack_2, int index, int min_moves)
{
	int	value;
	int	overlap;

    value = ft_check_stack_value(stack_1, index);
    //If index is 0, all moves are in stack b. This chunck checks in which direction
	if (index == 0)
	{
		if (ft_check_down(stack_2, value, min_moves))
			ft_r(stack_2, min_moves, 'b');
		else
			ft_rr(stack_2, min_moves, 'b');
	}
    //If not, there may be some overlap. Check the overlap, rotate both, and then the leftover is either 1 or 2 in the same direction
	else
	{
		overlap = ft_find_overlap(stack_2, value, index, min_moves);
		if (overlap &&(index > 0))
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
        //If overlap is 0, rotate stack 1 index positions and stack 2 min_moves-index in the opposite direction
		else if ((index > 0 ) && overlap == 0)
		{
			ft_r(stack_1, index, 'a');
			ft_rr(stack_2, min_moves - index, 'b');
		}
		else if ((index < 0 ) && overlap == 0)
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
	int min_moves;
	int	index;

	counter = 0;
	min_moves = 2147483647;
	index = 0;
    //Counts for as many elements as elements are in stack b, how many moves are needed (both rotating or reverse rotating)
    //If a new combination is cheaper than min_moves, save the amount of moves and the index
	while (counter < elem_in_b)
	{
		if (min_moves > ft_count_moves_next(stack_2, stack_1, max, counter, elem_in_b))
		{
			min_moves = ft_count_moves_next(stack_2, stack_1, max, counter, elem_in_b);
			index = counter;
		}
		counter++;
	}
	counter = 0;
	while (counter < elem_in_b)
	{
		if (min_moves > ft_count_moves_previous(stack_2, stack_1, max, counter, elem_in_b))
		{
			min_moves = ft_count_moves_previous(stack_2, stack_1, max, counter, elem_in_b);
			index = counter * -1;
        }
		counter++;
	}
	ft_prepare_push(stack_1, stack_2, index, min_moves);
	ft_new_max(stack_2, max, elem_in_b + 1);
}

void ft_special_condition(t_stack **stack)
{
    if ((*stack)->value > (*stack)->next->value && (*stack)->value > (*stack)->previous->value)
    {
        if ((*stack)->next->value > (*stack)->previous->value)
            {
                ft_swap(stack, 'a');
                ft_rr(stack, 1, 'a');
            }
        else
            ft_r(stack, 1, 'a');
    }
    else if ((*stack)->value < (*stack)->next->value && (*stack)->value < (*stack)->previous->value)
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
    if (elm == 3 ||
    !(((*stack)->value == elm - 1) || ((*stack)->next->value == elm - 1)|| ((*stack)->previous->value == elm - 1)))
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
	int	min;
	int	i;
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
void	ft_push_swap(t_stack **stack_1, t_stack **stack_2, int elements)
{
	int	i;
	t_stack	*max;

	i = 0;
    //If the stack has 5 or more element, push the first two, making sure that they are in descending order
	if (elements > 4)
	{
		if ((*stack_1)->value > (*stack_1)->next->value)
			ft_swap(stack_1, 'a');
		ft_push(stack_1, stack_2, 'b');
		max = (*stack_1);
		ft_push(stack_1, stack_2, 'b');
	}
    //If there are 4 elements, push just one
	if (elements == 4)
		ft_push(stack_1, stack_2, 'b');
    //Move all elements to b in the right order until there are only 3 left in a
	while (i < elements - 5)
	{
        ft_movenumber(stack_1, stack_2, &max, 2 + i);
		i++;
	}
	if (elements > 2)
	{
		ft_organize_3(stack_1, elements);
		i = 0;
        if (elements != 3)
		    ft_final_sort(stack_2, &max);
        while (i < elements - 3)
		{
			if ((*stack_1)->value == (*stack_1)->previous->value + 1)
				ft_rr(stack_1, 1, 'a');
			else if (((*stack_1)->value == (*stack_2)->value + 1) || (*stack_2)->value == elements - 1)
			{
				ft_push(stack_2, stack_1, 'a');
				i++;
			}
            else
                ft_rr(stack_1, 1, 'a');
		}
	}
    //For two elements, either it is already ok or not
	while ((*stack_1)->value != 0)
		ft_rr(stack_1, 1, 'a');
	(*stack_2) = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//int	counter;

	stack_a = NULL;
	stack_b = NULL;
	//If no args given, return prompt
    if (argc == 1)
		return (0);
	// if (argc == 2)
	// 	{
	// 		//function for elements as part of a list with " "
	// 	}
    //Function that populates stack 1 with the given arguments. If there are non-int args or larger than int, return error
	if (populate_stack(&stack_a, argc, argv) == 0)
	{
		ft_clean(&stack_a);
		ft_printf("Error\n");
		return (0);
	}
    //Generates the ranked numbers (stack b) and check for duplicates, returning error if there are duplicates
	if (modify_stack(&stack_a, &stack_b, argc) == 0)
	{
		ft_clean(&stack_a);
		ft_clean(&stack_b);
        ft_printf("Error\n");
		return (0);
	}
	//Check the initial ranked stack a
    // counter = 1;
    // while (counter < argc)
	// {
	// ft_printf("The next value ranking %d followed by %d\n", stack_b->value, stack_b->next->value);
	// stack_b = stack_b->next;
	// counter++;
	// }
    //Empties stack a
	ft_clean(&stack_a);
	stack_a = NULL;
    //Maybe unneccesary?
	// if (argc - 1 < 6)
	// {
	// 	//function for small list of elements
	// }
	ft_push_swap(&stack_b, &stack_a, argc - 1);
	//Check if sorted
    // counter = 1;
	// while (counter < argc)
	// {
	//  	ft_printf("The next value ranking %d followed by %d\n", stack_b->value, stack_b->next->value);
	//  	stack_b = stack_b->next;
	//  	counter++;
	// }
	//Cleans both stacks
    ft_clean(&stack_a);
	//Check in school if there are memory leaks, as cleaning stack b gives me error, does it even exist anymore?
	ft_clean(&stack_b);
}