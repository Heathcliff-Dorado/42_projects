#include "common_functions.h"

//Creates the position in stack if it doesn't exist, and changes the corresponding links
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

int	ft_atoli(const char *nptr)
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
    if (ft_atoli(nptr) > 2147483647 || ft_atoli(nptr) < -2147483648)
        return (0);
	return (1);
}

//Function that populattes stack, checking if there are elements that are non-integers or MAXINT
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
	return(0);
}

//Creates a stack with ranked values instead of the original ones. The way it does it is by comparing a number with all the others. Every time a number is smaller, increase the value +1. If they are equal, return error
int	modify_stack(t_stack **source, t_stack **dest, int n_elements)
{
	int	new_value;
	int	counter;
	int	counter_b;
	int	tmp;
	
	counter = 1;
	tmp = (*source)->value;
	(*source) = (*source)->next;
	while (counter++ < n_elements)
	{
		new_value = 0;
		counter_b = 2;
		while (counter_b++ < n_elements)
		{
			if (tmp == (*source)->value)
				return (0);
			else if (tmp > (*source)->value)
				new_value++;
			(*source) = (*source)->next;
		}
		if (add_position(dest, new_value) == 0)
			return (0);
		(*source) = (*source)->next;
		tmp = (*source)->value;
		(*source) = (*source)->next;
	}
	(*source) = (*source)->previous;
	return (1);
}