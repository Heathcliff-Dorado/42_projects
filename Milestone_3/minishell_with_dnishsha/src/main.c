/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:13 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 14:45:54 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_exit_status;

//This program is essentially divided in two parts.

//For the first part, the program checks that is run properly (no args),
//initializes the structures needed, imports the list of environments from "the
//outside world" and set how to react to certain signals (still not done)
//The second part is an infinite loop (or until exit/ctrl+C is pressed), which
//will ask the user for a prompt, if it's not empty, it will store it in
//history. Then it will interpret it (expanding all variable names into their
//actual value, finding all tokens and commands), and finally act on them
//(execute the commands). Finally, it will clean the environment and set
//everything back to 0, so it can ask the user again and start everything from
//scratch. From here, you should go to dictionary.c to see how I import all
//variables into this program. Then you need to go to expander.c to see how
//the prompt is read and all the variables are changed into their value. The
//next step is the lexer.c, where the prompt is split in "words" and stored in
//a linked list. Finally, commands.c groups all the lexers that belong to the
//same command and will return you the info you need to actually execute them.
//Note that the main is still only in testing mode, i.e. it doesn't do anything
//when it stores the variables, and it doesn't return and properly free after
//errors. Not fully unerstood yet, it writes the signal into STDERROR

int	process_path_variable(t_minishell *mini, const char *path_val)
{
	char	**tmpar;
	int		i;

	tmpar = ft_split(path_val, ':');
	if (!tmpar || !tmpar[0])
		return (ft_printf("Error creating paths\n"), 0);
	i = 0;
	while (tmpar[i])
		i++;
	mini->path = ft_calloc(sizeof(char *), i + 1);
	if (!mini->path)
		return (ft_free_array(tmpar), 0);
	i = -1;
	while (tmpar[++i])
	{
		mini->path[i] = ft_strjoin(tmpar[i], "/");
		if (!mini->path[i])
			return (ft_free_array(tmpar), 0);
	}
	return (ft_free_array(tmpar), 1);
}

/* Add executable directory paths*/
int	ft_find_path(t_minishell *mini)
{
	t_dict	*tmp;

	tmp = mini->dict;
	while (ft_strncmp(tmp->varname, "PATH", 4) || ft_strlen(tmp->varname) != 4)
	{
		tmp = tmp->next;
		if (tmp == mini->dict)
			return (1);
	}
	return (process_path_variable(mini, (const char *)tmp->value));
}

void	ft_reset_mini(t_minishell *mini)
{
	int	i;

	if (mini->cmd)
		ft_clean_cmd(mini);
	i = -1;
	while (mini->path && mini->path[++i])
		free(mini->path[i]);
	if (mini->path)
		free(mini->path);
	mini->path = NULL;
	while (mini->lex)
		ft_rmv_lx_node(mini, mini->lex);
	if (mini->env)
	{
		ft_clean_env(mini);
		ft_populate_env(mini);
	}
	mini->pipe_count = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	ft_init(int argc, char **argv, char **envp, t_minishell *mini)
{
	mini->dict = NULL;
	mini->cmd = NULL;
	mini->lex = NULL;
	mini->pwd = NULL;
	mini->old_pwd = NULL;
	mini->path = NULL;
	mini->env = NULL;
	mini->pipe_count = 0;
	if (argc != 1 || argv[1])
	{
		free(mini);
		ft_printf("Error, program does not accept arguments \n");
		exit(1);
	}
	if (!ft_dictionary(envp, mini))
		return (ft_printf("Error creating dictionary\n"), 0);
	g_exit_status = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	char		*prompt;

	mini = ft_calloc(1, sizeof(t_minishell));
	if (!mini)
		return (printf("Memory error\n"), 0);
	if (!ft_init(argc, argv, envp, mini))
		return (ft_free_all(mini), 0);
	prompt = readline("Minishell: ");
	while (prompt)
	{
		if (ft_is_there_prompt(prompt))
		{
			add_history(prompt);
			if (!ft_interpret(prompt, mini))
				free(prompt);
		}
		ft_reset_mini(mini);
		ft_find_path(mini);
		prompt = readline("Minishell: ");
	}
	rl_clear_history();
	ft_free_all(mini);
	return (g_exit_status);
}
