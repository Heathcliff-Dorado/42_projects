/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklineforrules.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmesropo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:01:41 by tmesropo          #+#    #+#             */
/*   Updated: 2022/07/10 22:01:49 by tmesropo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checklineforrules(char *str)
{
	int		i;
	int		j;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (-1);
	i++;
	while (str[i] == ' ')
		i++;
	j = i;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (-1);
		i++;
	}
	if (j == i)
		return (-1);
	return (1);
}
