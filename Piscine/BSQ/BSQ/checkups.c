/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:36:52 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/13 17:36:56 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_i_after_fl(char *text)
{
	int	i;

	i = 0;
	while (text[i] != '\n')
		i++;
	i++;
	return (i);
}

int	ft_length_sl(char *text)
{
	int	i;
	int	l;

	i = ft_i_after_fl(text);
	l = 0;
	while (text[i] != '\n')
	{
		i++;
		l++;
	}
	return (l);
}

int	ft_check_ll(char *text)
{
	int	i;
	int	l;
	int	l_max;

	i = ft_i_after_fl(text);
	l_max = ft_length_sl(text);
	while (text[i] != '\0')
	{
		l = 0;
		while (text[i] != '\n')
		{
			i++;
			l++;
		}
		if (text[i] == '\n' || text[i] == '\0')
		{
			if (l_max != l)
				return (-1);
		}
		i++;
	}
	return (l_max);
}
