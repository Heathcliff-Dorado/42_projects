#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"

typedef struct s_dict	t_dict;

typedef struct s_dict
{
	char	*varname;
	char	*value;
	t_dict	*next;
	t_dict	*previous;
}			t_dict;

typedef struct s_minishell
{
	t_dict	*dict;
	char	*pwd;
	char	*old_pwd;

}			t_minishell;

typedef struct s_prompt
{
	/* data */
}			t_prompt;

typedef struct s_cmd	t_cmd;

typedef struct s_cmd
{
	int		index;
	char	*cmd;
	char	*arg;
	char	*str;
	int		redir;
	t_cmd	*next;
	t_cmd	*previous;
}			t_cmd;

//Functions in dictionary
void	ft_clean_dict(t_minishell *mini);
int		ft_new_entry(char *varname, t_minishell *mini);
int		ft_dictionary(char **envp, t_minishell *mini);

#endif
