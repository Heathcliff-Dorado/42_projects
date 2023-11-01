/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:39:46 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/01 22:35:12 by hdorado-         ###   ########.fr       */
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

void	ft_load_all_sc(t_game *g, int i)
{
	mlx_image_to_window(g->id, g->sp.fnt.zero,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.one,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.two,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.three,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.four,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.five,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.six,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.seven,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.eight,
		(g->w / 2 -40) + i * 16, g->h -30);
	mlx_image_to_window(g->id, g->sp.fnt.nine,
		(g->w / 2 -40) + i * 16, g->h -30);
}

void	ft_render_scoreboard(t_game *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		ft_load_all_sc(g, i);
		i++;
	}
	ft_disable_all(g->sp.fnt);
}

int	ft_load3(t_game *g)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("sprite/others/seven.png");
	if (!tmp)
		return (0);
	g->sp.fnt.seven = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/eight.png");
	if (!tmp)
		return (0);
	g->sp.fnt.eight = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/nine.png");
	if (!tmp)
		return (0);
	g->sp.fnt.nine = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/black.png");
	if (!tmp)
		return (0);
	g->sp.fnt.black = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	g->n_moves = 0;
	return (1);
}

int	ft_load2(t_game *g)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("sprite/others/three.png");
	if (!tmp)
		return (0);
	g->sp.fnt.three = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/four.png");
	if (!tmp)
		return (0);
	g->sp.fnt.four = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/five.png");
	if (!tmp)
		return (0);
	g->sp.fnt.five = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/six.png");
	if (!tmp)
		return (0);
	g->sp.fnt.six = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	return (1);
}

int	ft_load_font(t_game *g)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("sprite/others/zero.png");
	if (!tmp)
		return (0);
	g->sp.fnt.zero = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/one.png");
	if (!tmp)
		return (0);
	g->sp.fnt.one = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/two.png");
	if (!tmp)
		return (0);
	g->sp.fnt.two = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	if (!(ft_load2(g)) || !(ft_load3(g)))
		return (0);
	return (1);
}
