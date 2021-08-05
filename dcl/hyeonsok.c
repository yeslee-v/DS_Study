#include <stdlib.h>

이중 원형 연결 리스트 머리에 원소 삽입하기
이중 원형 연결 리스트 꼬리에 원소 삽입하기
이중 원형 연결 리스트의 머리에서 노드 삭제하기
이중 원형 연결 리스트의 꼬리에서 노드 삭제하기
이중 원형 연결 리스의 원소 검색하기
이중 원형 연결 리스트 삭제하기
이중 원형 연결 리스트 출력하기


typedef struct s_node {
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}				t_node;

typedef struct s_dclst {
	struct s_node	*head;
	int				count;
}				t_dcLst;



t_node	*ft_nodepop(t_node *node, t_dcLst *lst)
{
	if (node == NULL)
		return (NULL);
	if (node->prev != NULL && node->next != NULL)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	lst->count--;
	return (node);
}

void	ft_addnode_next(t_node *node, t_node *add, t_dcLst *lst)
{
	if (node == NULL || add == NULL)
		return ;
	add->next = node->next;
	add->prev = node;
	node->next->prev = add;
	node->next = add;
	lst->count++;
}

void	ft_addnode_prev(t_node *node, t_node *add, t_dcLst *lst)
{
	if (node == NULL || add == NULL)
		return ;
	add->next = node;
	add->prev = node->prev;
	node->prev->next = add;
	node->prev = add;
	lst->count++;
}



void	ft_dclstclear(t_dcLst *lst)
{
	t_node	*curr;
	t_node	*node;

	if (!lst)
		return ;
	curr = lst->head->next;
	while (curr != lst->head)
	{
		node = curr;
		curr = curr->next;
		free(node);
	}
	free(lst->head);
}

t_node	*ft_dclstpeek(t_dcLst *lst, int data)
{
	t_node	*curr;

	if (!lst || !lst->count)
		return (NULL);
	curr = lst->head->next;
	while (curr != lst->head)
	{
		if (curr->data == data)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
