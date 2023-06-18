/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:58:26 by avarghes          #+#    #+#             */
/*   Updated: 2022/07/03 21:02:12 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_element_argv(char **argv)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = &argv[1][0];
	while (*ptr)
	{
		if (*ptr >= '0' && *ptr <= '9')
			count++;
		ptr++;
	}
	return (count);
}

int	*arg_to_array(char **argv)
{
	int		row;
	int		i;
	int		*arr;
	char	*ptr;

	i = 0;
	row = count_element_argv(argv);
	arr = (int *)malloc(row * sizeof(int));
	ptr = &argv[1][0];
	while (*ptr)
	{
		if (*ptr >= '0' && *ptr <= '9')
		{
			arr[i] = ((int)(*ptr)) - '0';
			i++;
		}
		ptr++;
	}
	return (arr);
}
