/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:58:44 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/03 19:59:03 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_disable_all(t_font font)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		font.one->instances[i].enabled = 0;
		font.two->instances[i].enabled = 0;
		font.three->instances[i].enabled = 0;
		font.four->instances[i].enabled = 0;
		font.five->instances[i].enabled = 0;
		font.six->instances[i].enabled = 0;
		font.seven->instances[i].enabled = 0;
		font.eight->instances[i].enabled = 0;
		font.nine->instances[i].enabled = 0;
		i++;
	}
}

void	ft_enable(t_game *g, int i)
{
	g->sp.fnt.zero->instances[i].enabled = true;
	g->sp.fnt.one->instances[i].enabled = true;
	g->sp.fnt.two->instances[i].enabled = true;
	g->sp.fnt.three->instances[i].enabled = true;
	g->sp.fnt.four->instances[i].enabled = true;
	g->sp.fnt.five->instances[i].enabled = true;
	g->sp.fnt.six->instances[i].enabled = true;
	g->sp.fnt.seven->instances[i].enabled = true;
	g->sp.fnt.eight->instances[i].enabled = true;
	g->sp.fnt.nine->instances[i].enabled = true;
}

void	ft_change_score(t_game *g, int digit, int i)
{
	ft_enable(g, i);
	if (digit != 0)
		g->sp.fnt.zero->instances[i].enabled = 0;
	if (digit != 1)
		g->sp.fnt.one->instances[i].enabled = 0;
	if (digit != 2)
		g->sp.fnt.two->instances[i].enabled = 0;
	if (digit != 3)
		g->sp.fnt.three->instances[i].enabled = 0;
	if (digit != 4)
		g->sp.fnt.four->instances[i].enabled = 0;
	if (digit != 5)
		g->sp.fnt.five->instances[i].enabled = 0;
	if (digit != 6)
		g->sp.fnt.six->instances[i].enabled = 0;
	if (digit != 7)
		g->sp.fnt.seven->instances[i].enabled = 0;
	if (digit != 8)
		g->sp.fnt.eight->instances[i].enabled = 0;
	if (digit != 9)
		g->sp.fnt.nine->instances[i].enabled = 0;
}
