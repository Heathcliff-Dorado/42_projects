/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:10:13 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:50 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	length_s1;
	unsigned int	length_s2;
	unsigned int	i;

	i = 0;
	while ((s1[i] != 0) && (s2[i] != 0) && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
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
