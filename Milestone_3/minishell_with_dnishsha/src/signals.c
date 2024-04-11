/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:11:50 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 13:16:50 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sigquit_handler(int signal)
{
	ft_putstr_fd("Quit (core dumped) ", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	(void) signal;
	exit(131);
}

void	ft_dummy(int signal)
{
	(void) signal;
}

void	sigint_handler(int signal)
{
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 130;
	(void) signal;
}

void	sigint_handler_notint(int signal)
{
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 130;
	(void) signal;
}

void	sigint_handler_heredoc(int signal)
{
	ft_putstr_fd("\n", STDERR_FILENO);
	(void) signal;
	exit(1);
}
