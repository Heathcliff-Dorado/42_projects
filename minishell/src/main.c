/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:13 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/23 21:00:45 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_recursive_interpret(char *prompt, t_minishell *mini);

/*int	ft_next_token(char *prompt, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (prompt[i] == "\"")
		{
			i++;
			while (prompt[i] != '\"')
				i++;
			return (i);
		}
		else if (prompt[i] == "\'")
		{
			i++;
			while (prompt[i] != '\"')
				i++;
			return (i);
		}
		else if ((prompt[i] == '|' || prompt[i] == '<' || prompt[i] == '>' || prompt[i] == ' ') && i (!= 0));
			return (i - 1);
		if ((prompt[i] == '|' || prompt[i] == '<' || prompt[i] == '>' || prompt[i] == ' ') && i (!= 0))
		{
			if ((prompt[i] == '>' && prompt[i + 1] == '>') || (prompt[i] == '<' && prompt[i + 1] == '<'))
				return (i + 1);
			else
				return (i);
		}
		i++;
	}
	return (i);
}

void	ft_parsing(char *prompt, t_minishell *mini)
{
	int	len;
	int	i;
	int	token_end;

	len = ft_strlen(prompt);
	i = 0;
	while (i < len)
	{
		while (prompt[i] == ' ')
			i++;
		token_end = ft_next_token(&prompt[i], len - i);
	}
}*/

int	ft_is_there_prompt(char *s)
{
	int	i;

	i = 0;
	while(s[i] && (s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (0);
	else
		return (1);
}

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

char	*ft_strncmp_list(char *var, int n, t_minishell *mini)
{
	char	*tmp;
	t_dict	*tmpd;

	tmp = mini->dict->varname;
	tmpd = mini->dict;
	tmpd = tmpd->next;
	while (ft_strncmp(var, tmpd->varname, n) || ft_strlen(var) != ft_strlen(tmpd->varname))
	{
		if (tmpd->varname == tmp)
			return (ft_strdup(""));
		tmpd = tmpd->next;
	}
	return (ft_strdup(tmpd->value));
}

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
void	ft_expand(char *var, char **str, t_minishell *mini)
{
	char	*tmp;
	char	*value;

	value = ft_strncmp_list(var, ft_strlen(var), mini);
	tmp = ft_strjoin(*str, ft_recursive_interpret(value, mini));
	free(value);
	value = NULL;
	free(*str);
	*str = NULL;
	*str = tmp;
	//need to create a dict with all the stored variables. Here I want to know how long the var name is, and then I will compare it to all var names in the dictionary, and store the value associated to that var name
}

char	*ft_get_varname(char *str)
{
	int	i;
	char	*dst;

	i = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\"'))
		i++;
	dst = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(dst, str, i + 1);
	return(dst);
}

char	*ft_recursive_interpret(char *prompt, t_minishell *mini)
{
	int	i;
	char	*str;
	char	*varname;

	i = 0;
	str = ft_strdup("");
	while(str && prompt[i])
	{
		if (prompt[i] == '$')
		{
			varname = ft_get_varname(&prompt[i + 1]);
			ft_expand(varname, &str, mini);
			i += ft_strlen(varname);
			free (varname);
			varname = NULL;
		}
		else
			str = ft_expand_char(str, prompt[i]);
		i++;
	}
	return (str);
}

//This function will read through the prompt and expand all variables if needed
//To expand the prompt, we need to search through any $ and substitute it for the actual variable value, unless it's single quoted.
//Then we

/*void	ft_extract_cmd(char *str, int start, int end)
{
	t_cmd	cmd;
	int	i;

	i = start;
	while (i < end)
	{
		while (str[i] == ' ')
			start++;
		i = start;
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
			cmd.str = malloc((i - start) * sizeof(char));
			ft_strlcpy(cmd.str, &str[start + 1], i - start - 1);
			i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				i++;
			cmd.str = malloc((i - start) * sizeof(char));
			ft_strlcpy(cmd.str, &str[start + 1], i - start - 1);
			i++;
		}
		else
		{

		}
	}
}

void	ft_parse(t_prompt *parsed, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '|')
		//Error
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				i++;
		}
		else if (str[i] == '|')
		{
			ft_extract_cmd(str, j, i);
			i++;
			j = i;
		}
		i++;
	}
}
*/

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

/*NEXT STEPS:
-Find how many pipes the prompt has. From index 0 until the pipe index, introduce all that information in the simple cmd struct
	Note: If the first command of each "group" starts with a | operator, it should return an error. Delete the pipe
Populate the simple cmd struct:
-First look for redirections (<< < > >>), and store that token value and the file where it should be redirected to (hd header file). Delete both. Note, if after a token there is a second token or nothing, return an error
-Count how many nodes are left, and create a string array where to store all of them
-Finally, search through the array if there is a builtin, and if so, return it*/

void	ft_rmv_lx_node(t_minishell *mini, t_lexer *node)
{
	if (node->i == mini->lex->i)
		mini->lex = mini->lex->next;
	if (!node->token)
		free (node->str);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free (node);
}

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

void	ft_create_cmd(t_minishell *mini, int index)
{
	t_simple_cmds *cmd;

	cmd = ft_calloc(1, sizeof(t_simple_cmds));
	cmd->num_redirections = 0;
	cmd->hd_file_name = NULL;
	ft_find_redir(mini, cmd, index);

}

void	ft_parse_cmd(t_minishell *mini)
{
	int	index;

	index = ft_find_pipe(mini);
	ft_create_cmd(mini, index);

}

int	ft_interpret(char *prompt, t_minishell *mini)
{
	int	status;
	int	i;
	char	*str;
	char	*varname;

	status = 0;
	i = 0;
	str = ft_strdup("");
	while(str && prompt[i])
	{
		status = ft_check_status(status, prompt[i]);
		if (status != -1 && prompt[i] == '$')
		{
			varname = ft_get_varname(&prompt[i + 1]);
			ft_expand(varname, &str, mini);
			i += ft_strlen(varname);
			free(varname);
			varname = NULL;
		}
		else
			str = ft_expand_char(str, prompt[i]);
		//printf("Works until %s, prompt char is %c\n", str, prompt[i]);
		i++;
	}
	if (status)
		return(printf("Error, no closing quotations!\n"), 0);
	ft_lexer(str, mini);
	ft_parse_cmd(mini);
	//ft_parse(parsed, str);
	free (str);
	str = NULL;
	return (1);
}


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

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	char		*prompt;

	if (argc != 1 || argv[1])
	{
		ft_printf("Error, this program does not accept arguments \n");
		return (0);
	}
	mini = ft_calloc(1, sizeof(t_minishell));
	if (!mini)
		return(printf("Memory error\n"), 0);
	mini->dict = NULL;
	mini->cmd = NULL;
	if (!ft_dictionary(envp, mini))
		return(printf("Error creating dictionary\n"), 0);
	ft_find_pwds(mini);
	prompt = readline("Minishell: ");
	while (prompt)
	{
		//Add the prompt to the history if it's not empty (i.e. only newline, what about spaces and other (\t,\r...)?)
		if (ft_is_there_prompt(prompt))
			add_history(prompt);
		if (ft_interpret(prompt, mini))
		{
			ft_test_lexer(mini);
			free(prompt);
		}
		prompt = readline("Minishell: ");
	}
	ft_clean_dict(mini);
	free(mini->dict);
	free(mini->pwd);
	free(mini->old_pwd);
	free(mini);
/*//First we asign two free fd that will act as out STDIN and STDOUT using dup()
	mini.stdin = dup(0);
	mini.stdout = dup(1);*/
}
