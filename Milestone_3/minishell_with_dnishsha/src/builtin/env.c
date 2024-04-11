/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:20 by hdorado-          #+#    #+#             */
/*   Updated: 2024/02/26 18:49:20 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	env(t_minishell *minishell, t_simple_cmds *cmd)
{
	t_dict	*head;
	t_dict	*tmp;

	(void) cmd;
	if (!minishell || !(minishell->dict))
		return (1);
	head = minishell->dict;
	tmp = head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->varname, tmp->value);
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	return (0);
}
