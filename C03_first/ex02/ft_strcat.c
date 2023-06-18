/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:37 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/30 18:39:51 by hdorado-         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = ft_strlen(dest);
	while (*src != 0)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
