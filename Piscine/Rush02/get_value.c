/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:24:20 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/10 13:42:27 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	*get_value(char *str)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * 2);
	i = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
		i++;
	if (i - 1 < 2)
	{
		array[0] = ft_atoi(str);
		array[1] = 0;
	}
	else
	{
		if (str[0] == '1')
			array[0] = 1;
		else
			return (0);
		array[1] = i - 1;
	}
	return (array);
}

int	ft_atoi(char *str)
{
	int	number;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (((str[i] >= '\t') && (str[i] <= '\r')) || (str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
	}
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * sign);
}
