/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:43:01 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 22:11:39 by tmesropo         ###   ########.fr       */
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
void	ft_list_sort(t_dict **begin_list);

char	*append_char(char *str, char *buffer)
{
	int		len;
	char	*str2;
	int		i;

	len = ft_strlen(str);
	str2 = (char *)malloc(sizeof(char) * (len + 2));
	i = 0;
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = buffer[0];
	str2[i + 1] = '\0';
	free(str);
	return (str2);
}

int	read_file(int file, t_dict **dictionary)
{
	int		amount_read;
	char	buffer[1];
	char	*str;
	int		parse_correct;

	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	amount_read = read(file, buffer, 1);
	while (amount_read != 0)
	{
		if (buffer[0] != '\n')
		{
			str = append_char(str, buffer);
		}
		else
		{
			if (str[0] != '\0')
			{
				parse_correct = parse_dictionary(str, dictionary);
				if (parse_correct == -1)
				{
					ft_putstr("Dict Error\n");
					return (-1);
				}
				free(str);
				str = (char *)malloc(sizeof(char));
				str[0] = '\0';
			}
		}
		amount_read = read(file, buffer, 1);
	}
	return (0);
}

int	open_dict(char *path, t_dict **dictionary)
{
	int	file;

	file = open(path, O_RDONLY);
	if (file != -1)
	{
		if (read_file(file, dictionary) < 0)
			return (0);
	}
	else
		return (0);
	return (1);
}
