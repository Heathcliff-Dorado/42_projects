/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_of_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:26:43 by hdorado-          #+#    #+#             */
/*   Updated: 2022/07/03 19:43:58 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_three(int *p1, int *p2, int *p3, int *p4);
void	ft_fill(int *p1, int *p2, int a, int b);

void	ft_rule_of_2(int **a, int ap)
{
	if (ap < 4)
	{
		check_three(&a[0][ap % 4], &a[1][ap % 4], &a[2][ap % 4], &a[3][ap % 4]);
	}
	if (ap > 3 && ap < 8)
	{
		check_three(&a[3][ap % 4], &a[2][ap % 4], &a[1][ap % 4], &a[0][ap % 4]);
	}
	if (ap > 7 && ap < 12)
	{
		check_three(&a[ap % 4][0], &a[ap % 4][1], &a[ap % 4][2], &a[ap % 4][3]);
	}
	if (ap > 11)
	{
		check_three(&a[ap % 4][3], &a[ap % 4][2], &a[ap % 4][1], &a[ap % 4][0]);
	}
}

void	check_three(int *p1, int *p2, int *p3, int *p4)
{
	if (*p3 == 4 && *p4 == 3)
	{
		ft_fill(p1, p2, 2, 1);
	}
}
