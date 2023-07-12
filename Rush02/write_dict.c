/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:36:15 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 22:12:00 by tmesropo         ###   ########.fr       */
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
int		open_dict(char *path);
int		read_file(int file);

t_dict	*add_entry(int *array, char *nbr_letter);

int	write_dict(t_dict **dictionary, int *array, char *nbr_letter)
{
	t_dict	*new;

	if (dictionary)
	{
		new = add_entry(array, nbr_letter);
		new->link = *dictionary;
		*dictionary = new;
	}
	else
	{
		*dictionary = add_entry(array, nbr_letter);
	}
	return (1);
}

t_dict	*add_entry(int *array, char *nbr_letter)
{
	t_dict	*entry;
	int		length;

	entry = NULL;
	entry = malloc(sizeof(t_dict));
	entry->array[0] = array[0];
	entry->array[1] = array[1];
	length = ft_strlen(nbr_letter);
	entry->name = (char *)malloc(sizeof(char) * (length + 1));
	entry->name = nbr_letter;
	entry->link = NULL;
	return (entry);
}
