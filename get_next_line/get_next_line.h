/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:49:15 by hdorado-          #+#    #+#             */
/*   Updated: 2023/01/17 20:55:17 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_append(char *str, char *buffer);
char	*ft_return_line(char *buffer, char *str, char **tmp);
char	*read_next_line(char **buffer, char **str, char **tmp, int fd);
char	*ft_error(char **str, char **tmp);
void	ft_bzero(void *s, size_t n);
int		ft_strlcpy(char *dst, const char *src, int size);
int		ft_strlen(const char *s);
int		ft_search_nl(char *str);

#endif
