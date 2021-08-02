#include "linked_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = (*lst);
	*lst = new;
}

t_list	*ft_lstnextpop(t_list *lst)
{
	t_list *ret;

	if (!lst )
		return (NULL);
	ret = lst->next;
	if (!lst->next)
		return (ret);
	lst->next = ret->next;
	return (ret);
}

void	ft_lstnextpush(t_list *lst, t_list *item)
{
	if (!item || !lst)
		return ;
	item->next = lst->next;
	lst->next = item;
}

void	ft_lstnextdel(t_list *lst)
{
	if (!lst)
		return ;
    t_list *next_remove_lst = lst->next;
    lst->next = next_remove_lst->next;
	free(next_remove_lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;
	t_list	*next;

	if (!lst)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		next = curr->next;
		ft_lstdelone(curr);
		curr = next;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !*f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		cnt;

	if (!lst)
		return (0);
	cnt = 0;
	while (lst)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}