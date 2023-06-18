/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:51:10 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/03 20:58:09 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_solve_once(int **array, int *conditions);
int		count_element_argv(char **argv);
int		*arg_to_array(char **argv);
int		ft_impossible(int *str);
void	recursive_rules(int **array, int *conditions);
void	ft_putchar(char x);
void	display(int **array);
void	print_error(void);

int	main(int argc, char **argv)
{
	int	*conditions;
	int	**array;
	int	i;

	conditions = arg_to_array(argv);
	if ((argc != 2) || (ft_impossible(conditions) == 0))
	{
		print_error();
		return (0);
	}
	array = malloc(sizeof(int *) * 4);
	i = -1;
	while (i++ < 4)
		array[i] = malloc(4 * sizeof(int));
	i = -1;
	while (i++ < 16)
		array[i / 4][i % 4] = 0;
	ft_solve_once(array, conditions);
	recursive_rules(array, conditions);
	display(array);
	free(array);
	free(conditions);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
