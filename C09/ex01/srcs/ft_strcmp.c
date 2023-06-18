/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:10:13 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/30 14:37:22 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strcmp(char *s1, char *s2)
{
	int	length_s1;
	int	length_s2;
	int	i;

	i = 0;
	while ((s1[i] != 0) && (s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	if (length_s1 == length_s2)
		return (0);
	else if (length_s1 > length_s2)
		return (s1[i]);
	else
		return (-s2[i]);
}

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
