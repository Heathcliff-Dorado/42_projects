/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:06:09 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/25 22:12:06 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_find_pipe(t_minishell *mini)
{
	t_lexer	*tmp;
	int	i;

	tmp = mini->lex;
	if (tmp->token == 3)
		return (printf("ERROR\n"), -1);
	while (tmp->next->i > tmp->i)
	{
		if(tmp->token == 3)
			break;
		tmp = tmp->next;
	}
	i = tmp->i;
	ft_rmv_lx_node(mini, tmp);
	return (i);
}

void	ft_find_redir(t_minishell *mini, t_simple_cmds *cmd, int index)
{
	t_lexer	*tmp;

	tmp = mini->lex;
	while (!tmp->token && tmp->i < index)
		tmp = tmp->next;
	if (tmp->token && tmp->i < index)
		ft_add_redirection(mini, cmd, tmp, index);
}

void	ft_add_redirection(t_minishell *mini, t_simple_cmds *cmd, t_lexer *node, int index)
{
	t_lexer	*redir;

	if (node->next->token || (node->i == index - 1))
		exit(printf("ERROR, two tokens together\n"));
	redir = ft_calloc(1, sizeof(t_lexer));
	redir->token = node->token;
	redir->str = ft_strdup(node->next->str);
	redir->i = mini->cmd->num_redirections;
	if (!mini->cmd->num_redirections)
	{
		redir->next = redir;
		redir->prev = redir;
		mini->cmd->redirections = redir;
	}
	else
	{
		redir->next = mini->cmd->redirections;
		redir->prev = mini->cmd->redirections->prev;
		mini->cmd->redirections->prev->next = redir;
		mini->cmd->redirections->prev = redir;
	}
	mini->cmd->num_redirections++;
	ft_rmv_lx_node(mini, node->next);
	ft_rmv_lx_node(mini, node);
	ft_find_redir(mini, cmd, index);
}

int	ft_count_args(t_minishell *mini, int index)
{
	t_lexer	*tmp;
	int	i;

	tmp = mini->lex;
	i = 0;
	while (tmp->i < index)
	{
		if (tmp->str)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	(*ft_find_builtin(char *str))(t_tools *, struct s_simple_cmds *)
{
	if (ft_strncmp(str, "echo", 4) && ft_strlen(str) == 4)
		return (echo);
	if (ft_strncmp(str, "cd", 2) && ft_strlen(str) == 2)
		return (cd);
	if (ft_strncmp(str, "pwd", 3) && ft_strlen(str) == 3)
		return (pwd);
	if (ft_strncmp(str, "export", 6) && ft_strlen(str) == 6)
		return (export);
	if (ft_strncmp(str, "unset", 5) && ft_strlen(str) == 5)
		return (unset);
	if (ft_strncmp(str, "env", 3) && ft_strlen(str) == 3)
		return (env);
	if (ft_strncmp(str, "exit", 4) && ft_strlen(str) == 4)
		return (exit);
	return (NULL);
}

void	ft_add_cmd(t_minishell *mini, t_simple_cmds *cmd)
{
	if (!mini->cmd)
	{
		mini->cmd = cmd;
		cmd->next = cmd;
		cmd->prev = cmd;
	}
	else
	{
		cmd->prev = mini->cmd->prev;
		cmd->next = mini->cmd;
		mini->cmd->prev->next = cmd;
		mini->cmd->prev = cmd;
	}
}

void	ft_create_cmd(t_minishell *mini, int index)
{
	t_simple_cmds *cmd;
	int	num_args;
	int	i;

	i = 0;
	cmd = ft_calloc(1, sizeof(t_simple_cmds));
	cmd->num_redirections = 0;
	cmd->hd_file_name = NULL;
	ft_find_redir(mini, cmd, index);
	num_args = ft_count_args(mini, index);
	cmd->str = ft_calloc(num_args + 1, sizeof(char *));
	while (i < num_args)
	{
		if (mini->lex->str)
		{
			cmd->str[i] = ft_strdup(mini->lex->str);
			ft_rmv_lx_node(mini, mini->lex);
			i++;
		}
	}
	cmd->builtin = ft_find_builtin(cmd->str[0]);
	ft_add_cmd(mini, cmd);
}

void	ft_parse_cmd(t_minishell *mini)
{
	int	index;

	while (mini->lex)
	{
		index = ft_find_pipe(mini);
		ft_create_cmd(mini, index);
	}
}
