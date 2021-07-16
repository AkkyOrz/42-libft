#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*prev;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	prev = ft_lstnew(f(lst->content));
	res = prev;
	while (lst->next != NULL)
	{
		tmp = ft_lstnew(f(lst->next->content));
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
