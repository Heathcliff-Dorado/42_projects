/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:54:58 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 20:11:03 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct s_dict
{
	int				array[2];
	char			*name;
	struct s_dict	*link;
}			t_dict;

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

#include <stdio.h>
#include <unistd.h>

int	print_nbr(char *nbr, t_dict **dictionary)
{
	int	length;
	int	i;
	
	length = ft_strlen(nbr);
	if (check_too_big(length, dictionary) == -1)
		return (-1);
	i = 0;
	while ((length - i) > 0)
	{
		if ((length - i) % 3 == 0)
			print_three_digits(length, &i, dictionary, nbr);
		else if ((length - i) % 3 == 2)
			print_two_digits(length, &i, dictionary, nbr);
		else
			print_one_digits(length, &i, dictionary, nbr);
	}
	return (0);
}

void	print_three_digits(int length, int *ptr, t_dict **dictionary, char *nbr)
{
	t_dict	*beginning;

	if (nbr[*ptr] != '0')
	{
		beginning = *dictionary;
		while ((*dictionary)->array[0] != (nbr[*ptr] - 48) || (*dictionary)->array[1] != 0)
			*dictionary = (*dictionary)->link;
		if (*ptr != 0)
			write(1, " ", 1);
		ft_putstr((*dictionary)->name);
		*dictionary = beginning;
		while ((*dictionary)->array[0] != 1 || (*dictionary)->array[1] != 2)
			*dictionary = (*dictionary)->link;
		if (*ptr != 0)
			write(1, " ", 1);
		ft_putstr((*dictionary)->name);
		(*ptr)++;
		*dictionary = beginning;
	}
	else
		(*ptr)++;
	print_two_digits(length, ptr, dictionary, nbr);
}

void	print_two_digits(int length, int *ptr, t_dict **dictionary, char *nbr)
{
	t_dict	*beginning;

	beginning = *dictionary;
	if (nbr[*ptr] != '0')
	{
		if (nbr[*ptr] != '1')
		{
			while ((*dictionary)->array[0] != (nbr[*ptr] - 48) * 10 || (*dictionary)->array[1] != 0)
				*dictionary = (*dictionary)->link;
			if (*ptr != 0)
				ft_putchar(' ');
			ft_putstr((*dictionary)->name);
			(*ptr)++;
			*dictionary = beginning;
			print_one_digits(length, ptr, dictionary, nbr);
		}
		else
		{
			while ((*dictionary)->array[0] != (nbr[*ptr + 1] - 48) + 10 || (*dictionary)->array[1] != 0)
				*dictionary = (*dictionary)->link;
			if (*ptr != 0)
				ft_putchar(' ');
			ft_putstr((*dictionary)->name);
			*ptr += 2;
			*dictionary = beginning;
			check_power(length, ptr, dictionary, nbr);
		}
	}
	else
	{
		(*ptr)++;
		print_one_digits(length, ptr, dictionary, nbr);
	}
}

void	print_one_digits(int length, int *ptr, t_dict **dictionary, char *nbr)
{
	t_dict	*beginning;

	beginning = *dictionary;
	if (nbr[*ptr] != '0')
	{
		while ((*dictionary)->array[0] != (nbr[*ptr] - 48) || (*dictionary)->array[1] != 0)
			*dictionary = (*dictionary)->link;
		if (*ptr != 0)
			ft_putchar(' ');
		ft_putstr((*dictionary)->name);
		*dictionary = beginning;
	}
	(*ptr)++;
	check_power(length, ptr, dictionary, nbr);
}

int	check_power(int length, int *ptr, t_dict **dictionary, char *nbr)
{
	if (nbr[*ptr - 1] == '0')
	{
		if (nbr[*ptr - 2] == '0')
		{
			if (nbr[*ptr - 3] == '0')
				return (0);
			else
				print_power(length, ptr, dictionary);
		}
		else
			print_power(length, ptr, dictionary);
	}
	else
		print_power(length, ptr, dictionary);
	return (0);
}

void	print_power(int length, int *ptr, t_dict **dictionary)
{
	if (length - *ptr > 2)
	{
		while ((*dictionary)->array[0] != 1 || (*dictionary)->array[1] != (length - *ptr))
			*dictionary = (*dictionary)->link;
		if (*ptr != 0)
			ft_putchar(' ');
		ft_putstr((*dictionary)->name);
	}
}

int	check_too_big(int length, t_dict **dictionary)
{
	int	max;
	
	max = 0;
	while (*dictionary)
	{
		if ((*dictionary)->array[1] > max)
			max = (*dictionary)->array[1];
		if ((*dictionary)->array[1] == 0)
			break;
		*dictionary = (*dictionary)->link;
	}
	if (((length - 1)/ 3) > (max / 3))
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	return (1);	
}
