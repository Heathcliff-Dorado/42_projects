/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:58:52 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/03 21:02:01 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_changedir2(t_game *g, int dir)
{
	if (dir == W)
	{
		g->pl->sp.left->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.left->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.left->content->enabled = true;
	}
	if (dir == E)
	{
		g->pl->sp.right->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.right->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.right->content->enabled = true;
	}
}

void	ft_changedir(t_game *g, int dir)
{
	g->pl->sp.up->content->enabled = 0;
	g->pl->sp.down->content->enabled = 0;
	g->pl->sp.left->content->enabled = 0;
	g->pl->sp.right->content->enabled = 0;
	if (dir == N)
	{
		g->pl->sp.up->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.up->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.up->content->enabled = true;
	}
	if (dir == S)
	{
		g->pl->sp.down->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sp.down->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sp.down->content->enabled = true;
	}
	if (dir == E || dir == W)
		ft_changedir2(g, dir);
	g->pl->dir = dir;
}

int	ft_moveallowed(t_game *g)
{
	if (g->pl->dir == N && g->map_bak[g->pl->pos.y - 1][g->pl->pos.x] != '1')
		return (1);
	if (g->pl->dir == S && g->map_bak[g->pl->pos.y + 1][g->pl->pos.x] != '1')
		return (1);
	if (g->pl->dir == W && g->map_bak[g->pl->pos.y][g->pl->pos.x - 1] != '1')
		return (1);
	if (g->pl->dir == E && g->map_bak[g->pl->pos.y][g->pl->pos.x + 1] != '1')
		return (1);
	return (0);
}

void	choose_action(t_game *g, int dir)
{
	if (g->pl->dir != dir)
		ft_changedir(g, dir);
	else if (ft_moveallowed(g))
		g->pl->moving = 1;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	**g;
	mlx_t	*mlx;

	g = param;
	mlx = (*g)->id;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
	if (!((*g)->pl->moving))
	{
		if (keydata.key == MLX_KEY_UP)
			choose_action((*g), N);
		else if (keydata.key == MLX_KEY_DOWN)
			choose_action((*g), S);
		else if (keydata.key == MLX_KEY_LEFT)
			choose_action((*g), W);
		else if (keydata.key == MLX_KEY_RIGHT)
			choose_action((*g), E);
	}
}
