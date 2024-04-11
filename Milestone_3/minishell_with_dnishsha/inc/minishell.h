/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:01 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 14:46:40 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../lib/libft/libft.h"
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <errno.h>

# define HEREDOC_MSG "heredoc> "

typedef struct s_dict		t_dict;
typedef struct s_minishell	t_minishell;

/* This struct contains environment variable and its value*/
typedef struct s_dict
{
	char	*varname;
	char	*value;
	t_dict	*next;
	t_dict	*previous;
}	t_dict;

typedef struct s_lexer
{
	char			*str;
	int				token;
	char			*hd_file_name;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_simple_cmds
{
	char					**str;
	int						(*builtin)(t_minishell *, struct s_simple_cmds *);
	int						num_redirections;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

typedef struct s_minishell
{
	t_dict			*dict;
	t_lexer			*lex;
	t_simple_cmds	*cmd;
	char			*pwd;
	char			*old_pwd;
	char			**path;
	char			**env;
	int				pipe_count;

}	t_minishell;

extern int					g_exit_status;

//Functions in main
int		ft_find_path(t_minishell *mini);
int		process_path_variable(t_minishell *mini, const char *path_val);
void	ft_reset_mini(t_minishell *mini);
int		ft_init(int argc, char **argv, char **envp, t_minishell *mini);

//Functions in dictionary
int		ft_separate_var(char *varname, t_dict *new_entry);
int		ft_new_entry(char *varname, t_minishell *mini);
char	*ft_get_varname(char *str);
int		ft_populate_env(t_minishell *mini);
int		ft_dictionary(char **envp, t_minishell *mini);

//Functions in expander
char	*ft_strncmp_list(char *var, int n, t_minishell *mini);
char	*ft_recursive_interpret(char *prompt, t_minishell *mini);
int		ft_expand(char *var, char **str, t_minishell *mini);
int		ft_read_prompt(char *prompt, char **str, t_minishell *mini);
int		ft_interpret(char *prompt, t_minishell *mini);

//Functions in lexer_utils
int		ft_is_token(char c);
void	ft_add_lexer(t_lexer *new_lexer, t_minishell *mini, int index);
void	ft_in_redir(char *str, t_lexer *new_lexer, int *i);
int		ft_tknz(char *str, t_minishell *mini, int *index, int *i);
int		ft_addstring(char **str, t_minishell *mini, int *index);

//Functions in lexer
int		ft_is_empty(char **tmp, t_minishell *mini, int *index);
int		ft_status_expand(char *str, char **tmp, int *status, int *i);
int		ft_clex(char **tmp, t_minishell *mini, int *index);
int		ft_translate(char *str, int end, t_minishell *mini, int index);
int		ft_lexer(char *prompt, t_minishell *mini);
//void	ft_test_lexer(t_minishell *mini);

//Function in commands_utils
void	ft_clean_redir(t_minishell *mini);
int		ft_find_pipe(t_minishell *mini);
void	ft_wire_redir(t_simple_cmds *cmd, t_lexer *redir);
int		ft_add_red(t_minishell *mini, t_simple_cmds *cmd, t_lexer *node, int i);
int		ft_find_redir(t_minishell *mini, t_simple_cmds *cmd, int index);

//Function in commands
int		ft_count_args(t_minishell *mini, int index);
void	ft_add_cmd(t_minishell *mini, t_simple_cmds *cmd);
int		ft_populate_cmd(t_minishell *mini, t_simple_cmds *cmd, int num_args);
int		ft_create_cmd(t_minishell *mini, int index);
int		ft_parse_cmd(t_minishell *mini);
//void	ft_test_cmd(t_minishell *mini);

//Functions in cleaning
void	ft_free_array(char **array);
void	ft_free_all(t_minishell *mini);
void	ft_clean_dict(t_minishell *mini);
void	ft_rmv_lx_node(t_minishell *mini, t_lexer *node);
void	ft_clean_cmd(t_minishell *mini);

//Functions in utils
int		ft_check_status(int status, char c);
char	*ft_expand_char(char *str, char c);
int		ft_is_there_prompt(char *s);
int		ft_find_pwds(t_minishell *mini);
int		ft_check_quote(char *prompt, int end);

//Functions in signals
void	sigquit_handler(int signal);
void	ft_dummy(int signal);
void	sigint_handler(int signal);
void	sigint_handler_notint(int signal);
void	sigint_handler_heredoc(int signal);

//Functions in more_utils
void	ft_increase_level(t_minishell *mini);
int		(*ft_find_builtin(char *str))(t_minishell *, struct s_simple_cmds *);

// executor_utils.c
void	non_executable_err_handle(t_minishell *mini, t_simple_cmds *cmd);
void	ft_clean_env(t_minishell *mini);
int		ft_isdir(char *str);
void	ft_siginterpret_end(int signal, int *signaled);
void	ft_siginterpret(int signal, int *signaled);

// executor.c
void	execve_execute(t_minishell *minishell, t_simple_cmds *cmd);
int		execute(t_minishell *minishell);
int		execute_executables(t_minishell *minishell, t_simple_cmds *cmd);
int		execute_commands(t_minishell *minishell, t_simple_cmds *cmd);

// handle_pipes.c
int		handle_pipes(t_minishell *minishell, t_simple_cmds *cmd);

// redirections.c
int		handle_redirections(t_simple_cmds *cmd);

// heredoc_utils.c
char	*ft_clean_quote(char *str);
int		ft_is_quote(char **delimiter);
char	*join_var(char *value, char *dollar_ptr, int len, char *line);
char	*generate_heredoc_filename(void);

// heredoc.c
int		handle_heredoc(t_simple_cmds *cmd, t_minishell *minishell);

// pipe_utils.c
void	free_fd(int	***fd, int arr_no);
void	close_fds(int **fd, int pipe_count);
void	wait_c_processes(pid_t *pid, int pipe_count);

// other_utils.c
void	print_cmd(t_simple_cmds *cmd);
void	free_cmd_mini(t_minishell **shell, t_simple_cmds **cmd);
int		print_err(char *msg, int need_perror);

// echo.c
int		echo(t_minishell *minishell, t_simple_cmds *cmd);

// env.c
int		env(t_minishell *minishell, t_simple_cmds *cmd);

// pwd.c
int		pwd(t_minishell *minishell, t_simple_cmds *cmd);

// cd.c
int		cd(t_minishell *minishell, t_simple_cmds *cmd);

// builtin_utils.c
int		add_new_dict_node(t_dict **dict, char *varname, char *value);
int		update_dict(t_dict **dict, char *varname, char *value);
char	*get_env_value(t_dict *dict, char *varname);
int		del_dict_node(t_dict **dict, t_dict **node);

// export.c
int		mini_export(t_minishell *minishell, t_simple_cmds *cmd);

// unset.c
int		mini_unset(t_minishell *minishell, t_simple_cmds *cmd);

// exit.c
int		mini_exit(t_minishell *minishell, t_simple_cmds *cmd);
#endif
