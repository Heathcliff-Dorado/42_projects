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

typedef struct s_prompt
{
	/* data */
}			t_prompt;

typedef struct s_tools
{
	/* Data*/

}			t_tools;

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

typedef struct s_minishell
{
	t_dict	*dict;
	t_lexer	*lex;
	t_simple_cmds	*cmd;
	char	*pwd;
	char	*old_pwd;

}			t_minishell;

//Functions in dictionary
void	ft_clean_dict(t_minishell *mini);
int		ft_new_entry(char *varname, t_minishell *mini);
int		ft_dictionary(char **envp, t_minishell *mini);
//Functions in expander
char	*ft_strncmp_list(char *var, int n, t_minishell *mini);
char	*ft_recursive_interpret(char *prompt, t_minishell *mini);
void	ft_expand(char *var, char **str, t_minishell *mini);
char	*ft_get_varname(char *str);
int	ft_interpret(char *prompt, t_minishell *mini);
//Functions in lexer
int	ft_is_token(char c);
void	ft_add_lexer(t_lexer *new_lexer, t_minishell *mini, int index);
int	ft_tokenize(char *str,t_minishell *mini,int index);
void	ft_addstring(char **str, t_minishell *mini, int index);
int	ft_translate(char *str, int end, t_minishell *mini, int index);
void	ft_lexer(char *prompt, t_minishell *mini);
void	ft_test_lexer(t_minishell *mini);
//Function in commands
int	ft_find_pipe(t_minishell *mini);
void	ft_add_redirection(t_minishell *mini, t_simple_cmds *cmd, t_lexer *node, int index);
void	ft_find_redir(t_minishell *mini, t_simple_cmds *cmd, int index);
int	ft_count_args(t_minishell *mini, int index);
int	(*ft_find_builtin(char *str))(t_tools *, struct s_simple_cmds *);
void	ft_add_cmd(t_minishell *mini, t_simple_cmds *cmd);
void	ft_create_cmd(t_minishell *mini, int index);
void	ft_parse_cmd(t_minishell *mini);
//Functions in utils
void	ft_rmv_lx_node(t_minishell *mini, t_lexer *node);
int	ft_check_status(int status, char c);
char	*ft_expand_char(char *str, char c);
int	ft_is_there_prompt(char *s);
void	ft_find_pwds(t_minishell *mini);

#endif
