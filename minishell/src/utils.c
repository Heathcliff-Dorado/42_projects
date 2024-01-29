/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:42:50 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/29 15:52:50 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//This is the cleaning function used for errors or when creating the simple cmds
void	ft_rmv_lx_node(t_minishell *mini, t_lexer *node)
{
	if (node->i == mini->lex->i)
		mini->lex = mini->lex->next;
	if (!node->token)
		free (node->str);
	if (node == node->next)
		mini->lex = NULL;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free (node);
}

//This function takes the current status (0 for unquoted) and checks if it finds a quotation sign.
//If there is a single quote, the status is changed to -1 (or reverted to 0)
//If there is a double quote, the status is changed to -2 (or reverted to 0)
//In any other cases, the status remains unchanged
int	ft_check_status(int status, char c)
{
	if (c == '\'')
	{
		if (status == 0)
			return (-1);
		else if (status == -1)
			return (0);
	}
	if (c == '\"')
	{
		if (status == 0)
			return (-2);
		else if (status == -2)
			return (0);
	}
	return (status);
}

//Similar as gnl, it will create a new string 1 character longer, copy the string, add the new char, \0 terminate and free the old string
char	*ft_expand_char(char *str, char c)
{
	char	*dst;

	dst = ft_calloc((ft_strlen(str) + 2), sizeof(char *));
	ft_strlcpy(dst, str, ft_strlen(str) + 1);
	dst[ft_strlen(str)] = c;
	free(str);
	str = NULL;
	return (dst);
}

//When using bash (and therefore minishell), only if the prompt has something (i.e. not just spaces or new line), it should not be stored in the history
int	ft_is_there_prompt(char *s)
{
	int	i;

	i = 0;
	while(s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	if (!s[i])
		return (0);
	else
		return (1);
}

//This function finds the working directories (old and current) and stores them in the corresponding variables of t_mini
void	ft_find_pwds(t_minishell *mini)
{
	t_dict	*tmp;

	tmp = mini->dict;
	if (!ft_strncmp(mini->dict->varname, "PWD", 3))
		mini->pwd = ft_strdup(mini->dict->value);
	if (!ft_strncmp(mini->dict->varname, "OLDPWD", 6))
		mini->old_pwd = ft_strdup(mini->dict->value);
	mini->dict = mini->dict->next;
	while(mini->dict != tmp)
	{
		if (!ft_strncmp(mini->dict->varname, "PWD", 3))
			mini->pwd = ft_strdup(mini->dict->value);
		if (!ft_strncmp(mini->dict->varname, "OLDPWD", 6))
			mini->old_pwd = ft_strdup(mini->dict->value);
		mini->dict = mini->dict->next;
	}
}

