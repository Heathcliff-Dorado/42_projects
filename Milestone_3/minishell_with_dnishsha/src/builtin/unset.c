/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:31 by hdorado-          #+#    #+#             */
/*   Updated: 2024/02/26 18:49:32 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
Check whether the given variable is in the env list i.e dict.
In that case return a pointer to that node.
*/
t_dict	*find_env_node(t_dict **dict, char *varname)
{
	t_dict	*temp;

	temp = (*dict);
	while (temp)
	{
		if (ft_strncmp(temp->varname, varname,
				ft_strlen(temp->varname) + 1) == 0)
			return (temp);
		temp = temp->next;
		if (temp == (*dict))
			break ;
	}
	return (NULL);
}

int	mini_unset(t_minishell *minishell, t_simple_cmds *cmd)
{
	int		i;
	t_dict	*env_node;

	i = 1;
	while (cmd->str[i])
	{
		env_node = find_env_node(&(minishell->dict), cmd->str[i]);
		if (env_node)
			del_dict_node(&(minishell->dict), &env_node);
		i ++;
	}
	return (0);
}
