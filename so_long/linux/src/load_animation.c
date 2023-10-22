#include "../inc/so_long.h"

t_lists	*ft_load_north(t_game *g, char *path, int i)
{
	t_lists	*anim;
	char	*s;

	anim = NULL;
	s = ft_strjoin(path, "link-up.png");
	ft_lstadd_back_s(&anim, ft_lstnew_s(mlx_texture_to_image(g->id, mlx_load_png(s))));
	free(s);
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
	free(s);
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
	free(s);
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
	free(s);
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
