/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:51:19 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 21:53:24 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct s_dict
{
	int				array[2];
	char			*name;
	struct s_dict	*link;
}			t_dict;

#include <stdlib.h>

void	print_three_digits(int length, int *ptr, t_dict **dictionary, char *nbr);
void	print_two_digits(int length, int *ptr, t_dict **dictionary, char *nbr);
void	print_one_digits(int length, int *ptr, t_dict **dictionary, char *nbr);
int		check_power(int length, int *ptr, t_dict **dictionary, char *nbr);
void	print_power(int length, int *ptr, t_dict **dictionary);
char	*clean_parameter(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		open_dict(char *path, t_dict **dictionary);
int		read_file(int file, t_dict **dictionary);
int		parse_dictionary(char *str, t_dict **dictionary);
int		check_too_big(int length, t_dict **dictionary);

void	free_memory(t_dict **dictionary)
{
	t_dict	*tmp;
	t_dict	*beginning;

	beginning = *dictionary;
	if (beginning)
		while (beginning)
		{
			if (beginning->array[0] == 0)
				break;
			tmp = beginning->link;
			free(beginning->name);
			free(beginning);
			beginning = tmp;
		}
}

