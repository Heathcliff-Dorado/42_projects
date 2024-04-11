/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:40:16 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/01 22:23:02 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_moving_north(t_game *g)
{
	if (g->pl->sp.up->next)
	{
		g->pl->win_pos.y = g->pl->win_pos.y - 3;
		g->pl->sp.up->content->enabled = 0;
		g->pl->sp.up = g->pl->sp.up->next;
		g->pl->sp.up->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.up->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.up->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.y = g->pl->win_pos.y - 2;
		g->pl->sp.up->content->enabled = 0;
		g->pl->sp.up = g->pl->sp.up_bak;
		g->pl->sp.up->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.up->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.up->content->enabled = true;
		g->pl->pos.y--;
		g->n_moves++;
		g->pl->moving = 0;
	}
}

void	ft_moving_south(t_game *g)
{
	if (g->pl->sp.down->next)
	{
		g->pl->win_pos.y = g->pl->win_pos.y + 3;
		g->pl->sp.down->content->enabled = 0;
		g->pl->sp.down = g->pl->sp.down->next;
		g->pl->sp.down->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.down->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.down->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.y = g->pl->win_pos.y + 2;
		g->pl->sp.down->content->enabled = 0;
		g->pl->sp.down = g->pl->sp.down_bak;
		g->pl->sp.down->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.down->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.down->content->enabled = true;
		g->pl->pos.y++;
		g->n_moves++;
		g->pl->moving = 0;
	}
}

void	ft_moving_west(t_game *g)
{
	if (g->pl->sp.left->next)
	{
		g->pl->win_pos.x = g->pl->win_pos.x - 3;
		g->pl->sp.left->content->enabled = 0;
		g->pl->sp.left = g->pl->sp.left->next;
		g->pl->sp.left->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.left->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.left->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.x = g->pl->win_pos.x - 2;
		g->pl->sp.left->content->enabled = 0;
		g->pl->sp.left = g->pl->sp.left_bak;
		g->pl->sp.left->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.left->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.left->content->enabled = true;
		g->pl->pos.x--;
		g->n_moves++;
		g->pl->moving = 0;
	}
}

void	ft_moving_east(t_game *g)
{
	if (g->pl->sp.right->next)
	{
		g->pl->win_pos.x = g->pl->win_pos.x + 3;
		g->pl->sp.right->content->enabled = 0;
		g->pl->sp.right = g->pl->sp.right->next;
		g->pl->sp.right->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.right->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.right->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.x = g->pl->win_pos.x + 2;
		g->pl->sp.right->content->enabled = 0;
		g->pl->sp.right = g->pl->sp.right_bak;
		g->pl->sp.right->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.right->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.right->content->enabled = true;
		g->pl->pos.x++;
		g->n_moves++;
		g->pl->moving = 0;
	}
}

void	ft_moving(t_game *g)
{
	if (g->pl->dir == N)
		ft_moving_north(g);
	if (g->pl->dir == S)
		ft_moving_south(g);
	if (g->pl->dir == W)
		ft_moving_west(g);
	if (g->pl->dir == E)
		ft_moving_east(g);
}
