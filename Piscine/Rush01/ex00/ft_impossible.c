/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impossible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:46:33 by nseropia          #+#    #+#             */
/*   Updated: 2022/07/03 16:13:06 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sum(int i, int *str);
int	checking_for_ones(int i, int *str);

int	ft_impossible(int *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 16)
	{
		return (0);
	}
	if (check_sum(0, str) == 0)
		return (0);
	if (check_sum(8, str) == 0)
		return (0);
	if (checking_for_ones(0, str) == 0)
		return (0);
	if (checking_for_ones(4, str) == 0)
		return (0);
	if (checking_for_ones(8, str) == 0)
		return (0);
	if (checking_for_ones(12, str) == 0)
		return (0);
	return (1);
}

int	checking_for_ones(int i, int *str)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (i + x <= i + 3)
	{
		if (str[i + x] == 1)
			j++;
		x++;
	}
	if (j != 1)
		return (0);
	return (1);
}

int	check_sum(int i, int *str)
{
	int	x;

	x = 0;
	while (i + x <= i + 3)
	{
		if (str[x + i] + str[x + i + 4] > 5 || str[x + i] + str[x + i + 4] < 3)
		{
			return (0);
		}
		x++;
	}
	return (1);
}
