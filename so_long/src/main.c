#include "../inc/so_long.h"
#include "../../MLX42/include/MLX42/MLX42_Int.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//static mlx_image_t* image;

void	ft_lstadd_back_s(t_lists **lst, t_lists *new)
{
	t_lists	*tmp;

	tmp = (*lst);
	if (!(*lst))
		(*lst) = new;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
		(*lst) = tmp;
	}
}

t_lists	*ft_lstnew_s(mlx_image_t *content)
{
	t_lists	*lst;

	lst = malloc(sizeof(t_lists));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = (mlx_image_t *)content;
	return (lst);
}

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

/*

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	int	j;

	j = 0;
	if (param)
		j = 0;
	else if (j == 1)
		j = 1;
	for (int32_t i = 0; i < (int32_t)image->width; ++i)
	{
		for (int32_t y = 0; y < (int32_t)image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	t_game	*g;
	mlx_t	*mlx;

	g = param;
	mlx = g->id;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		//mlx_close_window(mlx);
		g->sprites.link->instances[0].y -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		//mlx_close_window(mlx);
		g->sprites.link->instances[0].y += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		//mlx_close_window(mlx);
		g->sprites.link->instances[0].x -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		//mlx_close_window(mlx);
		g->sprites.link->instances[0].x += 1;
}
*/
/*
void	ft_start_moving(t_game *g, int direction)
{
	if (direction == N)
	{
		g->pl->win_pos.y = g->pl->win_pos.y - 3;
		mlx_image_to_window(g->id, g->sprites.black, (g->pl->pos.x) * SIZE, (g->pl->pos.y) * SIZE);
		mlx_image_to_window(g->id, g->sprites.black, (g->pl->pos.x) * SIZE, (g->pl->pos.y - 1) * SIZE);
		mlx_image_to_window(g->id, g->pl->sprites.up->content, g->pl->win_pos.x, g->pl->win_pos.y);
		g->pl->sprites.up = g->pl->sprites.up->next;
		g->pl->dir = N;
	}
	if (g->pl->dir == S)
	{
		g->sprites.link->instances[0].y += 16;
		g->pl->dir = S;
	}
	if (g->pl->dir == W)
	{
		g->sprites.link->instances[0].x -= 16;
		g->pl->dir = W;
	}
	if (g->pl->dir == E)
	{
		g->sprites.link->instances[0].x += 16;
		g->pl->dir = E;
	}
	g->pl->moving = 1;
}*/

void	ft_moving(t_game *g)
{
	if (g->pl->dir == N)
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
	if (g->pl->dir == S)
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
	if (g->pl->dir == W)
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
	if (g->pl->dir == E)
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

/*
int	key_hook(int key, t_game *g)
{
	if ((key == KEY_Q || key == KEY_ESC) && !g->pac_dying)
	{
		printf("\n%sYou quit the game early!%s\n\n", RED, DEFAULT);
		end_game(g);
	}
	if (key == KEY_R && !g->pac_dying)
		ft_reset(g);
	if ((key == KEY_UP || key == KEY_W) && g->next_dir != N && \
		!g->pac_dying)
		ft_newdirection(g, N);
	if ((key == KEY_DOWN || key == KEY_S) && g->next_dir != S && \
		!g->pac_dying)
		ft_newdirection(g, S);
	if ((key == KEY_RIGHT || key == KEY_D) && g->next_dir != E && \
		!g->pac_dying)
		ft_newdirection(g, E);
	if ((key == KEY_LEFT || key == KEY_A) && g->next_dir != W && \
		!g->pac_dying)
		ft_newdirection(g, W);
	return (0);
}

int	end_game(t_game *g)
{
	if (g->map)
		ft_free_matrix(&g->map);
	if (g->map_bak)
		ft_free_matrix(&g->map_bak);
	free_sprites(g);
	ft_free_playerlist(g);
	printf("%sGame Finished!\n%sTotal Moves: %d\n\n%s", GREEN, \
		BLUE, g->n_moves, DEFAULT);
	mlx_clear_window(g->id, g->w_id);
	mlx_destroy_window(g->id, g->w_id);
	mlx_destroy_display(g->id);
	free(g->id);
	exit(0);
	return (0);
}

void	ft_check_game(t_game *g)
{
	//if (g->lay_bak.collect / 4 + 1 >= g->layout->collect && g->layout->enemy)
	//{
	//	if (!g->panic_mode)
	//		g->g_rate -= g->g_rate / 3;
	//	g->panic_mode = 1;
	//}
	if (!(g->n_frames % (g->g_rate + (g->g_rate / 13))))
		ft_redraw_gh(g);
	if (!(g->n_frames % g->g_rate) && !g->pac_dying)
		ft_redraw_pac(g);
	if (g->pl->dir != ST && !g->pac_dying)
		ft_update_ghosts(g);
	if (g->next_dir)
		ft_next_dir(g);
	if (g->pac_dying && !(g->n_frames % (10 * g->g_rate)))
		ft_anim_pacdeath(g);
	if (!g->layout->collect && !g->layout->player && !g->pac_dying)
	{
		printf("%sCONGRATULATIONS, YOU WIN!%s\n\n", GREEN, DEFAULT);
		end_game(g);
	}
}

int	ft_update(t_game *g)
{
	int		x;
	int		y;

	y = 0;
	g->n_frames++;
	ft_check_game(g);
	if (g->redraw)
	{
		//ft_put_ghosts(g);
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.logo, \
		(g->width - 131) / 2, g->height - 42);
		ft_update_score(g);
		while (g->map[y])
		{
			x = 0;
			while (g->map[y][x])
			{
				ft_put_map(g, x, y);
				x++;
			}
			y++;
		}
		g->redraw = 0;
	}
	return (0);
}*/
/*
t_list	*ft_load_pacdeath(t_game *g)
{
	t_list	*pacdeath;
	char	*s;
	char	c;
	int		size;

	pacdeath = NULL;
	s = ft_substr("sprites/Pac-Man/Dying/pacman_dying1.xpm", 0, 39);
	c = '0';
	while (c++ < '8' + 1)
	{
		ft_memset(&s[34], c, 1);
		ft_lstadd_back(&pacdeath, \
			ft_lstnew(mlx_xpm_file_to_image(g->id, s, &size, &size)));
	}
	free(s);
	ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(g->id, \
		"sprites/Pac-Man/Dying/pacman_dying10.xpm", &size, &size)));
	while (c-- > '7')
	{
		ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(g->id, \
			"sprites/Other/Walls/black.xpm", &size, &size)));
		ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(g->id, \
			"sprites/Pac-Man/Dying/pacman_woosh.xpm", &size, &size)));
	}
	return (pacdeath);
}

t_font	ft_load_score_font(t_game *g)
{
	int	size;

	g->sprites.score_font.zero = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/0.xpm", &size, &size);
	g->sprites.score_font.one = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/1.xpm", &size, &size);
	g->sprites.score_font.two = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/2.xpm", &size, &size);
	g->sprites.score_font.three = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/3.xpm", &size, &size);
	g->sprites.score_font.four = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/4.xpm", &size, &size);
	g->sprites.score_font.five = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/5.xpm", &size, &size);
	g->sprites.score_font.six = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/6.xpm", &size, &size);
	g->sprites.score_font.seven = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/7.xpm", &size, &size);
	g->sprites.score_font.eight = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/8.xpm", &size, &size);
	g->sprites.score_font.nine = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/9.xpm", &size, &size);
	g->sprites.score_font.black = mlx_xpm_file_to_image(g->id, \
		"sprites/Other/Fonts/black.xpm", &size, &size);
	return (g->sprites.score_font);
}
*/


t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
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
	player->next = NULL;
	return (player);
}

void	ft_plradd_back(t_player **lst, t_player *newnode)
{
	t_player	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}
/*
void	ft_playerlist(char **map, t_game *g)
{
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				ft_plradd_back(&g->pl, ft_plrnew(ft_newvector(x, y)));
			//if (map[y][x] == 'G')
			//	ft_plradd_back(&g->gh, ft_plrnew(ft_newvector(x, y)));
			x++;
		}
		y++;
	}
}*/

t_lists	*ft_load_north(t_game *g, char *path, int i)
{
	t_lists	*anim;
	char	*s;

	anim = NULL;
	s = ft_strjoin(path, "link-up.png");
	ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
	s = ft_strjoin(path, "link-u0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
		i++;
	}
	free(s);
	return (anim);
}

t_lists	*ft_load_south(t_game *g, char *path, int i)
{
	t_lists	*anim;
	char	*s;

	anim = NULL;
	s = ft_strjoin(path, "link-d0.png");
	ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
	s = ft_strjoin(path, "link-md0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
		i++;
	}
	free(s);
	return (anim);
}

t_lists	*ft_load_east(t_game *g, char *path, int i)
{
	t_lists	*anim;
	char	*s;

	anim = NULL;
	s = ft_strjoin(path, "link-r0.png");
	ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
	s = ft_strjoin(path, "link-mr0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
		i++;
	}
	free(s);
	return (anim);
}

t_lists	*ft_load_west(t_game *g, char *path, int i)
{
	t_lists	*anim;
	char	*s;

	anim = NULL;
	s = ft_strjoin(path, "link-l0.png");
	ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
	s = ft_strjoin(path, "link-ml0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
		i++;
	}
	free(s);
	return (anim);
}

/*t_list	*ft_load_panic(t_game *g, int i)
{
	t_list	*anim;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->id, \
		"sprites/Ghosts/Panic/ghost_panic1a.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->id, \
		"sprites/Ghosts/Panic/ghost_panic1b.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->id, \
		"sprites/Ghosts/Panic/ghost_panic2a.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->id, \
		"sprites/Ghosts/Panic/ghost_panic2b.xpm", &i, &i)));
	return (anim);
}*/

/*t_list	*ft_chooseghcolor(t_game *g, int i, int dir)
{
	t_list	*anim;
	char	*s;
	int		j;

	j = 0;
	anim = NULL;
	s = NULL;
	s = ft_substr("sprites/Ghosts/R/", 0, 17);
	if (i > 0)
		ft_memset(&s[15], COLORS[i % 7], 1);
	if (dir == N)
		anim = ft_load_north(g, s, j);
	if (dir == S)
		anim = ft_load_south(g, s, j);
	if (dir == E)
		anim = ft_load_east(g, s, j);
	if (dir == W)
		anim = ft_load_west(g, s, j);
	free(s);
	return (anim);
}*/

/*void	ft_load_ghosts(t_game *g)
{
	t_player	*ghost;
	int			i;

	i = 0;
	ghost = g->gh;
	while (ghost)
	{
		ghost->sprites.up = ft_chooseghcolor(g, i, N);
		ghost->sprites.up_bak = ghost->sprites.up;
		ghost->sprites.down = ft_chooseghcolor(g, i, S);
		ghost->sprites.down_bak = ghost->sprites.down;
		ghost->sprites.right = ft_chooseghcolor(g, i, E);
		ghost->sprites.right_bak = ghost->sprites.right;
		ghost->sprites.left = ft_chooseghcolor(g, i, W);
		ghost->sprites.left_bak = ghost->sprites.left;
		//ghost->sprites.panic = ft_load_panic(g, i);
		//ghost->sprites.panic_bak = ghost->sprites.panic;
		ghost = ghost->next;
		i++;
	}
}*/

void ft_update_moves(t_game *g)
{
	int	digit;
	int	leftover;
	int	i;

	digit = g->n_moves % 10;
	leftover = g->n_moves / 10;
}

void	ft_render_link(t_lists *sprite, int x, int y, mlx_t *id)
{
	t_lists	*tmp;

	tmp = sprite;
	while(sprite->next)
	{
		mlx_image_to_window(id, sprite->content, x * SIZE, y * SIZE);
		sprite->content->enabled = 0;
		sprite = sprite->next;
	}
	mlx_image_to_window(id, sprite->content, x * SIZE, y * SIZE);
	sprite->content->enabled = 0;
	sprite = tmp;
}

void	ft_load_links(t_game *g)
{
	t_player	*link;
	int			i;

	i = 0;
	link = g->pl;
	link->sprites.up = ft_load_north(g, "sprite/link/", i);
	link->sprites.up_bak = link->sprites.up;
	ft_render_link(link->sprites.up, link->pos.x, link->pos.y, g->id);
	link->sprites.down = ft_load_south(g, "sprite/link/", i);
	link->sprites.down_bak = link->sprites.down;
	ft_render_link(link->sprites.down, link->pos.x, link->pos.y, g->id);
	link->sprites.left = ft_load_west(g, "sprite/link/", i);
	link->sprites.left_bak = link->sprites.left;
	ft_render_link(link->sprites.left, link->pos.x, link->pos.y, g->id);
	link->sprites.right = ft_load_east(g, "sprite/link/", i);
	link->sprites.right_bak = link->sprites.right;
	ft_render_link(link->sprites.right, link->pos.x, link->pos.y, g->id);
	link->sprites.down->content->enabled = true;
}

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

void	ft_render_scoreboard(t_game *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_image_to_window(g->id, g->sprites.score_font.black, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.zero, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.one, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.two, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.three, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.four, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.five, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.six, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.seven, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.eight, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		mlx_image_to_window(g->id, g->sprites.score_font.nine, (g->layout->col/2 * SIZE - 40) + i * 16, g->layout->row * SIZE + 60);
		i++;
	}
	ft_disable_all(g->sprites.score_font);
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

t_sprite	ft_initsprites(t_game *g)
{
	g->sprites.wall = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/wall.png"));
	g->sprites.rupee = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/rupee.png"));
	g->sprites.triforce = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/triforce-off.png"));
	g->sprites.triforceon = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/triforce-on.png"));
	//g->sprites.logo = mlx_texture_to_image(g->id, mlx_load_png("sprites/others/logo.png"));
	g->sprites.cover = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/path.png"));
	g->sprites.black = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/path.png"));
	//g->sprites.pac_dying = ft_load_pacdeath(g);
	//g->sprites.score_font = ft_load_score_font(g);
	//g->sprites.pac_dying_bak = g->sprites.pac_dying;
	return (g->sprites);
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
	// ft_printf("y: %d ", (*g)->pl->pos.y);
	// ft_printf("x: %d ", (*g)->pl->pos.x);
	// ft_printf("map: %c\n", (*g)->map[(*g)->pl->pos.y][(*g)->pl->pos.x]);
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
		ft_printf("YOU WON!\n");
		mlx_close_window((*g)->id);
	}
}

t_font	ft_load_font(t_game *g)
{
	t_font	score;

	score.zero = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/0.png"));
	score.one = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/1.png"));
	score.two = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/2.png"));
	score.three = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/3.png"));
	score.four = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/4.png"));
	score.five = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/5.png"));
	score.six = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/6.png"));
	score.seven = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/7.png"));
	score.eight = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/8.png"));
	score.nine = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/9.png"));
	score.black = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/black.png"));
	g->n_moves = 0;
	return (score);
}

void	ft_setgame(t_game *g, char **m, t_layout *lay)
{
	g->n_frames = 1;
	g->width = lay->col * SIZE;
	g->height = lay->row * SIZE + 80;
	g->layout = lay;
	g->map = m;
	g->sprites = ft_initsprites(g);
	//g->gh = NULL;
	g->next_dir = 0;
	//ft_load_ghosts(g);
	g->g_rate = GAME_RATE;
	g->redraw = 1;
	g->sprites.score_font = ft_load_font(g);
	ft_draw(g);
	ft_load_links(g);
	mlx_key_hook(g->id, my_keyhook, &g);
	mlx_loop_hook(g->id, ft_update_game, &g);
	mlx_loop(g->id);
}

//First thing is to initialize the game and load all the sprites for the game. I am not sure what the bak means, I am assuming backup or background

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
	//mlx_t	*mlx;
	t_layout	layout;
	int	ret;

	/*mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		//ft_error();
	image = mlx_new_image(mlx, 128, 128);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		//ft_error();
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);*/
	//First step, create the map layout and confirm everything is correct
	map = NULL;
	ft_newlayout(&layout);
	ret = parse_map(argc, argv, &layout, &map);
	if (ret < 0)
	{
		ft_error_handling(ret);
		return (0);
	}
	//Next step, create the game using the MLX42 library
	ft_initgame(map, layout);
	while(map[0])
	{
		printf("%s\n", map[0]);
		map++;
	}
	return (0);
}
