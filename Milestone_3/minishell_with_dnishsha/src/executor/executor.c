/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:47:35 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 15:01:06 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
Execute the program referred to by pathname
*/
void	execve_execute(t_minishell *minishell, t_simple_cmds *cmd)
{
	int		i;
	char	*pathname;

	i = 0;
	if (cmd->str[0])
	{
		while (minishell->path && minishell->path[i])
		{
			pathname = ft_strjoin(minishell->path[i], cmd->str[0]);
			if (access(pathname, X_OK) == 0
				&& execve(pathname, cmd->str, minishell->env) == -1)
			{
				free(pathname);
				ft_putstr_fd(" execve error\n", STDERR_FILENO);
				ft_free_all(minishell);
				exit(1);
			}
			i++;
			free(pathname);
		}
		if (execve(cmd->str[0], cmd->str, minishell->env) == -1)
			non_executable_err_handle(minishell, cmd);
	}
	exit(0);
}

/*
pid = 0 in the Child Process.

For each directory, we construct the full path of the command
and check if it's executable using the "access" function.
If the command is found and executable, we execute it using "execve".
On success, execve() does not return, on error -1 is returned.
That's why we need to call it inside the child process.

int execve(const char *pathname,
	char *const _Nullable argv[], char *const _Nullable envp[])

X_OK Flag meaning test for execute/search permission.

The input command can be in the form of 'ls' or '/bin/ls'
In the 'ls' form we search through executables by
constructing possible full paths.
*/
int	execute_executables(t_minishell *minishell, t_simple_cmds *cmd)
{
	pid_t	pid;
	int		status;
	int		dummy;

	dummy = 0;
	pid = fork();
	if (pid == -1)
		return (print_err("Error occurred in forking.", 1), 2);
	else if (pid == 0)
		execve_execute(minishell, cmd);
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			ft_siginterpret_end(WTERMSIG(status), &dummy);
	}
	return (g_exit_status);
}

/* Checks whether command is a builtin one or not*/
int	execute_commands(t_minishell *minishell, t_simple_cmds *cmd)
{
	if (cmd->builtin != NULL)
	{
		if (handle_redirections(cmd) != 0)
			return (1);
		g_exit_status = cmd->builtin(minishell, cmd);
		return (g_exit_status);
	}
	else
	{
		if (handle_redirections(cmd) != 0)
			return (1);
		return (execute_executables(minishell, cmd));
	}
}

static int	ft_dup2(int saved_stdout, int saved_stdin, int ret)
{
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		ret = print_err("Dup2", 1);
	if (dup2(saved_stdin, STDIN_FILENO) == -1)
		ret = print_err("Dup2", 1);
	return (ret);
}

/*
dup2
    int dup2(int oldfd, int newfd);
    The file descriptor newfd is adjusted so that
	it now refers to the same open file description as oldfd.

	saved_stdin and saved_stdout variables hold the initial
		values of STDIN_FILENO and STDOUT_FILENO.
	Once redirections and everything is done STDIN_FILENO,
		STDOUT_FILENO are set to its initial values.

	So reading and writing from/to the terminal can be done.
*/
int	execute(t_minishell *minishell)
{
	int				saved_stdin;
	int				saved_stdout;
	int				return_val;
	t_simple_cmds	*tmp;

	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler_notint);
	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	tmp = minishell->cmd;
	while (tmp)
	{
		if (handle_heredoc(tmp, minishell))
			return (1);
		tmp = tmp->next;
		if (tmp == minishell->cmd)
			break ;
	}
	if (minishell->pipe_count > 0)
		return_val = handle_pipes(minishell, minishell->cmd);
	else
		return_val = execute_commands(minishell, minishell->cmd);
	return_val = ft_dup2(saved_stdout, saved_stdin, return_val);
	return (return_val);
}
