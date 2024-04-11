/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:47:20 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 13:25:16 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_fd(int	***fd, int arr_no)
{
	int	i;

	i = -1;
	while (++i < arr_no && (*fd))
	{
		free((*fd)[i]);
	}
	free(*fd);
	(*fd) = NULL;
}

// Close all file descriptors used in pipes
void	close_fds(int **fd, int pipe_count)
{
	int	i;

	i = -1;
	while (++i < pipe_count)
	{
		close(fd[i][0]);
		close(fd[i][1]);
	}
}

// Wait for all child processes
void	wait_c_processes(pid_t *pid, int pipe_count)
{
	int	i;
	int	status;
	int	signaled;

	i = -1;
	signaled = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (++i < pipe_count)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			ft_siginterpret(WTERMSIG(status), &signaled);
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		ft_siginterpret_end(WTERMSIG(status), &signaled);
}
