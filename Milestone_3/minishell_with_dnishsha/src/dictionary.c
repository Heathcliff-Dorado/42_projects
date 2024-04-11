/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:10 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 14:46:35 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_separate_var(char *varname, t_dict *new_entry)
{
	int	i;

	i = 0;
	while (varname[i] != '=')
		i++;
	new_entry->varname = ft_substr(varname, 0, i);
	if (!new_entry->varname)
	{
		return (ft_printf("Error allocating memory to dictionary\n"), 0);
	}
	new_entry->value = ft_strdup(varname + i + 1);
	if (!new_entry->value)
	{
		free(new_entry->varname);
		return (ft_printf("Error allocating memory to dictionary\n"), 0);
	}
	return (1);
}

//First allocates the memory for a new entry. Variables are stored in envp as
//an array of strings with the structure "variable=value". Therefore, I split
//each string by the "=" character, everything to the left is the variable name,
//and to the right is the value. Finally, the new entry is linked as the last
//element of the dictionary (or if it's the first one, it creates the link)
int	ft_new_entry(char *varname, t_minishell *mini)
{
	t_dict	*new_entry;

	new_entry = (t_dict *)ft_calloc(sizeof(t_dict), 1);
	if (!new_entry)
		return (ft_printf("Memory allocation error creating dictionary\n"), 0);
	if (!ft_separate_var(varname, new_entry))
	{
		free(new_entry);
		return (0);
	}
	if (!mini->dict)
	{
		new_entry->next = new_entry;
		new_entry->previous = new_entry;
		mini->dict = new_entry;
		return (1);
	}
	new_entry->next = mini->dict;
	new_entry->previous = mini->dict->previous;
	mini->dict->previous->next = new_entry;
	mini->dict->previous = new_entry;
	return (1);
}

//This function will count how many characers until if finds a space or ", and
//then copy them into a new string. Note:I still need to figure out other cases,
//such as the varname followed by a token, single quotes or other potential
//edge cases
char	*ft_get_varname(char *str)
{
	int		i;
	char	*dst;

	if (str[0] && str[0] == '?')
	{
		dst = ft_strdup("?");
		if (!dst)
			return (ft_printf("Memory allocation error\n"), NULL);
		return (dst);
	}
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	dst = ft_calloc(i + 1, sizeof(char));
	if (!dst)
		return (ft_printf("Memory allocation error\n"), NULL);
	ft_strlcpy(dst, str, i + 1);
	return (dst);
}

int	ft_populate_env(t_minishell *mini)
{
	t_dict	*tmp;
	int		i;
	char	*tmps;

	tmp = mini->dict;
	i = 1;
	while (tmp->next != mini->dict)
	{
		i++;
		tmp = tmp->next;
	}
	mini->env = ft_calloc(i + 1, sizeof(char *));
	while (--i >= 0)
	{
		tmps = ft_strjoin(tmp->varname, "=");
		if (!tmps || !mini->env)
			return (0);
		mini->env[i] = ft_strjoin(tmps, tmp->value);
		if (!mini->env[i])
			return (free(tmps), 0);
		free(tmps);
		tmp = tmp->previous;
	}
	return (1);
}

//The dictionary function will take all the environmental variables from envp
//and store them into a (circular) double linked list of t_dict elements.
int	ft_dictionary(char **envp, t_minishell *mini)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (!ft_new_entry(envp[i], mini))
			return (0);
		i++;
	}
	ft_increase_level(mini);
	if (!ft_populate_env(mini))
		return (0);
	if (!ft_find_pwds(mini))
		return (0);
	if (!ft_find_path(mini))
		return (ft_printf("Memory error creating paths\n"), 0);
	return (1);
}
