/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:26 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 14:17:53 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	print_env(t_minishell *minishell)
{
	t_dict	*head;
	t_dict	*tmp;

	if (!minishell || !(minishell->dict))
		return (1);
	head = minishell->dict;
	tmp = head;
	while (tmp)
	{
		printf("declare -x %s=%s\n", tmp->varname, tmp->value);
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	return (0);
}

/*
Update PWD and OLD_PWD in minishell if required.
*/
void	update_minishell_wds(t_minishell **minishell,
	char *varname, char *value)
{
	if (!minishell || !(*minishell))
		return ;
	if (ft_strncmp(varname, "OLDPWD", 7) == 0)
	{
		free((*minishell)->old_pwd);
		(*minishell)->old_pwd = ft_strdup(value);
	}
	else if (ft_strncmp(varname, "PWD", 4) == 0)
	{
		free((*minishell)->pwd);
		(*minishell)->pwd = ft_strdup(value);
	}
}

/*
env variable names must:
	Start with a letter (a-z or A-Z) or an underscore.
	Subsequent characters can be letters, digits (0-9), or underscores.
*/
static int	is_valid_variable(char *s)
{
	int	i;

	if (ft_isalpha(s[0]) == 0 && s[0] != '_')
		return (0);
	i = 1;
	while (s[i])
	{
		if (ft_isalpha(s[i]) == 0 && s[i] != '_' && ft_isdigit(s[i]) == 0)
			return (0);
		i ++;
	}
	return (1);
}

static int	interprete_var(int i, t_minishell *minishell, t_simple_cmds *cmd)
{
	char	*equal_sign;
	char	*varname;
	char	*value;

	equal_sign = ft_strchr(cmd->str[i], '=');
	varname = ft_substr(cmd->str[i], 0, equal_sign - cmd->str[i]);
	value = ft_strdup(equal_sign + 1);
	if (is_valid_variable(varname) == 0)
	{
		ft_putstr_fd("export: `", STDERR_FILENO);
		ft_putstr_fd(cmd->str[i], STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		return (free(varname), free(value), 1);
	}
	else
		update_dict(&(minishell->dict), varname, value);
	free(varname);
	free(value);
	return (0);
}

/*
In this case 'dog' is ignored.
export myname=cat dog
$ echo $myname
	cat

export 9Path
-bash: export: `9Path': not a valid identifier

export 9Path=cat Cat=67
-bash: export: `9Path=cat': not a valid identifier

Even through export replaces PWD env variable.
	Bash will keep track of the correct pwd.
dvnishshanka@Vidushani:~$ export PWD=/home/dvnishshanka/heath/src/
dvnishshanka@Vidushani:~/heath/src/$ pwd
/home/dvnishshanka
*/
int	mini_export(t_minishell *minishell, t_simple_cmds *cmd)
{
	int		i;

	(void) minishell;
	if (!(cmd->str[1]) && print_env(minishell) == 1)
		return (1);
	i = 1;
	while (cmd->str[i])
	{
		if (!ft_strchr(cmd->str[i], '=') && is_valid_variable(cmd->str[i]) == 0)
			return (ft_putstr_fd(" not a valid identifier\n",
					STDERR_FILENO), 1);
		else if (ft_strchr(cmd->str[i], '='))
		{
			if (interprete_var(i, minishell, cmd))
				return (1);
		}
		i ++;
	}
	return (0);
}
