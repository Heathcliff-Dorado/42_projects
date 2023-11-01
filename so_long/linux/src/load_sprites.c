#include "../inc/so_long.h"

int	ft_initsprites(t_game *g)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("sprite/others/wall.png");
	if (!tmp)
		return (0);
	g->sprites.wall = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/rupee.png");
	if (!tmp)
		return (0);
	g->sprites.rupee = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/triforce-off.png");
	if (!tmp)
		return (0);
	g->sprites.triforce = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/triforce-on.png");
	if (!tmp)
		return (0);
	g->sprites.triforceon = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/path.png");
	if (!tmp)
		return (0);
	g->sprites.cover = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("sprite/others/path.png");
	if (!tmp)
		return (0);
	g->sprites.black = mlx_texture_to_image(g->id, tmp);
	mlx_delete_texture(tmp);
	return (1);
}

int	ft_load_links(t_game *g)
{
	int	ret;

	ret = 0;
	ret += ft_load_north(g, "sprite/link/", 0);
	g->pl->sprites.up_bak = g->pl->sprites.up;
	ft_render_link(g->pl->sprites.up, g->pl->pos.x, g->pl->pos.y, g->id);
	ret += ft_load_south(g, "sprite/link/", 0);
	g->pl->sprites.down_bak = g->pl->sprites.down;
	ft_render_link(g->pl->sprites.down, g->pl->pos.x, g->pl->pos.y, g->id);
	ret += ft_load_west(g, "sprite/link/", 0);
	g->pl->sprites.left_bak = g->pl->sprites.left;
	ft_render_link(g->pl->sprites.left, g->pl->pos.x, g->pl->pos.y, g->id);
	ret += ft_load_east(g, "sprite/link/", 0);
	g->pl->sprites.right_bak = g->pl->sprites.right;
	if (ret != 4)
		return (0);
	ft_render_link(g->pl->sprites.right, g->pl->pos.x, g->pl->pos.y, g->id);
	g->pl->sprites.down->content->enabled = true;
	return (1);
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
