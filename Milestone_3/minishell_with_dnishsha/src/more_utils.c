/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:00:01 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 14:46:33 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_increase_level(t_minishell *mini)
{
	t_dict	*tmp;
	int		level;

	level = 0;
	tmp = mini->dict;
	while (ft_strncmp(tmp->varname, "SHLVL", 6) && tmp != mini->dict->previous)
		tmp = tmp->next;
	if (ft_strncmp(tmp->varname, "SHLVL", 6) == 0)
	{
		level = ft_atoi(tmp->value) + 1;
		free(tmp->value);
		tmp->value = ft_itoa(level);
	}
}

//Search if the string is equal to the builtin command (also in length) and
//return the pointer to that command
int	(*ft_find_builtin(char *str))(t_minishell *mini, t_simple_cmds *cmd)
{
	if (!ft_strncmp(str, "echo", 4) && ft_strlen(str) == 4)
		return (echo);
	if (!ft_strncmp(str, "cd", 2) && ft_strlen(str) == 2)
		return (cd);
	if (!ft_strncmp(str, "pwd", 3) && ft_strlen(str) == 3)
		return (pwd);
	if (!ft_strncmp(str, "export", 6) && ft_strlen(str) == 6)
		return (mini_export);
	if (!ft_strncmp(str, "unset", 5) && ft_strlen(str) == 5)
		return (mini_unset);
	if (!ft_strncmp(str, "env", 3) && ft_strlen(str) == 3)
		return (env);
	if (!ft_strncmp(str, "exit", 4) && ft_strlen(str) == 4)
		return (mini_exit);
	return (NULL);
}
