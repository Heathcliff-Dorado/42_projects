#include "../inc/minishell.h"

void	ft_recursive_interpret(char *prompt, t_dict *dict);

/*int	ft_next_token(char *prompt, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (prompt[i] == "\"")
		{
			i++;
			while (prompt[i] != '\"')
				i++;
			return (i);
		}
		else if (prompt[i] == "\'")
		{
			i++;
			while (prompt[i] != '\"')
				i++;
			return (i);
		}
		else if ((prompt[i] == '|' || prompt[i] == '<' || prompt[i] == '>' || prompt[i] == ' ') && i (!= 0));
			return (i - 1);
		if ((prompt[i] == '|' || prompt[i] == '<' || prompt[i] == '>' || prompt[i] == ' ') && i (!= 0))
		{
			if ((prompt[i] == '>' && prompt[i + 1] == '>') || (prompt[i] == '<' && prompt[i + 1] == '<'))
				return (i + 1);
			else
				return (i);
		}
		i++;
	}
	return (i);
}

void	ft_parsing(char *prompt, t_minishell *mini)
{
	int	len;
	int	i;
	int	token_end;

	len = ft_strlen(prompt);
	i = 0;
	while (i < len)
	{
		while (prompt[i] == ' ')
			i++;
		token_end = ft_next_token(&prompt[i], len - i);
	}
}*/

int	ft_is_there_prompt(char *s)
{
	int	i;

	i = 0;
	while(s[i] && (s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (0);
	else
		return (1);
}

int	ft_check_status(int status, char c)
{
	if (c == '\'')
	{
		if (status == 0)
			return (-1);
		else if (status == -1)
			return (0);
	}
	if (c == '\"')
	{
		if (status == 0)
			return (-2);
		else if (status == -2)
			return (0);
	}
	return (status);
}

char	*ft_strncmp_list(char *var, int n, t_dict *dict)
{
	char	*tmp;

	tmp = dict->varname;
	dict = dict->next;
	while (ft_strncmp(var, dict->varname, n))
	{
		if (dict->varname == tmp)
			return (ft_strdup(""));
		dict = dict->next;
	}
	return (ft_strdup(dict->value));
}

char	*ft_expand_char(char *str, char c)
{
	char	*dst;

	dst = ft_calloc(ft_strlen(str) + 2, sizeof(char *));
	ft_strlcpy(dst, str, ft_strlen(str));
	dst[ft_strlen(str)] = c;
	free(str);
	return (dst);
}
void	ft_expand(char *var, char **str, t_dict *dict)
{
	char	*tmp;
	char	*value;

	value = ft_strncmp_list(var, ft_strlen(var), dict);
	ft_recursive_interpret(value, dict);
	tmp = ft_strjoin(*str, value);
	free(value);
	free(*str);
	*str = tmp;
	//need to create a dict with all the stored variables. Here I want to know how long the var name is, and then I will compare it to all var names in the dictionary, and store the value associated to that var name
}

char	*ft_get_varname(char *str)
{
	int	i;
	char	*dst;

	i = 0;
	while (str[i] && (str[i] != ' ' || str[i] != '\"'))
		i++;
	dst = ft_calloc(i, sizeof(char));
	ft_strlcpy(dst, str, i);
	return(dst);
}

void	ft_recursive_interpret(char *prompt, t_dict *dict)
{
	int	i;
	char	*str;
	char	*varname;

	i = 0;
	str = ft_strdup("");
	while(str && prompt[i])
	{
		if (prompt[i] == '$')
		{
			varname = ft_get_varname(&prompt[i + 1]);
			ft_expand(varname, &str, dict);
			i += ft_strlen(varname);
			free (varname);
		}
		else
			str = ft_expand_char(str, prompt[i]);
		i++;
	}
}

//This function will read through the prompt and expand all variables if needed
//To expand the prompt, we need to search through any $ and substitute it for the actual variable value, unless it's single quoted.
//Then we

void	ft_extract_cmd(char *str, int start, int end)
{
	t_cmd	cmd;
	int	i;

	i = start;
	while (i < end)
	{
		while (str[i] == ' ')
			start++;
		i = start;
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
			cmd.str = ft_calloc(i - start, sizeof(char));
			ft_strlcpy(cmd.str, &str[start + 1], i - start - 1);
			i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				i++;
			cmd.str = ft_calloc(i - start, sizeof(char));
			ft_strlcpy(cmd.str, &str[start + 1], i - start - 1);
			i++;
		}
		else
		{

		}
	}
}
/*
void	ft_parse(t_prompt *parsed, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '|')
		//Error
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				i++;
		}
		else if (str[i] == '|')
		{
			ft_extract_cmd(str, j, i);
			i++;
			j = i;
		}
		i++;
	}
}
*/
void	ft_interpret(char *prompt, t_dict *dict)
{
	int	status;
	int	i;
	char	*str;
	char	*varname;

	status = 0;
	i = 0;
	str = ft_strdup("");
	while(str && prompt[i])
	{
		status = ft_check_status(status, prompt[i]);
		if (status != -1 && prompt[i] == '$')
		{
			varname = ft_get_varname(&prompt[i + 1]);
			ft_expand(varname, &str, dict);
			i += ft_strlen(varname);
			free(varname);
		}
		else
			str = ft_expand_char(str, prompt[i]);
		i++;
	}
	//ft_parse(parsed, str);
	free (str);
}

void	ft_clean_dict(t_dict *dict)
{
	t_dict	*tmp;

	if (dict)
	{
		tmp = dict;
		while (tmp)
		{
			free(dict->varname);
			free(dict->value);
			dict = dict->next;
			dict->previous = tmp->previous;
			dict->previous->next = dict;
			free(tmp);
			tmp = dict;
		}
	}
}

t_dict	*ft_new_entry(char *varname, t_dict *dict)
{
	t_dict	*new_entry;

	new_entry = ft_calloc(1, sizeof(t_dict *));
	if (!new_entry)
		return (ft_clean_dict(dict), NULL);
	new_entry->varname = ft_strdup(varname);
	new_entry->value = ft_strdup(getenv(varname));
	if (!new_entry->varname || !new_entry->value)
	{
		ft_clean_dict(new_entry);
		return (ft_clean_dict(dict), NULL);
	}
	if (dict != NULL)
	{
		new_entry->next = new_entry;
		new_entry->previous = new_entry;
		return(new_entry);
	}
	new_entry->next = dict;
	new_entry->previous = dict->previous;
	dict->previous->next = new_entry;
	dict->previous = new_entry;
	return (dict);
}

//Are we allowed to use environ or envp?
t_dict	*ft_dictionary(char **envp)
{
	int	i;
	char	**arrdup;
	t_dict	*dict;

	i = 0;
	dict = NULL;
	while (envp[i] != NULL)
	{
		dict = ft_new_entry(envp[i], dict);
		if (!dict)
			return (NULL);
	}
		i++;
	arrdup = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (envp[i] != NULL)
	{
		arrdup[i] = ft_strdup(envp[i]);
		i++;
	}
	return (dict);
}

void	ft_find_pwds(t_minishell mini)
{
	t_dict	*tmp;

	tmp = mini.dict;
	if (!ft_strncmp(mini.dict->varname, "PWD=", 4))
		mini.pwd = mini.dict->value;
	if (!ft_strncmp(mini.dict->varname, "OLV_PWD=", 7))
		mini.old_pwd = mini.dict->value;
	mini.dict = mini.dict->next;
	while(mini.dict != tmp)
	{
		if (!ft_strncmp(mini.dict->varname, "PWD=", 4))
			mini.pwd = mini.dict->value;
		if (!ft_strncmp(mini.dict->varname, "OLV_PWD=", 7))
			mini.old_pwd = mini.dict->value;
		mini.dict = mini.dict->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	mini;
	int	i;

	if (argc != 1 || argv[1])
	{
		ft_printf("Error, this program does not accept arguments \n");
		return (0);
	}
	mini.dict = ft_dictionary(envp);
	ft_find_pwds(mini);
	i = 0;
	while (i < 50)
	{
		printf("Var name: %s, value: %s\n", mini.dict->varname, mini.dict->value);
		i++;
	}
	/*prompt = readline("Minishell: ");
	while (prompt)
	{
		//Add the prompt to the history if it's not empty (i.e. only newline, what about spaces and other (\t,\r...)?)
		if (ft_is_there_prompt(prompt))
			add_history(prompt);
		ft_interpret(prompt, dict, &parsed);
	}*/
/*//First we asign two free fd that will act as out STDIN and STDOUT using dup()
	mini.stdin = dup(0);
	mini.stdout = dup(1);*/
}
