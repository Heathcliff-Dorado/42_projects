/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:23:22 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/29 19:29:49 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	if (str[0] == 0)
	{
		return (1);
	}
	while (*str != 0)
	{
		if ((*str >= 1 && *str <= 31) || (*str == 127))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
