/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:04:43 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/25 22:12:08 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

int	ft_is_token(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

void	ft_add_lexer(t_lexer *new_lexer, t_minishell *mini, int index)
{
	if (index)
	{
		while (mini->lex->i != index - 1)
			mini->lex = mini->lex->prev;
		new_lexer->next = mini->lex->next;
		new_lexer->prev = mini->lex;
		mini->lex->next->prev = new_lexer;
		mini->lex->next = new_lexer;
	}
	else
	{
		new_lexer->next = new_lexer;
		new_lexer->prev = new_lexer;
	}
	new_lexer->i = index;
	mini->lex = new_lexer->next;
}

int	ft_tokenize(char *str,t_minishell *mini,int index)
{
	t_lexer	*new_lexer;
	int	ret;

	ret = 0;
	new_lexer = ft_calloc(1, sizeof(t_lexer));
	new_lexer->str = NULL;
	if (str[0] == '|')
		new_lexer->token = 3;
	else if (str[0] == '<')
	{
		if (str[1] && str[1] == '<')
		{
			new_lexer->token = -2;
			ret++;
		}
		else
			new_lexer->token = -1;
	}
	else if (str[0] == '>')
	{
		if (str[1] && str[1] == '>')
		{
			new_lexer->token = 2;
			ret++;
		}
		else
			new_lexer->token = 1;
	}
	ft_add_lexer(new_lexer, mini, index);
	return (ret);
}

void	ft_addstring(char **str, t_minishell *mini, int index)
{
	t_lexer	*new_lexer;

	new_lexer = ft_calloc(1, sizeof(t_lexer));
	new_lexer->token = 0;
	new_lexer->str = ft_strdup(*str);
	ft_add_lexer(new_lexer, mini, index);
}

int	ft_translate(char *str, int end, t_minishell *mini, int index)
{
	int	status;
	int	i;
	char	*tmp;

	status = 0;
	i = 0;
	tmp = ft_strdup("");
	while (i < end)
	{
		status = ft_check_status(status, str[i]);
		if (status)
		{
			i++;
			status = ft_check_status(status, str[i]);
			while (status)
			{
				tmp = ft_expand_char(tmp, str[i]);
				i++;
				status = ft_check_status(status, str[i]);
			}
		}
		else if (tmp[0] == '\0' && ft_is_token(str[i]))
		{
			i += ft_tokenize(str + i, mini, index);
			index++;
		}
		else if (ft_is_token(str[i]))
		{
			ft_addstring(&tmp, mini, index);
			free(tmp);
			tmp = ft_strdup("");
			index++;
			i += ft_tokenize(str + i, mini, index);
			index++;
		}
		else
			tmp = ft_expand_char(tmp, str[i]);
		i++;
	}
	if (tmp[0] != '\0')
	{
		ft_addstring(&tmp, mini, index);
		index++;
	}
	free(tmp);
	return(index);
}

void	ft_lexer(char *prompt, t_minishell *mini)
{
	int	start;
	int	end;
	int	index;

	start = 0;
	end = 0;
	index = 0;
	while (prompt[end])
	{
		if (prompt[end] == '\"')
		{
			end++;
			while (prompt[end] != '\"')
				end++;
		}
		if (prompt[end] == '\'')
		{
			end++;
			while (prompt[end] != '\'')
				end++;
		}
		if (prompt[end] == ' ')
		{
			index = ft_translate(prompt + start, end - start, mini, index);
			start = end + 1;
		}
		end++;
	}
	if (start != end)
		ft_translate(prompt + start, end - start, mini, index);
}

void	ft_test_lexer(t_minishell *mini)
{
	int	finish;
	t_lexer	*tmp;

	tmp = mini->lex;
	while (tmp->i)
		tmp = tmp->prev;
	finish = tmp->prev->i;
	while (finish >= 0)
	{
		if (tmp->token)
			printf("Found a token! Its value is %d\n", tmp->token);
		else
			printf("Found a sentence! It says %s\n", tmp->str);
		tmp = tmp->next;
		finish--;
	}
}
