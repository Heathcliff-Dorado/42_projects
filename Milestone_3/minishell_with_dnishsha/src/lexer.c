/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:04:43 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/07 18:22:46 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_empty(char **tmp, t_minishell *mini, int *index)
{
	int	i;

	i = 0;
	while ((*tmp)[i] == ' ' || (*tmp)[i] == '\t' || (*tmp)[i] == '\n')
		i++;
	if ((*tmp)[i])
	{
		if (!ft_addstring(tmp, mini, index))
			(*index) = -1;
	}
	free (*tmp);
	return (0);
}

//The translate function will look for different things:
//-The status of the string, as quotation marks need to be removed, and tokens
//are not considered. While inside a quote, it will add characters one by one
//until finding the matching quote.
//-If the element found is a token (<, <<, >, >>, |), and whether it was found
//alone (make new token lexer)
//-If the element found is a token preceded by a string (e.g. echo
//"test">test.txt). In that case, it will store the string into a lexer, and
//make a new lexer for the token
//-If there are only characters that are not tokens, keep appending them until
//the end of the strin/a token appears (e"ch"o is the same as echo or "echo")
//Finally, frees the tmp string and returns the current index number

int	ft_status_expand(char *str, char **tmp, int *status, int *i)
{
	while (*status)
	{
		(*tmp) = ft_expand_char((*tmp), str[*i]);
		if (!(*tmp))
			return (-1);
		(*i)++;
		*status = ft_check_status(*status, str[*i]);
	}
	(*tmp) = ft_expand_char((*tmp), str[*i]);
	if (!(*tmp))
		return (-1);
	return (0);
}

int	ft_clex(char **tmp, t_minishell *mini, int *index)
{
	if ((*tmp)[0] != '\0')
	{
		if (!ft_addstring(tmp, mini, index))
		{
			free (tmp);
			return (-1);
		}
		free((*tmp));
		(*tmp) = ft_strdup("");
		if (!(*tmp))
			return (ft_printf("Memory allocation error\n"), -1);
	}
	return (0);
}

int	ft_translate(char *str, int end, t_minishell *mini, int inx)
{
	int		status;
	int		i;
	int		ret;
	char	*tmp;

	status = 0;
	i = -1;
	tmp = ft_strdup("");
	if (!tmp)
		return (ft_printf("Memory allocation error\n"), -1);
	while (++i < end)
	{
		ret = 0;
		status = ft_check_status(status, str[i]);
		if (status)
			ret = ft_status_expand(str, &tmp, &status, &i);
		else if (ft_is_token(str[i]))
			ret = ft_clex(&tmp, mini, &inx) + ft_tknz(str + i, mini, &inx, &i);
		else
			tmp = ft_expand_char(tmp, str[i]);
		if (ret < 0 || !tmp)
			return (free(tmp), -1);
	}
	ft_is_empty(&tmp, mini, &inx);
	return (inx);
}

//This function takes the start and end position of a string. It will move the
//end until it finds a space or reaches the end of the string. If before that
//finds a quotation sign, it will ignore everything else until it finds the
//matching quotation sign. Once it reaches the delimiter, it will translate
//what it read (as it could have multiple words, such as in >test.txt (1 token,
//1 string)). Since the words are going to be indexed, the next index needs to
//be passed along and modified properly. Afterwards, start will be one character
//after end (to skip the space). At the end, if start is not the same character
//as end, it will translate the rest. NOTE: Probably I need to make sure I skip
//multiple spaces in a row

int	ft_lexer(char *prompt, t_minishell *mini)
{
	int	start;
	int	end;
	int	index;

	start = 0;
	end = 0;
	index = 0;
	while (prompt[end])
	{
		end = ft_check_quote(prompt, end);
		if (prompt[end] == ' ' || prompt[end] == '\t' || prompt[end] == '\n')
		{
			index = ft_translate(prompt + start, end - start, mini, index);
			if (index == -1)
				return (-1);
			start = end + 1;
		}
		end++;
	}
	if (start != end)
	{
		if (ft_translate(prompt + start, end - start, mini, index) == -1)
			return (-1);
	}
	return (0);
}

// Just a tester, not a real function for minishell, to make sure that all
// words are split properly and stored correctly as string or token
// void	ft_test_lexer(t_minishell *mini)
// {
// 	int	finish;
// 	t_lexer	*tmp;

// 	tmp = mini->lex;
// 	while (tmp->i)
// 		tmp = tmp->prev;
// 	finish = tmp->prev->i;
// 	while (finish >= 0)
// 	{
// 		if (tmp->token)
// 			printf("Found a token! Its value is %d\n", tmp->token);
// 		else
// 			printf("Found a sentence! It says %s\n", tmp->str);
// 		tmp = tmp->next;
// 		finish--;
// 	}
// }
