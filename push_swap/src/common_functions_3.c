/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:23:23 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/18 21:07:49 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common_functions.h"

int	ft_confirmation(t_stack **stack, int elements)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack);
	while (i < elements)
	{
		if ((*stack)->value != i)
		{
			(*stack) = tmp;
			return (0);
		}
		(*stack) = (*stack)->next;
		i++;
	}
	(*stack) = tmp;
	return (1);
}

void	ft_free_array(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}
