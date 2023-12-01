/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:13:49 by hdorado-          #+#    #+#             */
/*   Updated: 2023/12/01 18:31:41 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_valid_atoi(char *str)
{

}

int	ft_check_args(int argc, char **argv, t_conditions *rules)
{
	if (ft_valid_atoi(argv[1]))
		(*rules).n_phil = ft_atoi(argv[1]);
	else
		return (0);
	if (ft_valid_atoi(argv[2]))
		(*rules).t_die = ft_atoi(argv[2]);
	else
		return (0);
	if (ft_valid_atoi(argv[3]))
		(*rules).t_eat = ft_atoi(argv[3]);
	else
		return (0);
	if (ft_valid_atoi(argv[4]))
		(*rules).t_sleep = ft_atoi(argv[4]);
	else
		return (0);
	if (ft_valid_atoi(argv[5]))
		(*rules).req_eat = ft_atoi(argv[5]);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_conditions	rules;

	if (argc != 5 || argc != 6)
		return (0);
	i = 1;
	if (!ft_check_args(argc, argv, &rules))
		return (0);
}
