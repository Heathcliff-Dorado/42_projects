#include "../inc/so_long.h"

t_sprite	ft_initsprites(t_game *g)
{
	g->sprites.wall = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/wall.png"));
	g->sprites.rupee = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/rupee.png"));
	g->sprites.triforce = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/triforce-off.png"));
	g->sprites.triforceon = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/triforce-on.png"));
	g->sprites.cover = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/path.png"));
	g->sprites.black = mlx_texture_to_image(g->id, mlx_load_png("sprite/others/path.png"));
	return (g->sprites);
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
