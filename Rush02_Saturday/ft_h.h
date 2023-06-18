/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skleidei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:48:38 by skleidei          #+#    #+#             */
/*   Updated: 2022/07/10 21:28:38 by skleidei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H//include guards
# define FT_H_H//seems to check the ifndef??

//#define __BUFF 8 //seems to be working without it...

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_dict
{
	int				array[2];
	char			*name;
	struct s_dict	*link;
}				t_dict;

char		*clean_parameter(char *str);
t_dict		*add_entry(int *array, char *nbr_letter);
t_dict		*add_entry(int *array, char *nbr_letter);
char		*returnliteral(char *src);
int			*get_value(char *str);
void		ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_strlen(char *str);
int			open_dict(char *path, t_dict **dictionary);
int			read_file(int file, t_dict **dictionary);
int			parse_dictionary(char *str, t_dict **dictionary);
int			ft_atoi(char *str);
int			print_nbr(char *nbr, t_dict **dictionary);
void		ft_list_sort(t_dict **begin_list);
int			checklineforrules(char *str);
int			write_dict(t_dict **dictionary, int *array, char *nbr_letter);
void		print_three_digits(int length, int *ptr, t_dict **dictionary, char *nbr);
void		print_two_digits(int length, int *ptr, t_dict **dictionary, char *nbr);
void		print_one_digits(int length, int *ptr, t_dict **dictionary, char *nbr);
int			check_power(int length, int *ptr, t_dict **dictionary, char *nbr);
void		print_power(int length, int *ptr, t_dict **dictionary);

#endif
