/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:13 by hdorado-          #+#    #+#             */
/*   Updated: 2024/01/29 15:11:47 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_recursive_interpret(char *prompt, t_minishell *mini);

/*NEXT STEPS:
-Find how many pipes the prompt has. From index 0 until the pipe index, introduce all that information in the simple cmd struct
	Note: If the first command of each "group" starts with a | operator, it should return an error. Delete the pipe
Populate the simple cmd struct:
-First look for redirections (<< < > >>), and store that token value and the file where it should be redirected to (inside the t_lexer struct). Delete both. Note, if after a token there is a second token or nothing, return an error
-Count how many nodes are left, and create a string array where to store all of them
-Finally, search through the array if there is a builtin, and if so, return it*/



// This program is essentially divided in two parts.

// For the first part, the program checks that is run properly (no args),
// initializes the structures needed, imports the list of environments from "the outside world" and set how to react to certain signals (still not done)

// The second part is an infinite loop (or until exit/ctrl+C is pressed), which will ask the user for a prompt, if it's not empty, it will store it in history.
// Then it will interpret it (expanding all variable names into their actual value, finding all tokens and commands), and finally act on them (execute the commands).
// Finally, it will clean the environment and set everything back to 0, so it can ask the user again and start everything from scratch

//From here, you should go to dictionary.c to see how I import all variables into this program.
//Then you need to go to expander.c to see how the prompt is read and all the variables are changed into their value
//The next step is the lexer.c, where the prompt is split in "words" and stored in a linked list
//Finally, commands.c groups all the lexers that belong to the same command and will return you the info you need to actually execute them
//Note that the main is still only in testing mode, i.e. it doesn't do anything when it stores the variables, and it doesn't return and properly free after errors
int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	char		*prompt;

	if (argc != 1 || argv[1])
	{
		ft_printf("Error, this program does not accept arguments \n");
		return (0);
	}
	mini = ft_calloc(1, sizeof(t_minishell));
	if (!mini)
		return(printf("Memory error\n"), 0);
	mini->dict = NULL;
	mini->cmd = NULL;
	if (!ft_dictionary(envp, mini))
		return(printf("Error creating dictionary\n"), 0);
	ft_find_pwds(mini);
	prompt = readline("Minishell: ");
	while (prompt)
	{
		//Add the prompt to the history if it's not empty (i.e. only newline, what about spaces and other (\t,\r...)?)
		if (ft_is_there_prompt(prompt))
		{
			add_history(prompt);
			if (ft_interpret(prompt, mini))
			{
				ft_test_lexer(mini);
				free(prompt);
			}
		}
		prompt = readline("Minishell: ");
	}
	ft_clean_dict(mini);
	free(mini->dict);
	free(mini->pwd);
	free(mini->old_pwd);
	free(mini);
/*//First we asign two free fd that will act as out STDIN and STDOUT using dup()
	mini.stdin = dup(0);
	mini.stdout = dup(1);*/
}
