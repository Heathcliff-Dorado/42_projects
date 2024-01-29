/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:06:09 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/29 16:44:29 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//NOTE: Untested, it won't run as there are missing structs, this is still work in progress

//The function will check for pipes. However, if the first element is a pipe, it means that either the prompt started with one, or there were two consecutive pipes
//Therefore it returns an error
//If not, it will keep looking until it reaches the end. It will store the index value and remove the pipe (if there was one)
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
	if (tmp->token == 3)
		ft_rmv_lx_node(mini, tmp);
	return (i);
}

//This function first confirms if after the token there is a second token, or nothing at all, in this case it fails and returns an error
//Otherwise, it creates a lexer struct that will contain the token (as before), and as a string the file where it should be stored. It will also assign an index
//corresponding to the number of redirections, and add the lexer into the circular linked list containing all redirections.
//Finally it removes the two old lexer structs and recursively looks for new redirections
//NOTE: There may be a problem if two of the same token are found, I need to check, as it would not make sense to store the data in two different files,
//but maybe bash is ok with that? Also, when is it time to check that the input file exists and works?
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

//Redirections are indicated by tokens, so this function first look for a token and sends it to the add_redirection function
void	ft_find_redir(t_minishell *mini, t_simple_cmds *cmd, int index)
{
	t_lexer	*tmp;

	tmp = mini->lex;
	while (!tmp->token && tmp->i < index)
		tmp = tmp->next;
	if (tmp->token && tmp->i < index)
		ft_add_redirection(mini, cmd, tmp, index);
}

//Iterates through the lexer elements that need to be added, counting how many there are, to allocate the correct memory
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

//Search if the string is equal to the builtin command (also in length) and return the pointer to that command (not implemented yet, therefore the errors)
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

//As before, if there is no other commands, it links the command to mini. Otherwise it appends it to the end
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

//It first initializes a cmd struct, and search for redirections (i.e. tokens that are not |), storing and deleting the elements involved.
//The rest is stored as string. There should not be any other redirections left, but just in case, I still copy only those with str into the str array
//The first element of the string array should be the command name, as redirections have been removed already. Therefore I check if the command is a built in,
//in which case I return the pointer to the builtin, or NULL if it's not the case
//FInally it adds the command to the list of commands (same as usual)
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

//The logic for this part is that the program will look for a pipe sign, and everything to the left corresponds to the first command. It will remove all the elements
//from the lexer as soon as they are added to the cmd, then look for the next pipe. If there are no pipes, it takes all the elements as one command
void	ft_parse_cmd(t_minishell *mini)
{
	int	index;

	while (mini->lex)
	{
		index = ft_find_pipe(mini);
		ft_create_cmd(mini, index);
	}
}
