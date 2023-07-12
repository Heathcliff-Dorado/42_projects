/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:45:02 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/03 23:05:47 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	three_of_the_same(int **array);
void	ft_only_1_option(int **array);
void	ft_rule_of_3(int **a, int ap);
void	ft_rule_of_2(int **a, int ap);
void	check_conditions(int **array, int *conditions);

void	recursive_rules(int **array, int *conditions)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i == 0)
	{
		three_of_the_same(array);
		ft_only_1_option(array);
		check_conditions(array, conditions);
		j = -1;
		count = 0;
		while (++j < 16)
		{
			if (array[j / 4][j % 4] == 0)
				count++;
		}
		if (count == 0)
			i = 1;
	}
}

void	check_conditions(int **array, int *conditions)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (conditions[j] == 3)
			ft_rule_of_3(array, j);
		if (conditions[j] == 2)
			ft_rule_of_2(array, j);
		j++;
	}
}
