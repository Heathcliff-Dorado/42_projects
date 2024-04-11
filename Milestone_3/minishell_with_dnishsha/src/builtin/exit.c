/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:23 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/10 22:04:11 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	free_before_exit(t_minishell **mini)
{
	ft_clean_env(*mini);
	ft_clean_dict(*mini);
	free_cmd_mini(mini, &((*mini)->cmd));
}

static int	is_str_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i ++;
	}
	return (1);
}

/*
The exit command in Bash is used to terminate a script and return a value
to the parent shell. It allows you to control when your script ends and
what it returns to the system.

	exit [n]

[n] represents an exit status that the script returns
	to the shell or parent script.
This is an optional parameter. If not provided, the exit command will
	return the status of the last command executed.
*/
int	mini_exit(t_minishell *minishell, t_simple_cmds *cmd)
{
	int	exit_code;

	if ((cmd->str[1]) && is_str_num(cmd->str[1]) == 0)
	{
		ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
		exit_code = 2;
	}
	else if (cmd->str[1] && cmd->str[2])
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	else if (!(cmd->str[1]))
		exit_code = 0;
	else
		exit_code = ft_atoi(cmd->str[1]);
	free_before_exit(&minishell);
	exit(exit_code);
	return (0);
}
