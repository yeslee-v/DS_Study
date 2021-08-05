#include <stdlib.h>
#include <stdio.h>

// 구조체
typedef struct s_node {
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}				t_node;

typedef struct s_dcLst {
	struct s_node	*head;
	struct s_node	*tail;
	int				count;
}				t_dcLst;

//노드 생성
t_node	*nodeNew(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// 리스트 초기화
t_dcLst	*dcLstInit(void)
{
	t_dcLst	*lst;

	lst = (t_dcLst *)malloc(sizeof(t_dcLst));
	if (!lst)
		return (NULL);
	lst->head = ft_nodenew(0);
	lst->tail = ft_nodenew(0);
	lst->head->next = lst->tail;
	lst->head->prev = lst->tail;
	lst->tail->next = lst->head;
	lst->tail->prev = lst->head;
	lst->count = 0;
	return (lst);
}

// 이중 원형 연결 리스트 머리에 원소 삽입하기
int		insertAtStart(t_dcLst *lst, int value)
{
	t_node	*node;

	node = nodeNew(value);
	if (!node)
		return (0);
	node->next = lst->head->next;
	node->prev = lst->head;
	lst->head->next = node;
	lst->count++;
	return (1);
}

// 이중 원형 연결 리스트 꼬리에 원소 삽입하기
int		insertAtEnd(t_dcLst *lst, int value)
{
	t_node	*node;

	node = nodeNew(value);
	if (!node)
		return (0);
	lst->tail->next = node;
	lst->tail = node;
	node->prev = lst->tail;
	lst->count++;
	return (1);
}

// 이중 원형 연결 리스트의 머리에서 노드 삭제하기
void	delFromHead(t_dcLst *lst)
{
	t_node	*temp;

	if (!lst)
	{
		printf("Empty List\n");
		return ;
	}
	temp = lst->head->next;
	if (temp != lst->tail)
	{
		lst->head->next = temp->next;
		temp->next->prev = lst->head;
		free(temp);	
	}
	lst->count--;
	return ;
}

// 이중 원형 연결 리스트의 꼬리에서 노드 삭제하기
int		delFromTail(t_dcLst *lst)
{
	t_node	*temp;

	if (!lst)
	{
		printf("Empty List\n");
		return ;
	}
	temp = lst->tail->prev;
	if (temp != lst->head)
	{
		lst->tail->prev = temp->prev;
		temp->prev->next = lst->tail;
		free(temp);	
	}
	lst->count--;
	return ;
}

// 이중 원형 연결 리스트의 원소 검색하기
int	searchNodeVal(t_dcLst *lst, int value)
{
	t_node	*curr;

	if (!lst || !lst->count)
		return (0);
	curr = lst->head->next;
	while (curr != lst->tail)
	{
		if (curr->data == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

// 이중 원형 연결 리스트 삭제하기
int	deleteList(t_dcLst *lst)
{
	t_node	*curr;
	t_node	*temp;

	if (!lst)
		return (0);
	curr = lst->head->next;
	while (curr != lst->tail)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	free(lst->head);
	free(lst->tail);
	free(lst);
	return (1);
}

// 이중 원형 연결 리스트 출력하기
void	printLst(t_dcLst *lst)
{
    t_node *node;

    node = lst->head->next;
    while (node != lst->tail)
    {
        printf("%s\n", node->data);
        node = node->next;
    }
}