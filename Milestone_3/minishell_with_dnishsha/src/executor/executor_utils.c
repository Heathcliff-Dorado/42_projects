/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:45:19 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 13:30:02 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
Print relevant error messages and exit in case of non executable commands
*/
void	non_executable_err_handle(t_minishell *mini, t_simple_cmds *cmd)
{
	if (access(cmd->str[0], F_OK) == 0 && ft_isdir(cmd->str[0]))
	{
		if (access(cmd->str[0], X_OK))
			ft_putstr_fd(" Permission denied\n", STDERR_FILENO);
		else if (ft_isdir(cmd->str[0]))
			ft_putstr_fd(" Is a directory\n", STDERR_FILENO);
		ft_free_all(mini);
		exit (126);
	}
	ft_putstr_fd(cmd->str[0], STDERR_FILENO);
	if (access(cmd->str[0], F_OK) == 0 || !ft_isdir(cmd->str[0]))
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	else
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	ft_free_all(mini);
	exit(127);
}

void	ft_clean_env(t_minishell *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->env[i])
		i++;
	j = 0;
	while (j < i)
	{
		free(mini->env[j]);
		j++;
	}
	free(mini->env);
	mini->env = NULL;
}

int	ft_isdir(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	ft_siginterpret_end(int signal, int *signaled)
{
	if (!(*signaled))
	{
		if (signal == 3)
			ft_putstr_fd("Quit (core dumped) \n", STDERR_FILENO);
		else if (signal == 2)
			ft_putstr_fd("\n", STDERR_FILENO);
		g_exit_status = 128 + signal;
		*signaled = 1;
	}
}

void	ft_siginterpret(int signal, int *signaled)
{
	if (!(*signaled))
	{
		if (signal == 2)
			ft_putstr_fd("\n", STDERR_FILENO);
		g_exit_status = 128 + signal;
		*signaled = 1;
	}
}
