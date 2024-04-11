/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:17 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/05 17:18:11 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	update_n_option(t_simple_cmds *cmd, int *n_option)
{
	int	i;
	int	j;

	i = 1;
	while (cmd->str[i] && cmd->str[i][0] == '-' && cmd->str[i][1] == 'n')
	{
		j = 2;
		while (cmd->str[i][j] == 'n')
			j ++;
		if (cmd->str[i][j] == '\0')
		{
			*n_option = 1;
			i ++;
		}
		else
			break ;
	}
	return (i);
}

/*
    echo Hello       there
    Hello there

    echo -nnnnnnnnnn "asc"
    asc

    echo -nnn -nn -nnn asc
    asc

    echo -nnn -nvn -nnn asc
    -nvn -nnn asc

If -n option is given n_option is set to 1.
*/
int	echo(t_minishell *minishell, t_simple_cmds *cmd)
{
	int	i;
	int	n_option;

	i = 1;
	n_option = 0;
	(void) minishell;
	i = update_n_option(cmd, &n_option);
	while (cmd->str[i])
	{
		ft_putstr_fd(cmd->str[i++], STDOUT_FILENO);
		if (cmd->str[i])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!n_option)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
