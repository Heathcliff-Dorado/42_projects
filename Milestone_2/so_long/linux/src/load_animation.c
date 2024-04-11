/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:40:03 by hdorado-          #+#    #+#             */
/*   Updated: 2023/11/03 20:00:35 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_load_north(t_game *g, char *path, int i)
{
	char			*s;
	mlx_texture_t	*tmp;

	s = ft_strjoin(path, "link-up.png");
	tmp = mlx_load_png(s);
	if (!tmp)
		return (0);
	ft_lstadd_back_s(&(g->pl->sp.up),
		ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
	free(s);
	mlx_delete_texture(tmp);
	s = ft_strjoin(path, "link-u0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		tmp = mlx_load_png(s);
		if (!tmp)
			return (0);
		ft_lstadd_back_s(&(g->pl->sp.up),
			ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
		i++;
		mlx_delete_texture(tmp);
	}
	free(s);
	return (1);
}

int	ft_load_south(t_game *g, char *path, int i)
{
	char			*s;
	mlx_texture_t	*tmp;

	s = ft_strjoin(path, "link-d0.png");
	tmp = mlx_load_png(s);
	if (!tmp)
		return (0);
	ft_lstadd_back_s(&(g->pl->sp.down),
		ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
	free(s);
	mlx_delete_texture(tmp);
	s = ft_strjoin(path, "link-md0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		tmp = mlx_load_png(s);
		if (!tmp)
			return (0);
		ft_lstadd_back_s(&(g->pl->sp.down),
			ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
		i++;
		mlx_delete_texture(tmp);
	}
	free(s);
	return (1);
}

int	ft_load_east(t_game *g, char *path, int i)
{
	char			*s;
	mlx_texture_t	*tmp;

	s = ft_strjoin(path, "link-r0.png");
	tmp = mlx_load_png(s);
	if (!tmp)
		return (0);
	ft_lstadd_back_s(&(g->pl->sp.right),
		ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
	free(s);
	mlx_delete_texture(tmp);
	s = ft_strjoin(path, "link-mr0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		tmp = mlx_load_png(s);
		if (!tmp)
			return (0);
		ft_lstadd_back_s(&(g->pl->sp.right),
			ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
		i++;
		mlx_delete_texture(tmp);
	}
	free(s);
	return (1);
}

int	ft_load_west(t_game *g, char *path, int i)
{
	char			*s;
	mlx_texture_t	*tmp;

	s = ft_strjoin(path, "link-l0.png");
	tmp = mlx_load_png(s);
	if (!tmp)
		return (0);
	ft_lstadd_back_s(&(g->pl->sp.left),
		ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
	free(s);
	mlx_delete_texture(tmp);
	s = ft_strjoin(path, "link-ml0.png");
	while (i < 10)
	{
		ft_memset(&s[ft_strlen(s) - 5], i + 48, 1);
		tmp = mlx_load_png(s);
		if (!tmp)
			return (0);
		ft_lstadd_back_s(&(g->pl->sp.left),
			ft_lstnew_s(mlx_texture_to_image(g->id, tmp)));
		i++;
		mlx_delete_texture(tmp);
	}
	free(s);
	return (1);
}
