/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:02:14 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/05 11:45:18 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	i = 1;
	if ((str[0] >= 'a') && (str[0] <= 'z'))
		str[0] = str[0] - 32;
	while (str[i] != 0)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (!(str[i - 1] >= 65 && str[i - 1] <= 90))
			{
				if (!(str[i - 1] >= 97 && str[i - 1] <= 122))
				{
					if (!(str[i - 1] >= 48 && str[i - 1] <= 57))
						str[i] = str[i] - 32;
				}
			}
		}
		i++;
	}
	return (str);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] +32;
		}
		i++;
	}
	return (str);
}
