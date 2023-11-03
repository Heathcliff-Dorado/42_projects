/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:39:46 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/03 09:26:24 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
