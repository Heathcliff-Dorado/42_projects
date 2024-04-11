/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:30:35 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 16:46:36 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct s_dict
{
	int				array[2];
	char			*name;
	struct s_dict	*link;
}	t_dict;

char	*clean_parameter(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		open_dict(char *path, t_dict **dictionary);
int		read_file(int file, t_dict **dictionary);
int		parse_dictionary(char *str, t_dict **dictionary);
int		checklineforrules(char *str);
int		*get_value(char *str);
char	*returnliteral(char *src);
int		write_dict(t_dict **dictionary, int *array, char *nbr_letter);

int	parse_dictionary(char *str, t_dict **dictionary)
{
	int		correct_line;
	int		*array;
	char	*literal;

	correct_line = checklineforrules(str);
	if (correct_line == -1)
		return (-1);
	else
	{
		array = get_value(str);
		literal = returnliteral(str);
		write_dict(dictionary, array, literal);
	}
	return (1);
}
