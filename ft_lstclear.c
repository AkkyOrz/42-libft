#include "libft.h"
#include <stdio.h>
static void ft_lstclear_util(t_list *lst, void (*del)(void *));

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	ft_lstclear_util(*lst, del);
	*lst = NULL;
}

static void ft_lstclear_util(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return;
	ft_lstclear_util(lst->next, del);
	ft_lstdelone(lst, del);
}
