/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:34:43 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/16 14:34:55 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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
