/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:46:22 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 14:09:59 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*interprete_var(char *line, t_minishell *mini, char *d_ptr)
{
	int		len;
	char	*var;
	char	*value;
	char	*amended_line;

	len = 1;
	if (d_ptr && d_ptr[len] == '?')
	{
		len ++;
		value = ft_itoa(g_exit_status);
		amended_line = join_var(value, d_ptr, len, line);
		return (free(value), amended_line);
	}
	while (d_ptr && d_ptr[len] && (ft_isalnum(d_ptr[len]) || d_ptr[len] == '_'))
		len ++;
	if (len > 1)
	{
		var = ft_substr(d_ptr + 1, 0, len - 1);
		value = get_env_value(mini->dict, var);
		free(var);
		return (join_var(value, d_ptr, len, line));
	}
	return (line);
}

/* Read from shell and interprete the variables and write in herdoc file*/
static void	read_line(char *delimeter, int *fd, t_minishell *mini, int q)
{
	char	*line;
	char	*d_ptr;

	signal(SIGINT, sigint_handler_heredoc);
	line = readline(HEREDOC_MSG);
	while (line != NULL
		&& ft_strncmp(delimeter, line, ft_strlen(delimeter) + 1) != 0)
	{
		d_ptr = ft_strchr(line, '$');
		while (d_ptr && d_ptr[1] && q == 0
			&& (ft_isalnum(d_ptr[1]) || d_ptr[1] == '?' || d_ptr[1] == '_'))
		{
			line = interprete_var(line, mini, d_ptr);
			d_ptr = ft_strchr(line, '$');
		}
		write(*fd, line, ft_strlen(line));
		write(*fd, "\n", 1);
		free(line);
		line = readline(HEREDOC_MSG);
	}
	free(line);
	free(delimeter);
	ft_free_all(mini);
	exit(0);
}

/*
dvnishshanka@Vidushani:~/heath$ cat << EOF1
> This is the content of the first heredoc.
> It can span multiple lines.
> EOF1
	This is the content of the first heredoc.
	It can span multiple lines.

In the below command heredoc doesn't do anything.
dvnishshanka@Vidushani:~/heath$ ls -l << EOF2
> This is the content of the second heredoc.
> It can also span multiple lines.
> EOF2
	total 84
	-rw-r--r-- 1 dvnishshanka dvnishshanka  1311 Mar  1 11:45 Makefile
	drwxr-xr-x 2 dvnishshanka dvnishshanka  4096 Mar  1 10:51 inc
	drwxr-xr-x 3 dvnishshanka dvnishshanka  4096 Feb 20 14:19 lib
	-rwxr-xr-x 1 dvnishshanka dvnishshanka 51656 Mar  1 12:57 minishell
	drwxr-xr-x 4 dvnishshanka dvnishshanka  4096 Mar  1 12:57 src
	-rw-r--r-- 1 dvnishshanka dvnishshanka     0 Mar  1 11:49 t1
	-rw-r--r-- 1 dvnishshanka dvnishshanka     4 Mar  1 11:49 t2
	-rw-r--r-- 1 dvnishshanka dvnishshanka     8 Mar  1 11:05 test.txt
	-rw-r--r-- 1 dvnishshanka dvnishshanka     6 Mar  1 00:21 test2.txt
	-rw-r--r-- 1 dvnishshanka dvnishshanka    59 Mar  1 12:11 tk
*/

static int	ft_wait_child_hd(pid_t pid, int fd)
{
	int	status;

	waitpid(pid, &status, 0);
	close(fd);
	if (WIFEXITED(status))
	{
		g_exit_status = WEXITSTATUS(status);
		if (g_exit_status)
			return (1);
	}
	return (0);
}

static char	*execute_heredoc(char **delimeter, t_minishell *mini)
{
	int		fd;
	char	*file;
	int		quotation;
	pid_t	pid;

	file = generate_heredoc_filename();
	pid = fork();
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1 || pid == -1 || !(*delimeter) || !delimeter)
		return (print_err("Heredoc creation failed ", 1), free(file), NULL);
	quotation = ft_is_quote(delimeter);
	if (pid == 0)
	{
		free(file);
		read_line(*delimeter, &fd, mini, quotation);
	}
	else
	{
		if (ft_wait_child_hd(pid, fd))
			return (NULL);
	}
	return (file);
}

int	handle_heredoc(t_simple_cmds *cmd, t_minishell *mini)
{
	t_lexer	*temp;
	char	*delim;

	if (!cmd)
		return (1);
	temp = cmd->redirections;
	while (temp)
	{
		if (temp->token == -2)
		{
			delim = ft_strdup(temp->str);
			signal(SIGQUIT, SIG_IGN);
			signal(SIGINT, SIG_IGN);
			temp->hd_file_name = execute_heredoc(&delim, mini);
			free(delim);
			if (temp->hd_file_name == NULL)
				return (1);
		}
		temp = temp->next;
		if (temp == cmd->redirections)
			break ;
	}
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler_notint);
	return (0);
}
