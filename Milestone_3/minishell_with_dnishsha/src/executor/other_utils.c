/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:48:05 by hdorado-          #+#    #+#             */
/*   Updated: 2024/02/26 18:48:06 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
void	print_cmd(t_simple_cmds *cmd)
{
	int i;

	i = 0;
	while (cmd->str[i])
	{
		printf("%d %s\n", i, cmd->str[i]);
		i ++;
	}
}
*/

static void	free_lexer(t_lexer *lexer)
{
	if (!lexer)
		return ;
	free(lexer->str);
	if (lexer->hd_file_name)
		free(lexer->hd_file_name);
	free(lexer);
}

static void	free_cmd(t_simple_cmds **cmd)
{
	t_lexer	*tmp;
	t_lexer	*tmp2;
	int		i;

	if (!cmd || !(*cmd))
		return ;
	tmp = (*cmd)->redirections;
	i = 0;
	while ((*cmd)->str[i])
	{
		free((*cmd)->str[i]);
		i ++;
	}
	free((*cmd)->str);
	while (tmp)
	{
		tmp2 = tmp->next;
		free_lexer(tmp);
		tmp = tmp2;
		if (tmp == (*cmd)->redirections)
			break ;
	}
	free(*cmd);
}

static void	free_minishell(t_minishell **shell)
{
	int	i;

	i = 0;
	if ((*shell)->path)
	{
		while ((*shell)->path[i])
		{
			free((*shell)->path[i]);
			i ++;
		}
		free((*shell)->path);
	}
	if ((*shell)->pwd)
		free((*shell)->pwd);
	if ((*shell)->old_pwd)
		free((*shell)->old_pwd);
	free(*shell);
}

void	free_cmd_mini(t_minishell **shell, t_simple_cmds **cmd)
{
	t_simple_cmds	*tmp;
	t_simple_cmds	*head;

	if (!cmd || !(*cmd))
		return ;
	tmp = (*cmd);
	head = (*cmd);
	while (*cmd)
	{
		tmp = (*cmd)->next;
		free_cmd(cmd);
		*cmd = tmp;
		if (*cmd == head)
			break ;
	}
	free_minishell(shell);
}

int	print_err(char *msg, int need_perror)
{
	if (need_perror)
		perror(msg);
	else
		ft_putstr_fd("%s\n", STDERR_FILENO);
	return (1);
}
