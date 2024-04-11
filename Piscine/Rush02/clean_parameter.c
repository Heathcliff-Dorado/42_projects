/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:35:09 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 22:10:07 by tmesropo         ###   ########.fr       */
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

char	*clean_parameter(char *str)
{
	char	*nb;
	int		length;
	int		i;
	int		start;

	i = 0;
	length = ft_strlen(str);
	nb = (char *)malloc(sizeof(char) * (length + 1));
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r') || str[i] == '+')
		i++;
	if (str[i] == '-')
		return (0);
	nb[0] = '\0';
	while (str[i] == '0')
		i++;
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb[i - start] = str[i];
		i++;
	}
	if (str[i] == '.')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			return (0);
	}
	nb[i - start] = '\0';
	return (nb);
}
