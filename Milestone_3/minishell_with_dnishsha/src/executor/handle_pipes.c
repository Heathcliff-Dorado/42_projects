/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:48:01 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 12:48:19 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	pipe_execute_commands(t_minishell *minishell, t_simple_cmds *cmd)
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
		execve_execute(minishell, cmd);
		return (g_exit_status);
	}
}

static int	create_pipes(t_minishell *minishell, int ***fd, pid_t **pid)
{
	int	i;

	i = -1;
	while (++i < minishell->pipe_count)
	{
		(*fd)[i] = (int *)calloc(2, sizeof(int));
		if ((*fd)[i] == NULL)
		{
			free(*pid);
			free_fd(fd, i);
			return (print_err("Error occurred in Calloc.", 1));
		}
		if (pipe((*fd)[i]) == -1)
		{
			free(*pid);
			free_fd(fd, i + 1);
			return (print_err("Error occurred in PIPES.", 1));
		}
	}
	return (0);
}

static int	execute_child_process(t_minishell *minishell,
	t_simple_cmds *cmd, int **fd, int i)
{
	int		result;

	signal(SIGINT, ft_dummy);
	signal(SIGQUIT, ft_dummy);
	if (i == 0)
		dup2(fd[i][1], STDOUT_FILENO);
	else if (i == (minishell->pipe_count))
		dup2(fd[i - 1][0], STDIN_FILENO);
	else
	{
		dup2(fd[i - 1][0], STDIN_FILENO);
		dup2(fd[i][1], STDOUT_FILENO);
	}
	close_fds(fd, minishell->pipe_count);
	free_fd(&fd, minishell->pipe_count);
	result = pipe_execute_commands(minishell, cmd);
	return (result);
}

static int	spawn_child_processes(t_minishell *minishell, t_simple_cmds *cmd,
	int **fd, pid_t *pid)
{
	int				i;
	t_simple_cmds	*head;
	int				result;

	i = -1;
	head = cmd;
	while (++i < (minishell->pipe_count + 1) && cmd)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (free_fd(&fd, minishell->pipe_count), free(pid),
				print_err("Error occurred in forking.", 1));
		else if (pid[i] == 0)
		{
			free(pid);
			result = execute_child_process(minishell, cmd, fd, i);
			ft_free_all(minishell);
			exit(result);
		}
		cmd = cmd->next;
		if (head == cmd)
			break ;
	}
	return (0);
}

/*
PIPE
    fd[0] for the read end of pipe
    fd[1] for the write end of pipe
*/
int	handle_pipes(t_minishell *minishell, t_simple_cmds *cmd)
{
	int				**fd;
	pid_t			*pid;

	fd = (int **)calloc(minishell->pipe_count, sizeof(int *));
	if (fd == NULL)
		return (print_err("Error occurred in Calloc.", 1));
	pid = (pid_t *)calloc(minishell->pipe_count + 1, sizeof(pid_t));
	if (!pid)
		return (free(fd), print_err("Error occurred in Calloc.", 1));
	if (create_pipes(minishell, &fd, &pid))
		return (1);
	if (spawn_child_processes(minishell, cmd, fd, pid))
		return (1);
	close_fds(fd, minishell->pipe_count);
	wait_c_processes(pid, minishell->pipe_count);
	free_fd(&fd, minishell->pipe_count);
	free(pid);
	return (0);
}
