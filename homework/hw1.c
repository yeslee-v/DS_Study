#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

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

void	ft_lstreverse(t_list **lst)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	if (!lst || !(*lst)->next)
		return ;
	next = NULL;
	prev = NULL;
	curr = (*lst)->next;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr; 
		curr = next;
	}
	(*lst)->next = prev;
}

int	main(void)
{
	t_list	*list;
	t_list	*head;


	head = ft_lstnew("(head)");
	list = head;
	ft_lstadd_back(&list, ft_lstnew("1"));
	ft_lstadd_back(&list, ft_lstnew("2"));
	ft_lstadd_back(&list, ft_lstnew("3"));
	ft_lstadd_back(&list, ft_lstnew("4"));
	ft_lstadd_back(&list, ft_lstnew("5"));
	printf("forward\n");
	while(list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	printf("===============================\n");
	list = head;
	ft_lstreverse(&list);
	printf("reverse\n");
	while(list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

