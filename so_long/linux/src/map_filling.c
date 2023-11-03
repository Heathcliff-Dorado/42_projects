#include "../inc/so_long.h"

void	ft_fillbackground(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				mlx_image_to_window(g->id, g->sp.wall, x * SIZE, y * SIZE);
			else
				mlx_image_to_window(g->id, g->sp.black,
					x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	ft_fillothers(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'C')
				mlx_image_to_window(g->id, g->sp.rupee,
					x * SIZE, y * SIZE);
			else if (g->map[y][x] == 'E')
			{
				mlx_image_to_window(g->id, g->sp.triforce,
					x * SIZE, y * SIZE);
				mlx_image_to_window(g->id, g->sp.triforceon,
					x * SIZE, y * SIZE);
				g->sp.triforceon->enabled = 0;
			}
			x++;
		}
		y++;
	}
}

void	ft_fillplayer(t_game *g)
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
			if (g->map[y][x] == 'P')
			{
				g->pl = ft_plrnew(ft_newvector(x, y));
				i = 0;
				while (i++ < g->col_bak)
					mlx_image_to_window(g->id, g->sp.cover,
						g->pl->win_pos.x, g->pl->win_pos.y);
			}
			x++;
		}
		y++;
	}
}

int	ft_draw(t_game *g)
{
	ft_fillbackground(g);
	ft_fillothers(g);
	ft_fillplayer(g);
	ft_render_scoreboard(g);
	return (0);
}
