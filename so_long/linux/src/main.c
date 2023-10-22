#include "../inc/so_long.h"

void	ft_error_handling(int errno)
{
	ft_printf("Error\n");
	if (errno == -1)
		ft_putstr_fd("Please provide (only) path to map\n", 2);
	if (errno == -2)
		ft_putstr_fd("Map extension should be .ber\n", 2);
	if (errno == -3)
		ft_putstr_fd("Unable to open map\n", 2);
	if (errno == -4)
		ft_putstr_fd("Memory allocation error\n", 2);
	if (errno == -5)
		ft_putstr_fd("Invalid map borders or size\n", 2);
	if (errno == -6)
		ft_putstr_fd("Invalid number of collectibles, player or exit\n", 2);
	if (errno == -7)
		ft_putstr_fd("Unrecognized character in map\n", 2);
	if (errno == -8)
		ft_putstr_fd("No valid path to collectible or exit\n", 2);
}

void	ft_freestructure(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_changedir(t_game *g, int dir)
{
	g->pl->sprites.up->content->enabled = 0;
	g->pl->sprites.down->content->enabled = 0;
	g->pl->sprites.left->content->enabled = 0;
	g->pl->sprites.right->content->enabled = 0;
	if (dir == N)
	{
		g->pl->sprites.up->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.up->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.up->content->enabled = true;
	}
	if (dir == S)
	{
		g->pl->sprites.down->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.down->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.down->content->enabled = true;
	}
	if (dir == W)
	{
		g->pl->sprites.left->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.left->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.left->content->enabled = true;
	}
	if (dir == E)
	{
		g->pl->sprites.right->content->instances[0].x = g->pl->win_pos.x;
		g->pl->sprites.right->content->instances[0].y = g->pl->win_pos.y;
		g->pl->sprites.right->content->enabled = true;
	}
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

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_game	**g;
	mlx_t	*mlx;

	g = param;
	mlx = (*g)->id;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
	if (!((*g)->pl->moving))
	{
		if (keydata.key == MLX_KEY_UP && (*g)->pl->dir != N)
			ft_changedir((*g), N);
		else if (keydata.key == MLX_KEY_DOWN && (*g)->pl->dir != S)
			ft_changedir((*g), S);
		else if (keydata.key == MLX_KEY_LEFT && (*g)->pl->dir != W)
			ft_changedir((*g), W);
		else if (keydata.key == MLX_KEY_RIGHT && (*g)->pl->dir != E)
			ft_changedir((*g), E);
		else if (ft_moveallowed((*g)))
			(*g)->pl->moving = 1;
	}
}

t_player	*ft_plrnew(t_vector pos)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos = pos;
	player->win_pos = ft_newvector(pos.x * SIZE, pos.y * SIZE);
	player->moving = 0;
	player->dir = S;
	return (player);
}

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

int	ft_draw(t_game *g)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				mlx_image_to_window(g->id, g->sprites.wall, x * SIZE, y * SIZE);
			else
				mlx_image_to_window(g->id, g->sprites.black, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'C')
				mlx_image_to_window(g->id, g->sprites.rupee, x * SIZE, y * SIZE);
			else if (g->map[y][x] == 'E')
			{
				mlx_image_to_window(g->id, g->sprites.triforce, x * SIZE, y * SIZE);
				mlx_image_to_window(g->id, g->sprites.triforceon, x * SIZE, y * SIZE);
				g->sprites.triforceon->enabled = 0;
			}
			x++;
		}
		y++;
	}
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
			{
				g->pl = ft_plrnew(ft_newvector(x, y));
				i = 0;
				 while (i++ < g->n_collect_bak)
				 	mlx_image_to_window(g->id, g->sprites.cover, g->pl->win_pos.x, g->pl->win_pos.y);
			}
			x++;
		}
		y++;
	}
	ft_render_scoreboard(g);
	return (0);
}

void	ft_update_game(void *param)
{
	t_game	**g;

	g = param;
	(*g)->n_frames++;
	if ((*g)->pl->moving && ((*g)->n_frames % 2))
	{
		ft_moving((*g));
		ft_update_moves((*g));
	}
	if ((*g)->map[(*g)->pl->pos.y][(*g)->pl->pos.x] == 'C')
	{
		(*g)->n_collect_bak--;
		(*g)->sprites.cover->instances[(*g)->n_collect_bak].x = (*g)->pl->win_pos.x;
		(*g)->sprites.cover->instances[(*g)->n_collect_bak].y = (*g)->pl->win_pos.y;
		(*g)->map[(*g)->pl->pos.y][(*g)->pl->pos.x] = '0';
	}
	if ((*g)->n_collect_bak == 0 && !((*g)->sprites.triforceon->enabled))
		(*g)->sprites.triforceon->enabled = true;
	if ((*g)->map[(*g)->pl->pos.y][(*g)->pl->pos.x] == 'E' && (*g)->sprites.triforceon->enabled)
	{
		ft_printf("YOU WON! and it only took you %d moves!\n", (*g)->n_moves);
		sleep(1);
		mlx_close_window((*g)->id);
	}
}

void	ft_animclean(t_lists *list)
{
	t_lists	*tmp;

	while(list->next)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
}

void	ft_freegame(t_game *g)
{
	ft_freestructure(g->map);
	ft_freestructure(g->map_bak);
	ft_animclean(g->pl->sprites.down);
	ft_animclean(g->pl->sprites.left);
	ft_animclean(g->pl->sprites.right);
	ft_animclean(g->pl->sprites.up);
	free(g->pl);
}

void	ft_setgame(t_game *g, char **m, t_layout *lay)
{
	g->n_frames = 1;
	g->width = lay->col * SIZE;
	g->height = lay->row * SIZE + 80;
	g->layout = lay;
	g->map = m;
	g->sprites = ft_initsprites(g);
	g->next_dir = 0;
	g->g_rate = GAME_RATE;
	g->n_moves_bak = 0;
	g->sprites.score_font = ft_load_font(g);
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
	g.n_collect_bak = lay.collect;
	ft_dupmap(map, &(g.map_bak));
	g.id = mlx_init(lay.col * SIZE, lay.row * SIZE + 80, "TLOZ - A lame 42 story", true);
	g.w_id = mlx_new_image(g.id, lay.col * SIZE, lay.row * SIZE + 80);
	ft_setgame(&g, map, &lay);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_layout	layout;
	int	ret;

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
