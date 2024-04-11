/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:25:32 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/11 12:04:15 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_clean_redir(t_minishell *mini)
{
	if (mini->cmd->redirections)
	{
		mini->cmd->redirections->prev->next = NULL;
		while (mini->cmd->redirections->next)
		{
			if (mini->cmd->redirections->str)
				free(mini->cmd->redirections->str);
			if (mini->cmd->redirections->hd_file_name)
				free(mini->cmd->redirections->hd_file_name);
			mini->cmd->redirections = mini->cmd->redirections->next;
			free(mini->cmd->redirections->prev);
		}
		if (mini->cmd->redirections->str)
			free(mini->cmd->redirections->str);
		if (mini->cmd->redirections->hd_file_name)
		{
			free(mini->cmd->redirections->hd_file_name);
			mini->cmd->redirections->hd_file_name = NULL;
		}
		free(mini->cmd->redirections);
	}
	mini->cmd->redirections = NULL;
}

//The function will check for pipes. However, if the first element is a pipe, it
//means that either the prompt started with one, or there were two consecutive
//pipes. Therefore it returns an error
//If not, it will keep looking until it reaches the end. It will store the index
//value and remove the pipe (if there was one)
int	ft_find_pipe(t_minishell *mini)
{
	t_lexer	*tmp;
	int		i;

	i = mini->lex->prev->i + 1;
	tmp = mini->lex;
	if (tmp->token == 3)
		return (ft_putstr_fd(" syntax error near unexpected token `|'", 2), -1);
	while (tmp->next->i > tmp->i)
	{
		if (tmp->token == 3)
		{
			i = tmp->i;
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp->token == 3)
	{
		mini->pipe_count++;
		ft_rmv_lx_node(mini, tmp);
	}
	return (i);
}

//This function first confirms if after the token there is a second token, or
//nothing at all, in this case it fails and returns an error. Otherwise, it
//creates a lexer struct that will contain the token (as before), and as a
//string the file where it should be stored. It will also assign an index
//corresponding to the number of redirections, and add the lexer into the
//circular linked list containing all redirections. Finally it removes the
//two old lexer structs and recursively looks for new redirections
//NOTE: There may be a problem if two of the same token are found, I need to
//check, as it would not make sense to store the data in two different files,
//but maybe bash is ok with that? Also, when is it time to check that the
//input file exists and works?
void	ft_wire_redir(t_simple_cmds *cmd, t_lexer *redir)
{
	if (!cmd->num_redirections)
	{
		redir->next = redir;
		redir->prev = redir;
		cmd->redirections = redir;
	}
	else
	{
		redir->next = cmd->redirections;
		redir->prev = cmd->redirections->prev;
		cmd->redirections->prev->next = redir;
		cmd->redirections->prev = redir;
	}
}

int	ft_add_red(t_minishell *mini, t_simple_cmds *cmd, t_lexer *node, int i)
{
	t_lexer	*redir;

	if (node->next->token || (node->i == i - 1))
		return (ft_putstr_fd(" syntax error near unexpected token\n", 2), 0);
	redir = ft_calloc(1, sizeof(t_lexer));
	if (!redir)
		return (ft_printf("Memory allocation error\n"), 0);
	redir->token = node->token;
	if (redir->token == -2)
		redir->str = ft_strdup(node->next->str);
	else
		redir->str = ft_clean_quote(ft_strdup(node->next->str));
	if (!redir->str)
		return (ft_printf("Memory allocation error\n"), 0);
	redir->i = cmd->num_redirections;
	ft_wire_redir(cmd, redir);
	cmd->num_redirections++;
	ft_rmv_lx_node(mini, node->next);
	ft_rmv_lx_node(mini, node);
	if (!ft_find_redir(mini, cmd, i))
		return (0);
	return (1);
}

//Redirections are indicated by tokens, so this function first look for a
//token and sends it to the add_red function
int	ft_find_redir(t_minishell *mini, t_simple_cmds *cmd, int index)
{
	t_lexer	*tmp;

	tmp = mini->lex;
	if (tmp)
	{
		while (!tmp->token && tmp->i < index && tmp->i < tmp->next->i)
			tmp = tmp->next;
		if (tmp->token && tmp->i < index)
		{
			if (!ft_add_red(mini, cmd, tmp, index))
				return (0);
		}
	}
	return (1);
}
