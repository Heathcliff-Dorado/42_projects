/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:57:00 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/05 18:09:04 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//Check if the character is a token
int	ft_is_token(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

//This function adds the lexer to the (circular) double linked list. If there is
//none, is sets it as the first, else it adds it to the end
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

void	ft_in_redir(char *str, t_lexer *new_lexer, int *i)
{
	if (str[0] == '|')
		new_lexer->token = 3;
	else if (str[0] == '<')
	{
		if (str[1] && str[1] == '<')
		{
			new_lexer->token = -2;
			(*i)++;
		}
		else
			new_lexer->token = -1;
	}
	else if (str[0] == '>')
	{
		if (str[1] && str[1] == '>')
		{
			new_lexer->token = 2;
			(*i)++;
		}
		else
			new_lexer->token = 1;
	}
}

//Adds a token to the lexer. Sets the str to NULL, and checks if the token is |,
//< or >, and in the last two cases, if it's also followed by another < or >
//respectively. Then appends the lexer and moves as many characters as needed
int	ft_tknz(char *str, t_minishell *mini, int *index, int *i)
{
	t_lexer	*new_lexer;

	new_lexer = ft_calloc(1, sizeof(t_lexer));
	if (!new_lexer)
		return (ft_printf("Memory allocation error\n"), -1);
	new_lexer->str = NULL;
	ft_in_redir(str, new_lexer, i);
	ft_add_lexer(new_lexer, mini, *index);
	(*index)++;
	return (0);
}

//Adds a new string-type lexer, simply copying the string, setting token to 0
//and appending the lexer to the list
int	ft_addstring(char **str, t_minishell *mini, int *index)
{
	t_lexer	*new_lexer;

	new_lexer = ft_calloc(1, sizeof(t_lexer));
	if (!new_lexer)
		return (ft_printf("Memory allocation error\n"), 0);
	new_lexer->token = 0;
	new_lexer->str = ft_strdup(*str);
	if (!new_lexer->str)
	{
		free(new_lexer);
		return (ft_printf("Memory allocation error\n"), 0);
	}
	ft_add_lexer(new_lexer, mini, *index);
	(*index)++;
	return (1);
}
