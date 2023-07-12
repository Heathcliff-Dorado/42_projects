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

void	check_un(int *p1, int *p2, int *p3, int *p4);
void	check_two(int *p1, int *p2, int *p3, int *p4);
void	ft_fill(int *p1, int *p2, int a, int b);

void	ft_rule_of_3(int **a, int ap)
{
	if (ap < 4)
	{
		check_un(&a[0][ap % 4], &a[1][ap % 4], &a[2][ap % 4], &a[3][ap % 4]);
		check_two(&a[0][ap % 4], &a[1][ap % 4], &a[2][ap % 4], &a[3][ap % 4]);
	}
	if (ap > 3 && ap < 8)
	{
		check_un(&a[3][ap % 4], &a[2][ap % 4], &a[1][ap % 4], &a[0][ap % 4]);
		check_two(&a[3][ap % 4], &a[2][ap % 4], &a[1][ap % 4], &a[0][ap % 4]);
	}
	if (ap > 7 && ap < 12)
	{
		check_un(&a[ap % 4][0], &a[ap % 4][1], &a[ap % 4][2], &a[ap % 4][3]);
		check_two(&a[ap % 4][0], &a[ap % 4][1], &a[ap % 4][2], &a[ap % 4][3]);
	}
	if (ap > 11)
	{
		check_un(&a[ap % 4][3], &a[ap % 4][2], &a[ap % 4][1], &a[ap % 4][0]);
		check_two(&a[ap % 4][3], &a[ap % 4][2], &a[ap % 4][1], &a[ap % 4][0]);
	}
}

void	check_un(int *p1, int *p2, int *p3, int *p4)
{
	if (*p3 == 2)
	{
		ft_fill(p1, p2, 1, 3);
		ft_fill(p1, p4, 1, 4);
	}
	if (*p3 == 1)
	{
		ft_fill(p1, p2, 2, 3);
		ft_fill(p1, p4, 2, 4);
	}
	if (*p2 == 2)
	{
		ft_fill(p1, p3, 1, 4);
		ft_fill(p1, p4, 1, 3);
	}
	if (*p2 == 1)
	{
		ft_fill(p1, p3, 2, 3);
		ft_fill(p1, p4, 2, 4);
	}
	if (*p1 == 2 && *p3 == 4)
		ft_fill(p2, p4, 3, 1);
	if (*p1 == 1 && *p4 == 4)
		ft_fill(p2, p3, 2, 3);
}

void	check_two(int *p1, int *p2, int *p3, int *p4)
{
	if (*p4 == 3)
	{
		ft_fill(p1, p2, 1, 2);
		ft_fill(p2, p3, 2, 4);
	}
	if (*p4 == 2)
	{
		ft_fill(p1, p2, 1, 3);
		ft_fill(p1, p3, 1, 4);
	}
	if (*p4 == 1)
	{
		ft_fill(p1, p2, 2, 3);
		ft_fill(p1, p3, 2, 4);
	}
	if (*p3 == 3)
	{
		ft_fill(p1, p2, 2, 1);
		ft_fill(p1, p4, 2, 4);
	}
}

void	ft_fill(int *p1, int *p2, int a, int b)
{
	*p1 = a;
	*p2 = b;
}
