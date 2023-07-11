#include "checker.h"
#include "common_functions.h"

int ft_confirmation(t_stack **stack, int elements)
{
    int i;

    i = 0;
    while (i++ < elements)
    {
        if ((*stack)->value != i)
            return (0);
        (*stack) = (*stack)->next;
    }
    return (1);
}

void    ft_rrotate_both(t_stack **stack_a, t_stack **stack_b)
{
    (*stack_a) = (*stack_a)->previous;
	(*stack_b) = (*stack_b)->previous;
}

void    ft_rrotate(t_stack **stack)
{
    (*stack) = (*stack)->previous;
}

void    ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
    (*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
}

void    ft_rotate(t_stack **stack)
{
    (*stack) = (*stack)->next;
}

void	ft_do_swap(t_stack **stack)
{
	int tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	ft_do_push(t_stack **donor, t_stack **receiver)
{
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
	}
}

int    ft_rotate_checker(t_stack **stack_a, t_stack **stack_b, char *str)
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

int    ft_command(t_stack **stack_a, t_stack **stack_b, char *str)
{
    if (str[0] = 'r')
    {
        if (ft_rotate_checker(stack_a, stack_b, str) == 0)
            return (0);
    }
    else if (ft_strncmp(str, "sa\n", 3) == 0)
        ft_do_swap(stack_a);
    else if (ft_strncmp(str, "sb\n", 3) == 0)
        ft_do_swap(stack_b);
    else if (ft_strncmp(str, "pb\n", 3) == 0)
        ft_do_push(stack_a, stack_b);
    else if (ft_strncmp(str, "pa\n", 3) == 0)
        ft_do_push(stack_b, stack_a);
    else
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_stack	*stack_a;
	t_stack	*stack_b;
    char    *str;
	
	stack_a = NULL;
	stack_b = NULL;
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
    if (modify_stack(&stack_a, &stack_b, argc) == 0)
	{
		ft_clean(&stack_a);
		ft_clean(&stack_b);
        ft_printf("Error\n");
		return (0);
	}
    str = get_next_line(0);
    while (str)
    {
        if (ft_strlen(str) > 4 || ft_strlen(str) < 3)
        {
            ft_clean(&stack_a);
            ft_clean(&stack_b);
            ft_printf("Error\n");
            return (0);
        }
        if (ft_command(&stack_a, &stack_b, str) == 0)
        {
            ft_clean(&stack_a);
            ft_clean(&stack_b);
            ft_printf("Error\n");
            return (0);
        }
        str = get_next_line(0);
    }
    if (stack_b)
        ft_clean(&stack_b);
    if (ft_confirmation(&stack_a, argc - 1))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    return (0);
    
}