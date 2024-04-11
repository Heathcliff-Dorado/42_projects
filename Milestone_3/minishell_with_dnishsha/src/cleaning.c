/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:03:20 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 10:42:20 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (--i >= 0)
		free(array[i]);
	free(array);
}

void	ft_free_all(t_minishell *mini)
{
	int	i;

	ft_clean_cmd(mini);
	ft_clean_dict(mini);
	if (mini->pwd)
		free(mini->pwd);
	if (mini->old_pwd)
		free(mini->old_pwd);
	while (mini->lex)
		ft_rmv_lx_node(mini, mini->lex);
	i = -1;
	while (mini->path && mini->path[++i])
		free(mini->path[i]);
	if (mini->path)
		free(mini->path);
	if (mini->env)
		ft_clean_env(mini);
	clear_history();
	free(mini);
}

//If there is an error, or at the end of the program, ft_clean_dict will
//remove all elements of the dictionary and free all the memory
void	ft_clean_dict(t_minishell *mini)
{
	t_dict	*tmp;
	t_dict	*tmp2;

	if (!mini->dict)
		return ;
	tmp = mini->dict;
	while (tmp)
	{
		free(tmp->varname);
		free(tmp->value);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
		if (tmp == mini->dict)
			break ;
	}
	mini->dict = NULL;
}

//This is the cleaning function used for errors or when creating the simple cmds
void	ft_rmv_lx_node(t_minishell *mini, t_lexer *node)
{
	if (node->i == mini->lex->i)
		mini->lex = mini->lex->next;
	if (node->str)
		free (node->str);
	if (node->hd_file_name)
		free (node->hd_file_name);
	if (node == node->next)
		mini->lex = NULL;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free (node);
}

void	ft_clean_cmd(t_minishell *mini)
{
	int				i;
	t_simple_cmds	*tmp;

	while (mini->cmd)
	{
		i = -1;
		ft_clean_redir(mini);
		if (mini->cmd->str)
		{
			while (mini->cmd->str[++i])
				free(mini->cmd->str[i]);
			free(mini->cmd->str);
		}
		tmp = mini->cmd;
		if (mini->cmd == mini->cmd->next)
			mini->cmd = NULL;
		else
		{
			mini->cmd->prev->next = mini->cmd->next;
			mini->cmd->next->prev = mini->cmd->prev;
			mini->cmd = mini->cmd->next;
		}
		free(tmp);
	}
}
