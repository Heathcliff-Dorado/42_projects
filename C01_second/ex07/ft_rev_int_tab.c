/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:58:23 by hdorado-          #+#    #+#             */
/*   Updated: 2022/06/28 16:52:18 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	reverse;

	i = 0;
	reverse = size - 1;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[reverse];
		tab[reverse] = tmp;
		reverse--;
		i++;
	}
}
