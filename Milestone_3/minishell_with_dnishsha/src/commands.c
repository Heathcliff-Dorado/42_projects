/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:06:09 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 10:31:13 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//Iterates through the lexer elements that need to be added, counting how many
//there are, to allocate the correct memory
int	ft_count_args(t_minishell *mini, int index)
{
	t_lexer	*tmp;
	int		i;

	tmp = mini->lex;
	i = 0;
	if (tmp)
	{
		while (tmp->i <= index && tmp->i < tmp->next->i)
		{
			if (tmp->str)
				i++;
			tmp = tmp->next;
		}
		if (tmp->str && tmp->i <= index)
			i++;
	}
	return (i);
}

//As before, if there is no other commands, it links the command to mini.
//Otherwise it appends it to the end
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

//It first initializes a cmd struct, and search for redirections (i.e. tokens
//that are not |), storing and deleting the elements involved. The rest is
//stored as string. There should not be any other redirections left, but just
//in case, I still copy only those with str into the str array
//The first element of the string array should be the command name, as
//redirections have been removed already. Therefore I check if the command is
//a built in, in which case I return the pointer to the builtin, or NULL if
//it's not the case. Finally it adds the command to the list of commands
//(same as usual)
int	ft_populate_cmd(t_minishell *mini, t_simple_cmds *cmd, int num_args)
{
	int	i;

	i = -1;
	while (++i < num_args)
	{
		if (mini->lex->str)
		{
			cmd->str[i] = ft_clean_quote(ft_strdup(mini->lex->str));
			if (!cmd->str[i])
				return (ft_printf("Memory allocation error\n"), 0);
			ft_rmv_lx_node(mini, mini->lex);
		}
	}
	return (1);
}

int	ft_create_cmd(t_minishell *mini, int index)
{
	t_simple_cmds	*cmd;
	int				num_args;

	cmd = ft_calloc(1, sizeof(t_simple_cmds));
	if (!cmd)
		return (ft_printf("Memory allocation error\n"), 0);
	cmd->num_redirections = 0;
	if (!ft_find_redir(mini, cmd, index))
		return (0);
	num_args = ft_count_args(mini, index);
	cmd->str = ft_calloc(num_args + 1, sizeof(char *));
	if (!cmd->str)
		return (ft_printf("Memory allocation error\n"), 0);
	if (!ft_populate_cmd(mini, cmd, num_args))
		return (0);
	if (cmd->str[0])
		cmd->builtin = ft_find_builtin(cmd->str[0]);
	else
		cmd->builtin = NULL;
	ft_add_cmd(mini, cmd);
	return (1);
}

//The logic for this part is that the program will look for a pipe sign, and
//everything to the left corresponds to the first command. It will remove all
//the elements from the lexer as soon as they are added to the cmd, then look
//for the next pipe. If there are no pipes, it takes all the elements as one
//command
int	ft_parse_cmd(t_minishell *mini)
{
	int	index;

	while (mini->lex)
	{
		index = ft_find_pipe(mini);
		if (index < 0)
			return (0);
		if (!ft_create_cmd(mini, index))
			return (0);
	}
	return (1);
}

// void	ft_test_cmd(t_minishell *mini)
// {
// 	t_simple_cmds *tmp;
// 	int	i;

// 	tmp = mini->cmd;
// 	while (tmp->next != mini->cmd)
// 	{
// 		if (tmp->num_redirections)
// 		{
// 			i = 0;
// 			while (i < tmp->num_redirections)
// 			{
// 				tmp->redirections = tmp->redirections->next;
// 				i++;
// 			}
// 		}
// 		ft_find_builtin(tmp->str[0]);
// 		i = 1;
// 		printf("Other strings:\n");
// 		while (tmp->str[i])
// 		{
// 			printf("%s\n", tmp->str[i]);
// 			i++;
// 		}
// 		tmp = tmp->next;
// 	}
// 	printf("Found a command! It has %d redir\n", tmp->num_redirections);
// 		if (tmp->num_redirections)
// 		{
// 			i = 0;
// 			while (i < tmp->num_redirections)
// 			{
// 				tmp->redirections = tmp->redirections->next;
// 				i++;
// 			}
// 		}
// 		printf("The command is: %s\n", tmp->str[0]);
// 		ft_find_builtin(tmp->str[0]);
// 		i = 1;
// 		printf("Other strings:\n");
// 		while (tmp->str[i])
// 		{
// 			printf("%s\n", tmp->str[i]);
// 			i++;
// 		}
// }
