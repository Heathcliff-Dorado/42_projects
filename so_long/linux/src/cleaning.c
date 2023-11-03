#include "../inc/so_long.h"

void	ft_freestructure(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_animclean(t_lists *list)
{
	t_lists	*tmp;

	while (list->next)
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
	ft_animclean(g->pl->sp.down);
	ft_animclean(g->pl->sp.left);
	ft_animclean(g->pl->sp.right);
	ft_animclean(g->pl->sp.up);
	free(g->pl);
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
