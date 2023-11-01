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
	g->sprites.score_font.zero->instances[i].enabled = true;
	g->sprites.score_font.one->instances[i].enabled = true;
	g->sprites.score_font.two->instances[i].enabled = true;
	g->sprites.score_font.three->instances[i].enabled = true;
	g->sprites.score_font.four->instances[i].enabled = true;
	g->sprites.score_font.five->instances[i].enabled = true;
	g->sprites.score_font.six->instances[i].enabled = true;
	g->sprites.score_font.seven->instances[i].enabled = true;
	g->sprites.score_font.eight->instances[i].enabled = true;
	g->sprites.score_font.nine->instances[i].enabled = true;
}

void	ft_change_score(t_game *g, int digit, int i)
{
	ft_enable(g, i);
	if (digit != 0)
		g->sprites.score_font.zero->instances[i].enabled = 0;
	if (digit != 1)
		g->sprites.score_font.one->instances[i].enabled = 0;
	if (digit != 2)
		g->sprites.score_font.two->instances[i].enabled = 0;
	if (digit != 3)
		g->sprites.score_font.three->instances[i].enabled = 0;
	if (digit != 4)
		g->sprites.score_font.four->instances[i].enabled = 0;
	if (digit != 5)
		g->sprites.score_font.five->instances[i].enabled = 0;
	if (digit != 6)
		g->sprites.score_font.six->instances[i].enabled = 0;
	if (digit != 7)
		g->sprites.score_font.seven->instances[i].enabled = 0;
	if (digit != 8)
		g->sprites.score_font.eight->instances[i].enabled = 0;
	if (digit != 9)
		g->sprites.score_font.nine->instances[i].enabled = 0;
}

void	ft_render_scoreboard(t_game *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_image_to_window(g->id, g->sprites.score_font.zero, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.one, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.two, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.three, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.four, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.five, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.six, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.seven, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.eight, (g->width/2 - 40) + i * 16, g->height -30);
		mlx_image_to_window(g->id, g->sprites.score_font.nine, (g->width/2 - 40) + i * 16, g->height -30);
		i++;
	}
	ft_disable_all(g->sprites.score_font);
}

int	ft_load_font(t_game *g)
{
	mlx_texture_t *tmp;

	tmp = mlx_load_png("sprite/others/zero.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.zero = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/one.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.one = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/two.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.two = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/three.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.three = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/four.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.four = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/five.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.five = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/six.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.six = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/seven.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.seven = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/eight.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.eight = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/nine.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.nine = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/black.png");
	if (!tmp)
		return (0);
	g->sprites.score_font.black = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	g->n_moves = 0;
	return (1);
}
