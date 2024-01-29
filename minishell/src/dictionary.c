/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:10 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/29 15:11:32 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//If there is an error, or at the end of the program, ft_clean_dict will remove all elements of the dictionary and free all the memory
void	ft_clean_dict(t_minishell *mini)
{
	int	i;
	t_dict	*tmp;

	if (mini->dict)
	{
		i = 1;
		mini->dict->previous->next = NULL;
		while (mini->dict->next)
		{
			tmp = mini->dict->next;
			if (mini->dict->varname)
			{
				free(mini->dict->varname);
				mini->dict->varname = NULL;
			}
			if (mini->dict->value)
			{
				free(mini->dict->value);
				mini->dict->value = NULL;
			}
			mini->dict->next = NULL;
			mini->dict->previous = NULL;
			free(mini->dict);
			mini->dict = NULL;
			mini->dict = tmp;
			i++;
		}
		if (mini->dict->varname)
		{
			free(mini->dict->varname);
			mini->dict->varname = NULL;
		}
		if (mini->dict->value)
		{
			free(mini->dict->value);
			mini->dict->value = NULL;
		}
		mini->dict->next = NULL;
		mini->dict->previous = NULL;
		free(mini->dict);
	}
	mini->dict = NULL;
}


//First allocates the memory for a new entry. Variables are stored in envp as an array of strings with the structure "variable=value".
//Therefore, I split each string by the "=" character, everything to the left is the variable name, and to the right is the value
//Finally, the new entry is linked as the last element of the dictionary (or if it's the first one, it creates the link)
int	ft_new_entry(char *varname, t_minishell *mini)
{
	t_dict	*new_entry;
	int	i;

	i = 0;
	new_entry = malloc(sizeof(t_dict));
	if (!new_entry)
		return (ft_clean_dict(mini), 0);
	while (varname[i] != '=')
		i++;
	new_entry->varname = ft_calloc((i + 1), sizeof(char));
	new_entry->value = ft_calloc((ft_strlen(varname) - i), sizeof(char));
	if (!new_entry->varname || !new_entry->value)
	{
		ft_clean_dict(mini);
		if (new_entry->varname)
			free(new_entry->varname);
		if (new_entry->value)
			free(new_entry->value);
		new_entry->varname = NULL;
		new_entry->value = NULL;
		return (ft_clean_dict(mini), 0);
	}
	ft_strlcpy(new_entry->varname, varname, i + 1);
	ft_strlcpy(new_entry->value, &varname[i + 1], ft_strlen(varname) - i);
	//printf("Are you right?\n");
	if (!mini->dict)
	{
		free(mini->dict);
		//printf("It does enter here\n");
		new_entry->next = new_entry;
		new_entry->previous = new_entry;
		mini->dict = new_entry;
		//printf("%s\n", mini->dict->varname);
		return(1);
	}
	//printf("Turns out no\n");
	new_entry->next = mini->dict;
	new_entry->previous = mini->dict->previous;
	mini->dict->previous->next = new_entry;
	mini->dict->previous = new_entry;
	//printf("%s\n", mini->dict->previous->varname);
	return (1);
}

//The dictionary function will take all the environmental variables from envp and store them into a (circular) double linked list of t_dict elements.
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
	return (1);
}
