/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:37 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/30 18:45:18 by hdorado-         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;

	i = ft_strlen(dest);
	while (*src != 0 && nb > 0)
	{
		dest[i] = *src;
		src++;
		i++;
		nb--;
	}
	dest[i] = 0;
	return (dest);
}
