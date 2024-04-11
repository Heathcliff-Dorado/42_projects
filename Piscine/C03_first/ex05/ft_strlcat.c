/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:37 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/30 22:44:00 by hdorado-         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;

	i = ft_strlen(dest);
	while (*src != 0 && (size -1) > i)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(dest));
}
