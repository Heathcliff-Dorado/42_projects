#include "../inc/so_long.h"

void	ft_lstadd_back_s(t_lists **lst, t_lists *new)
{
	t_lists	*tmp;

	tmp = (*lst);
	if (!(*lst))
		(*lst) = new;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
		(*lst) = tmp;
	}
}

t_lists	*ft_lstnew_s(mlx_image_t *content)
{
	t_lists	*lst;

	lst = malloc(sizeof(t_lists));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = (mlx_image_t *)content;
	return (lst);
}

t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
}

//Use this one??
void	ft_plradd_back(t_player **lst, t_player *newnode)
{
	t_player	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}
