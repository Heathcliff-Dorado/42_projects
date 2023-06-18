/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:44:29 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/30 23:20:55 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (*str)
	{
		a++;
		str++;
	}
	return (a);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	length_query;
	int	i;
	int	start;
	int	j;

	length_query = ft_strlen(to_find);
	if ((*str == 0) && (*to_find == 0))
		return (0);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			start = i;
			j = 0;
			while ((str[i + j] == to_find[j]) && (j < length_query))
				j++;
			if (j == length_query)
				return (&str[start]);
		}
		i++;
	}
	return (0);
}
