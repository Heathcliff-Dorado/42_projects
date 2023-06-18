/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:49:15 by hdorado-          #+#    #+#             */
/*   Updated: 2023/01/17 19:41:57 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr_recursive(unsigned int num);
int	ft_puthexa_recursive(unsigned long num, char c);
int	ft_putunint(unsigned int num);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long ptr);
int	ft_puthexa(unsigned int num, char c);
int	ft_putnbr(int num);
int	ft_eval_format(va_list args, char c);

#endif
