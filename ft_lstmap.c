#include "libft.h"

// void *my_malloc(size_t n)
// {
//     static int g = 3;

//     if (g <= 0)
//         return (NULL);
//     g--;
//     return (malloc(n));
// }

// #define malloc my_malloc

t_list	*ft_lstnews(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*prev;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	prev = ft_lstnews(f(lst->content));
	res = prev;
	while (lst->next != NULL)
	{
		tmp = ft_lstnews(f(lst->next->content));
		if (tmp == NULL)
		{
			ft_lstclear(&res, del);
			return (res);
		}
		prev->next = tmp;
		prev = prev->next;
		lst = lst->next;
	}
	return (res);
}
