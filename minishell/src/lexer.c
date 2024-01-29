/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:04:43 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/29 15:37:16 by hdorado-         ###   ########.fr       */
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

//This function adds the lexer to the (circular) double linked list. If there is none, is sets it as the first, else it adds it to the end
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

//Adds a token to the lexer. Sets the str to NULL, and checks if the token is |, < or >, and in the last two cases, if it's also followed by another < or > respectively
//Then appends the lexer and moves as many characters as needed
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

//Adds a new string-type lexer, simply copying the string, setting token to 0 and appending the lexer to the list
void	ft_addstring(char **str, t_minishell *mini, int index)
{
	t_lexer	*new_lexer;

	new_lexer = ft_calloc(1, sizeof(t_lexer));
	new_lexer->token = 0;
	new_lexer->str = ft_strdup(*str);
	ft_add_lexer(new_lexer, mini, index);
}

//The translate function will look for different things:
//-The status of the string, as quotation marks need to be removed, and tokens are not considered
//While inside a quote, it will add characters one by one until finding the matching quote.
//-If the element found is a token (<, <<, >, >>, |), and whether it was found alone (make new token lexer)
//-If the element found is a token preceded by a string (e.g. echo "test">test.txt). In that case, it will store the string into a lexer, and make a new lexer for the token
//-If there are only characters that are not tokens, keep appending them until the end of the strin/a token appears (e"ch"o is the same as echo or "echo")
//Finally, frees the tmp string and returns the current index number
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

//This function takes the start and end position of a string. It will move the end until it finds a space or reaches the end of the string.
//If before that finds a quotation sign, it will ignore everything else until it finds the matching quotation sign
//Once it reaches the delimiter, it will translate what it read (as it could have multiple words, such as in >test.txt (1 token, 1 string))
//Since the words are going to be indexed, the next index needs to be passed along and modified properly
//Afterwards, start will be one character after end (to skip the space)
//At the end, if start is not the same character as end, it will translate the rest
//NOTE: Probably I need to make sure I skip multiple spaces in a row
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

//Just a tester, not a real function for minishell, to make sure that all words are split properly and stored correctly as string or token
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
