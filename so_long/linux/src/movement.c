#include "../inc/so_long.h"

void	ft_moving_north(t_game *g)
{
	if (g->pl->sprites.up->next)
	{
		g->pl->win_pos.y = g->pl->win_pos.y - 3;
		g->pl->sprites.up->content->enabled = 0;
		g->pl->sprites.up = g->pl->sprites.up->next;
		g->pl->sprites.up->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.up->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.up->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.y = g->pl->win_pos.y - 2;
		g->pl->sprites.up->content->enabled = 0;
		g->pl->sprites.up = g->pl->sprites.up_bak;
		g->pl->sprites.up->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.up->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.up->content->enabled = true;
		g->pl->pos.y--;
		g->n_moves++;
		g->pl->moving = 0;
	}
}

void	ft_moving_south(t_game *g)
{
	if (g->pl->sprites.down->next)
	{
		g->pl->win_pos.y = g->pl->win_pos.y + 3;
		g->pl->sprites.down->content->enabled = 0;
		g->pl->sprites.down = g->pl->sprites.down->next;
		g->pl->sprites.down->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.down->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.down->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.y = g->pl->win_pos.y + 2;
		g->pl->sprites.down->content->enabled = 0;
		g->pl->sprites.down = g->pl->sprites.down_bak;
		g->pl->sprites.down->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.down->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.down->content->enabled = true;
		g->pl->pos.y++;
		g->n_moves++;
		g->pl->moving = 0;
	}
}

void	ft_moving_west(t_game *g)
{
	if (g->pl->sprites.left->next)
	{
		g->pl->win_pos.x = g->pl->win_pos.x - 3;
		g->pl->sprites.left->content->enabled = 0;
		g->pl->sprites.left = g->pl->sprites.left->next;
		g->pl->sprites.left->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.left->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.left->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.x = g->pl->win_pos.x - 2;
		g->pl->sprites.left->content->enabled = 0;
		g->pl->sprites.left = g->pl->sprites.left_bak;
		g->pl->sprites.left->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.left->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.left->content->enabled = true;
		g->pl->pos.x--;
		g->n_moves++;
		g->pl->moving = 0;
	}
}

void	ft_moving_east(t_game *g)
{
	if (g->pl->sprites.right->next)
	{
		g->pl->win_pos.x = g->pl->win_pos.x + 3;
		g->pl->sprites.right->content->enabled = 0;
		g->pl->sprites.right = g->pl->sprites.right->next;
		g->pl->sprites.right->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.right->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.right->content->enabled = true;
	}
	else
	{
		g->pl->win_pos.x = g->pl->win_pos.x + 2;
		g->pl->sprites.right->content->enabled = 0;
		g->pl->sprites.right = g->pl->sprites.right_bak;
		g->pl->sprites.right->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.right->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.right->content->enabled = true;
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
