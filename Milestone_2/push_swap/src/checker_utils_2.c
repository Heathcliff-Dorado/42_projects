/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:03:42 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/17 13:04:49 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_last_push(t_stack **donor, t_stack **receiver)
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
	(*donor) = NULL;
}

void	ft_normal_push(t_stack **donor, t_stack **receiver)
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
