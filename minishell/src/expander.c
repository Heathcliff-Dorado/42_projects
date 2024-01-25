/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:06:34 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/25 22:12:05 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

//need to create a dict with all the stored variables. Here I want to know how long the var name is, and then I will compare it to all var names in the dictionary, and store the value associated to that var name

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
