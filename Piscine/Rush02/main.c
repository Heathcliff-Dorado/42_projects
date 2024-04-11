/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:21:37 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 22:05:25 by tmesropo         ###   ########.fr       */
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
int		print_nbr(char *nbr, t_dict **dictionary);
void	free_memory(t_dict **dictionary);

int	main(int argc, char **argv)
{
	char	*dict;
	char	*nb;
	char	*number;
	t_dict	*dictionary;

	if (argc == 2)
	{
		number = argv[1];
		dict = "numbers.dict";
	}
	else if (argc == 3)
	{
		number = argv[2];
		dict = argv[1];
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	nb = clean_parameter(number);
	if (nb == 0)
	{
		free(nb);
		ft_putstr("Error\n");
		return (0);
	}
	if (open_dict(dict, &dictionary) == 0)
		return (0);
	if (print_nbr(nb, &dictionary) == -1)
		return (0);
	free(nb);
	free_memory(&dictionary);
}
