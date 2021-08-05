#include <stdio.h>
#include <stdlib.h>

typedef struct	ListNode
{
	int				coef;
	int				degree;
	struct ListNode	*pLink;
}				polyNode;

typedef struct	ListHead
{
	struct ListNode	*pLink;
}				polyHead;

typedef struct	LinkedList
{
	unsigned int	currentElementCount;
	polyHead		*head;
}				polyList;

polyList	*initPolyList(void)
{
	polyList	*poly;

	poly = (polyList *)calloc(1, sizeof(polyList));
	if (!poly)
		return (NULL);
	poly->head = headNew();
	if (!poly->head)
		return (NULL);
	return (poly);
}

polyNode	*polyNew(int coef, int degree)
{
	polyNode *newNode;

	newNode = (polyNode *)calloc(1, sizeof(polyNode));
	if (!newNode)
		return (NULL);
	newNode->coef = coef;
	newNode->degree = degree;
	return (newNode);
}

polyHead	*headNew(void)
{
	polyHead *head;

	head = (polyHead *)calloc(1, sizeof(polyHead));
	if (!head)
		return (NULL);
	return (head);
}

polyNode	*polyNodeLast(polyHead *head)
{
	polyNode	*node;

	if (!head || !head->pLink)
		return (NULL);
	node = head->pLink;
	while (node->pLink)
	{	
		node = node->pLink;
	}
	return (node);
}

void	polyAddack(polyList *lst, polyNode *new)
{
	polyNode *lastNode;

	if (!lst || !lst->head || !new)
		return ;
	lastNode = polyNodeLast(lst->head);
	if (!lastNode)
		lst->head->pLink = new;
	else
		lastNode->pLink = new;
	lst->currentElementCount++;
}

void	polyPrint(polyList *lst)
{
	polyNode *node;

	if (!lst || !lst->head)
		return ;
	printf("currentElementCount : %u\n", lst->currentElementCount);
	node = lst->head->pLink;
	while (node)
	{
		printf("coef [%d] ", node->coef);
		printf("degree [%d]\n", node->degree);
		node = node->pLink;
	}
}
/* 
** 1. A와 B의 degree가 내림차순으로 정렬 되었을 경우에만 고려하였음
** 2. 동적메모리의 반납은 프로세스의 종료와 함께 이뤄지도록 따로 free하지 않았음
** 3. 시간복잡도 O(n)
 */
polyList	*additionOfPolys(polyList *A, polyList *B)
{
	polyNode *aNode;
	polyNode *bNode;
	polyList *New;

	if (!A || !B)
		return (NULL);
	New = initPolyList();
	if (!New)
		return (NULL);
	aNode = A->head->pLink;
	bNode = B->head->pLink;
	while (aNode && bNode)
	{
		if (aNode->degree > bNode->degree)
		{
			polyAddack(New, polyNew(aNode->coef, aNode->degree));
			aNode = aNode->pLink;
		}
		else if (aNode->degree < bNode->degree)
		{
			polyAddack(New, polyNew(bNode->coef, bNode->degree));
			bNode = bNode->pLink;
		}
		else
		{
			polyAddack(New, polyNew(aNode->coef + bNode->coef, aNode->degree));
			aNode = aNode->pLink;
			bNode = bNode->pLink;
		}
	}
	while (aNode)
	{
		polyAddack(New, polyNew(aNode->coef, aNode->degree));
		aNode = aNode->pLink;
	}
	while (bNode)
	{
		polyAddack(New, polyNew(bNode->coef, bNode->degree));
		bNode = bNode->pLink;
	}
	return (New);
}

int	main(void)
{
	polyList	*A;
	polyList	*B;

	A = initPolyList();
	B = initPolyList();

	A->head = headNew();
	B->head = headNew();

	polyAddack(A, polyNew(6, 6));
	polyAddack(A, polyNew(4, 5));
	polyAddack(A, polyNew(2, 2));

	polyAddack(B, polyNew(1, 5));
	polyAddack(B, polyNew(2, 4));
	polyAddack(B, polyNew(3, 2));
	polyAddack(B, polyNew(4, 0));

	polyPrint(A);
	polyPrint(B);

	polyPrint(additionOfPolys(A, B));
}
