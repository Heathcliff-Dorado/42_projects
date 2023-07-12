/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraf <mgraf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:13:27 by mgraf             #+#    #+#             */
/*   Updated: 2022/07/13 11:13:14 by mgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

typedef struct s_info
{
	int		lines;
	int		length;
	char	c_empty;
	char	c_obstacle;
	char	c_full;
	char	**map;
}	t_info;

char	*ft_read_text(char *path, int *error);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcpy_nzb(char *dest, char *src);
int		**find_square(int **array, int nrow, int ncol);
int		**create_int_array(t_info *map);
int		**populate_array(int **array, t_info *map);
int		find_max_position(t_info *map, int **array, int *col, int *row);
t_info	*change_map(t_info *map, int c, int r, int max);
int		ft_check_ll(char *text);
t_info	ft_extract_info(char *text, int *error);
t_info	ft_extract_map(t_info info, char *text);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_first_line(char *text);
int		ft_length(char *text);
int		ft_simple_atoi(char *str);
int		ft_characters(char *path);
int		ft_check(t_info info);
t_info	ft_malloc_map(t_info info, char *text);
int		ft_check(t_info info);
int		check_error(int test, int *error);
int		read_stdin(void);
int		ft_file_from_input(char *text);
int		create_structure(char *text, t_info *info, int *error);
int		**ft_solver(t_info *info, int **array);
void	free_info(t_info info);

#endif
