/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:39:53 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/03 09:42:44 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_update_moves(t_game *g)
{
	int	digit;
	int	leftover;
	int	i;

	if (g->n_moves != g->n_moves_bak && g->n_moves < 10000)
	{
		digit = g->n_moves % 10;
		leftover = g->n_moves / 10;
		i = 4;
		while (i >= 0)
		{
			ft_change_score(g, digit, i);
			digit = leftover % 10;
			leftover = leftover / 10;
			i--;
		}
		g->n_moves_bak = g->n_moves;
	}
	else if (g->n_moves > 9999)
		g->n_moves = 9999;
}

void	ft_update_game(void *param)
{
	t_game	**g;

	g = param;
	(*g)->n_frames++;
	if ((*g)->pl->moving)
	{
		ft_moving((*g));
		ft_update_moves((*g));
	}
	if ((*g)->map[(*g)->pl->pos.y][(*g)->pl->pos.x] == 'C')
	{
		(*g)->col_bak--;
		(*g)->sp.cover->instances[(*g)->col_bak].x = (*g)->pl->win_pos.x;
		(*g)->sp.cover->instances[(*g)->col_bak].y = (*g)->pl->win_pos.y;
		(*g)->map[(*g)->pl->pos.y][(*g)->pl->pos.x] = '0';
	}
	if ((*g)->col_bak == 0 && !((*g)->sp.triforceon->enabled))
		(*g)->sp.triforceon->enabled = true;
	if ((*g)->map[(*g)->pl->pos.y][(*g)->pl->pos.x] == 'E' &&
		(*g)->sp.triforceon->enabled)
	{
		ft_printf("YOU WON! and it only took you %d moves!\n", (*g)->n_moves);
		sleep(1);
		mlx_close_window((*g)->id);
	}
}

void	ft_setgame(t_game *g, char **m, t_layout *lay)
{
	int	ret;

	ret = 1;
	g->n_frames = 1;
	g->w = lay->col * SIZE;
	g->h = lay->row * SIZE + 80;
	g->layout = lay;
	g->map = m;
	if (!ft_initsprites(g))
		ret = 0;
	g->n_moves_bak = 0;
	if (!ft_load_font(g))
		ret = 0;
	ft_draw(g);
	ft_load_links(g);
	mlx_key_hook(g->id, my_keyhook, &g);
	mlx_loop_hook(g->id, ft_update_game, &g);
	mlx_loop(g->id);
	mlx_terminate(g->id);
	ft_freegame(g);
}

void	ft_initgame(char **map, t_layout lay)
{
	t_game	g;

	g.lay_bak = lay;
	g.col_bak = lay.collect;
	ft_dupmap(map, &(g.map_bak));
	g.id = mlx_init(lay.col * SIZE, lay.row * SIZE + 80,
			"TLOZ - A lame 42 story", true);
	g.w_id = mlx_new_image(g.id, lay.col * SIZE, lay.row * SIZE + 80);
	ft_setgame(&g, map, &lay);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_layout	layout;
	int			ret;

	map = NULL;
	ft_newlayout(&layout);
	ret = parse_map(argc, argv, &layout, &map);
	if (ret < 0)
	{
		ft_error_handling(ret);
		return (0);
	}
	ft_initgame(map, layout);
	return (0);
}
