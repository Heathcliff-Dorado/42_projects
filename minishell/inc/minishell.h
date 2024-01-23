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

typedef struct s_lexer
{
	char			*str;
	int				token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_minishell
{
	t_dict	*dict;
	t_lexer	*lex;
	t_simple_cmds	*cmd;
	char	*pwd;
	char	*old_pwd;

}			t_minishell;

typedef struct s_prompt
{
	/* data */
}			t_prompt;

typedef struct s_simple_cmds
{
	char                    **str;
	int                     (*builtin)(t_tools *, struct s_simple_cmds *);
	int                     num_redirections;
	char                    *hd_file_name;
	t_lexer                 *redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

//Functions in dictionary
void	ft_clean_dict(t_minishell *mini);
int		ft_new_entry(char *varname, t_minishell *mini);
int		ft_dictionary(char **envp, t_minishell *mini);

#endif
