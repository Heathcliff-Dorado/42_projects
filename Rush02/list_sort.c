/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:08:22 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 22:11:12 by tmesropo         ###   ########.fr       */
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

void	ft_list_swap(t_dict *liste)
{
	int		nb;
	int		suf;
	char	*literal;

	nb = liste->array[0];
	suf = liste->array[1];
	literal = liste->name;
	liste->array[0] = liste->link->array[0];
	liste->array[1] = liste->link->array[1];
	liste->name = liste->link->name;
	liste->link->array[0] = nb;
	liste->link->array[1] = suf;
	liste->link->name = literal;
}

void	ft_list_sort(t_dict **begin_list)
{
	t_dict	*a;
	t_dict	*b;

	a = *begin_list;
	while (a != NULL)
	{
		b = *begin_list;
		while (b->link != NULL)
		{
			printf("%d and %d, %s\n", (a)->array[0], (a)->array[1], (a)->name);
			printf("%d and %d, %s\n", (b)->array[0], (b)->array[1], (b)->name);
			if (b->array[0] < b->link->array[0])
				ft_list_swap(b);
			b = b->link;
		}
		a = a->link;
	}
}

