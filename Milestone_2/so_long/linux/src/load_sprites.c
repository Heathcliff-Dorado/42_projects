/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:39:59 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/01 22:21:41 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_initsprites2(t_game *g)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("sprite/others/triforce-off.png");
	if (!tmp)
		return (0);
	g->sp.triforce = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/triforce-on.png");
	if (!tmp)
		return (0);
	g->sp.triforceon = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/path.png");
	if (!tmp)
		return (0);
	g->sp.cover = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/path.png");
	if (!tmp)
		return (0);
	g->sp.black = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	return (1);
}

int	ft_initsprites(t_game *g)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("sprite/others/wall.png");
	if (!tmp)
		return (0);
	g->sp.wall = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/rupee.png");
	if (!tmp)
		return (0);
	g->sp.rupee = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	if (!ft_initsprites2(g))
		return (0);
	return (1);
}

int	ft_load_links(t_game *g)
{
	int	ret;

	ret = 0;
	g->pl->sp.up = NULL;
	g->pl->sp.down = NULL;
	g->pl->sp.left = NULL;
	g->pl->sp.right = NULL;
	ret += ft_load_north(g, "sprite/link/", 0);
	g->pl->sp.up_bak = g->pl->sp.up;
	ft_render_link(g->pl->sp.up, g->pl->pos.x, g->pl->pos.y, g->id);
	ret += ft_load_south(g, "sprite/link/", 0);
	g->pl->sp.down_bak = g->pl->sp.down;
	ft_render_link(g->pl->sp.down, g->pl->pos.x, g->pl->pos.y, g->id);
	ret += ft_load_west(g, "sprite/link/", 0);
	g->pl->sp.left_bak = g->pl->sp.left;
	ft_render_link(g->pl->sp.left, g->pl->pos.x, g->pl->pos.y, g->id);
	ret += ft_load_east(g, "sprite/link/", 0);
	g->pl->sp.right_bak = g->pl->sp.right;
	if (ret != 4)
		return (0);
	ft_render_link(g->pl->sp.right, g->pl->pos.x, g->pl->pos.y, g->id);
	g->pl->sp.down->content->enabled = true;
	return (1);
}

void	ft_render_link(t_lists *sprite, int x, int y, mlx_t *id)
{
	t_lists	*tmp;

	tmp = sprite;
	while (sprite->next)
	{
		mlx_image_to_window(id, sprite->content, x * SIZE, y * SIZE);
		sprite->content->enabled = 0;
		sprite = sprite->next;
	}
	mlx_image_to_window(id, sprite->content, x * SIZE, y * SIZE);
	sprite->content->enabled = 0;
	sprite = tmp;
}
