/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:14 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/05 16:57:52 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
Get the parent directory from the PWD
If pwd=/ but still the "cd .." is called. It will not change anything.
*/
static int	change_to_parent_dir(char *pwd)
{
	int		i;
	char	*parent_dir;

	if (!pwd)
		return (ft_putstr_fd("No PWD ", STDERR_FILENO), 1);
	if (ft_strncmp(pwd, "/", 2) == 0)
		return (0);
	i = ft_strlen(pwd) - 1;
	while (i >= 0)
	{
		if (pwd[i] == '/')
		{
			if (i == 0)
				i ++;
			break ;
		}
		i --;
	}
	parent_dir = ft_substr(pwd, 0, (size_t) i);
	if (chdir(parent_dir) == -1)
	{
		free(parent_dir);
		return (ft_putstr_fd("chdir Error ", STDERR_FILENO), 1);
	}
	return (free(parent_dir), 0);
}

/*
Update PWD and OLD_PWD in minishell
*/
static void	update_wds(t_minishell **minishell, char *work_dir)
{
	if (!minishell || !(*minishell))
		return ;
	free((*minishell)->old_pwd);
	(*minishell)->old_pwd = ft_strdup((*minishell)->pwd);
	free((*minishell)->pwd);
	(*minishell)->pwd = ft_strdup(work_dir);
}

/*

*/
int	change_to_home_based_path(t_simple_cmds *cmd, char **home)
{
	char	*tmp;

	if (*home)
	{
		tmp = ft_strjoin((*home), cmd->str[1] + 1);
		free((*home));
		(*home) = tmp;
		return (chdir((*home)));
	}
	return (ft_putstr_fd(" HOME not set\n", STDERR_FILENO), 1);
}

/*
Change directory

chdir() changes the current working directory of the calling
	process to the directory specified in path.
	Command returns zero (0) on success. -1 is returned on an error.
	int chdir(const char *path);
*/
static int	change_directory(t_minishell *minishell,
	t_simple_cmds *cmd, char **home)
{
	if (!(cmd->str[1]))
	{
		if ((*home))
			return (chdir((*home)));
		return (ft_putstr_fd(" HOME not set\n", STDERR_FILENO), 1);
	}
	else if (cmd->str[2])
		return (ft_putstr_fd(" too many arguments\n", STDERR_FILENO), 1);
	else if ((cmd->str[1]) && ft_strncmp(cmd->str[1], "-", 2) == 0)
	{
		if (!(minishell->old_pwd))
			return (ft_putstr_fd(" OLDPWD not set", STDERR_FILENO), 1);
		return (chdir(minishell->old_pwd));
	}
	else if (ft_strncmp(cmd->str[1], "~", 1) == 0)
		return (change_to_home_based_path(cmd, home));
	else if (cmd->str[1] && ft_strncmp(cmd->str[1], "..", 3) == 0)
		return (change_to_parent_dir(minishell->pwd));
	return (chdir(cmd->str[1]));
}

/*
getcwd	Determines the path name of the
		working directory and stores it in buffer.
	size	The number of characters in the buffer area.
	buffer	The name of the buffer that will be used to hold the
			pathname of the working directory.
			Buffer must be big enough to hold the working directory name,
			plus a terminating NULL to mark the end of the name.
	char *getcwd(char *buffer, size_t size);
For the buffer I have used 1024 size.

The command "cd -" is typically used to change the current directory to the
	previous working directory, which is stored
	in the OLDPWD environment variable.
*/
int	cd(t_minishell *minishell, t_simple_cmds *cmd)
{
	int		return_val;
	char	work_dir[1024];
	char	*home;

	home = ft_strdup(get_env_value(minishell->dict, "HOME"));
	return_val = change_directory(minishell, cmd, &home);
	if (return_val == -1)
	{
		ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
		free(home);
		return (1);
	}
	else if (return_val == 1)
		return (1);
	if (!getcwd(work_dir, sizeof (work_dir)))
		return (ft_putstr_fd("getcwd ", STDERR_FILENO), 1);
	if (update_dict(&(minishell->dict), "OLDPWD", minishell->pwd)
		|| update_dict(&(minishell->dict), "PWD", work_dir))
		return (1);
	free(home);
	return (update_wds(&minishell, work_dir), 0);
}
