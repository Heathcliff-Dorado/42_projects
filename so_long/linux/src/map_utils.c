#include "../inc/so_long.h"

void	ft_freemap(char ***map)
{
	int	nrow;

	nrow = 0;
	while ((*map)[nrow])
		nrow++;
	while (nrow > 0)
	{
		free((*map)[nrow - 1]);
		nrow--;
	}
	free(*map);
}

int	ft_dupmap(char **src, char ***dst)
{
	int	nrow;
	int	i;

	nrow = 0;
	while (src[nrow])
		nrow++;
	*dst = malloc(sizeof(char *) * (nrow + 1));
	if (!(*dst))
		return (-4);
	i = 0;
	while (i < nrow)
	{
		(*dst)[i] = ft_strdup(src[i]);
		if (!(*dst)[i])
			return (-4);
		i++;
	}
	(*dst)[i] = NULL;
	return (1);
}

void	ft_newlayout(t_layout *layout)
{
	layout->row = 0;
	layout->col = 0;
	layout->exit = 0;
	layout->player = 0;
	layout->collect = 0;
}

int	ft_map_length(char ***map)
{
	int	len;

	len = 0;
	if (*map)
	{
		while ((*map)[len])
			len++;
	}
	return (len);
}

