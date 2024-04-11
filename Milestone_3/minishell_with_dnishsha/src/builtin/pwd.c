/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:28 by hdorado-          #+#    #+#             */
/*   Updated: 2024/02/26 18:49:29 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	pwd(t_minishell *minishell, t_simple_cmds *cmd)
{
	(void) cmd;
	if (!minishell || !(minishell->pwd))
		return (1);
	printf("%s\n", minishell->pwd);
	return (0);
}
