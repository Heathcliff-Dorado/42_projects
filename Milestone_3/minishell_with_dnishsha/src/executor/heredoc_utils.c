/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:45:34 by hdorado-          #+#    #+#             */
/*   Updated: 2024/03/12 13:56:02 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_clean_quote(char *str)
{
	int		i;
	char	*new_str;
	int		status;

	i = 0;
	status = 0;
	new_str = ft_strdup("");
	while (str[i])
	{
		status = ft_check_status(status, str[i]);
		if (status)
		{
			status = ft_check_status(status, str[++i]);
			while (status)
			{
				new_str = ft_expand_char(new_str, str[i]);
				if (str[++i])
					status = ft_check_status(status, str[i]);
			}
			i++;
		}
		else
			new_str = ft_expand_char(new_str, str[i++]);
	}
	return (free(str), new_str);
}

int	ft_is_quote(char **delimiter)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while ((*delimiter)[i])
	{
		if ((*delimiter)[i] == '\'' || (*delimiter)[i] == '\"')
			ret = 1;
		i++;
	}
	(*delimiter) = ft_clean_quote(*delimiter);
	return (ret);
}

/* Substitute the env variable value and return the line */
char	*join_var(char *value, char *dollar_ptr, int len, char *line)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*final_str;

	str1 = ft_substr(line, 0, dollar_ptr - line);
	str2 = ft_substr(dollar_ptr + len, 0, ft_strlen(dollar_ptr + len));
	if (!value)
		final_str = ft_strjoin(str1, str2);
	else
	{
		str3 = ft_strjoin(str1, value);
		final_str = ft_strjoin(str3, str2);
		free(str3);
	}
	free(str1);
	free(str2);
	free(line);
	return (final_str);
}

/* Generate filename of the heredoc file.*/
char	*generate_heredoc_filename(void)
{
	static int	i = 0;
	char		*num;
	char		*filename;

	num = ft_itoa(i);
	i ++;
	filename = ft_strjoin("/tmp/tmp_heredoc_", num);
	free(num);
	return (filename);
}
