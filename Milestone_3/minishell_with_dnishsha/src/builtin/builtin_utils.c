/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:11 by hdorado-          #+#    #+#             */
/*   Updated: 2024/02/26 18:49:12 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
Delete node from dict.
*/
int	del_dict_node(t_dict **dict, t_dict **node)
{
	if (!(*node) || !dict || !node || !(*dict))
		return (1);
	if ((*dict) == (*node))
	{
		if ((*dict)->previous == (*node))
			(*dict) = NULL;
		else
		{
			(*dict) = (*node)->next;
			(*dict)->previous = (*node)->previous;
			(*node)->previous->next = (*dict);
		}
	}
	else
	{
		if ((*node)->next)
			(*node)->next->previous = (*node)->previous;
		if ((*node)->previous)
			(*node)->previous->next = (*node)->next;
	}
	free((*node)->varname);
	free((*node)->value);
	free(*node);
	return (0);
}

/*
Add new node to dict.
*/
int	add_new_dict_node(t_dict **dict, char *varname, char *value)
{
	t_dict	*new_node;

	if (!dict || !varname || !value)
		return (print_err("env Error", 1));
	new_node = (t_dict *)calloc(1, sizeof (t_dict));
	if (!new_node)
		return (print_err("Calloc Error", 1));
	new_node->value = ft_strdup(value);
	new_node->varname = ft_strdup(varname);
	if (!(*dict))
	{
		new_node->next = new_node;
		new_node->previous = new_node;
		*dict = new_node;
	}
	else
	{
		new_node->previous = (*dict)->previous;
		new_node->next = (*dict);
		(*dict)->previous->next = new_node;
		(*dict)->previous = new_node;
	}
	return (0);
}

/*
Update the dict values.
*/
int	update_dict(t_dict **dict, char *varname, char *value)
{
	t_dict	*tmp;

	if (!varname || !value || !dict || !(*dict))
		return (print_err("Error in updating env.", 1));
	tmp = (*dict);
	while (tmp)
	{
		if (ft_strncmp(tmp->varname, varname, ft_strlen(varname) + 1) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return (0);
		}
		tmp = tmp->next;
		if (tmp == *dict)
			return (add_new_dict_node(dict, varname, value));
	}
	return (1);
}

/* Get specific Environmental variable*/
char	*get_env_value(t_dict *dict, char *varname)
{
	t_dict	*tmp;

	if (!dict || !varname)
		return (NULL);
	tmp = dict;
	while (tmp)
	{
		if (ft_strlen(tmp->varname) == ft_strlen(varname)
			&& ft_strncmp(tmp->varname, varname, ft_strlen(tmp->varname)) == 0)
			return (tmp->value);
		tmp = tmp->next;
		if (tmp == dict)
			break ;
	}
	return (NULL);
}
