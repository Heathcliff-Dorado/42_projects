/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:06:34 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/29 16:46:57 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//This function checks all varnames in the dictionary confirming if they match and have the same length
//Need to add a special case for exit status (marked as $>)
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

//Same as in ft_interpret, it looks for all $ and expands them
//This version skips the status check, since it should not have single quotes, however I still need to test if that's true, or if it's possible to store single quotes inside variables
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

//First it will look for the varname in the dictionary. If it finds it, stores the value into a new string. If not, the value will be ""
//The function will run the value through recursive interpret, which will look for moe $ signs (example: "My message is $test", where $test = "Hi, my name is $USER")
//Once all variables are expanded, it will be joined to the string using strjoin, finishing the expansion part
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
}

//This function will count how many characers until if finds a space or ", and then copy them into a new string.
//Note:I still need to figure out other cases, such as the varname followed by a token, single quotes or other potential edge cases
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

//Once we get a valid prompt, the first thing we need to do is to expand all variables if corresponding.
//Variables are char * always (at least for this project), and are preceded by a $
//If the variable is enclosed by single quotes, it should be left without expanding. In any other case, it will be exchanged by its value
//Therefore, it is important that we know if the character we are reading is in quotation or not, by using the status variable and the ft_check_status function
//If the character found is not $, or it is in single quotes, it will add a character at a time to the string str
//If the program finds a $ that has to be expanded, it will get the variable name (all characters following $ until a space, quotation sign or end of line)
//Then it will look for the corresponding value and add the value to the string (or nothing if there was no variable with that name)
//Then it will move as many positions in the string as the variable name was
//FInally, it calls the lexer (check lexer.c) and the parser (check commands.c)
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
	//ft_parse_cmd(mini);
	free (str);
	str = NULL;
	return (1);
}
