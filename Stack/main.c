#include "stack.h"

//초기화
void lstInit(Linkedlist *lst)
{
  if (!(lst->head = malloc((sizeof(Node)))))
    return ;
  lst->curX = 0;
  lst->curY = 0;
  lst->head->next = NULL;
  lst->size = 0;
}

//새 노드 생성
Node	*lstNew(int x, int y)
{
	Node	*list;

	if (!(list = malloc(sizeof(Node))))
    return (0);
	list->x = x;
  list->y = y;
	list->next = NULL;
	return (list);
}

//헤드 바로 뒤에 노드 추가
void	addFront(Linkedlist *lst, Node *newNode)
{
  if (lst && newNode)
  {
	  newNode->next = lst->head->next;
    lst->head->next = newNode;
    (lst->size)++;
  }
}

// 마지막 노드 반환
Node	*getLast(Node *head)
{
	Node	*lastlst;

	if (head == NULL)
		return (NULL);
	lastlst = head;
	while (lastlst->next)
		lastlst = lastlst->next;
	return (lastlst);
}

int	count(Linkedlist lst)
{
  return (lst.size);
}

// 연결리스트 맨 뒤에 노드 추가하기
void		addBack(Linkedlist *lst, Node *newNode)
{
	Node *last;

	if (lst == NULL || newNode == NULL)
		return ;
	last = getLast(lst->head);
	last->next = newNode;
  (lst->size)++;
}

// 연결리스트 n번째 인덱스에 노드 추가하기
void		addNIndex(Linkedlist *lst, Node *newNode, int n)
{
  Node *pre = lst->head;
	Node *curr = lst->head->next;
  if (n < 0 || lst->size < n)
    return ;
	if (lst == NULL || newNode == NULL)
		return ;
  for (int i = 0; i < n; i++)
  {
    pre = curr;
    curr = curr->next;
  }
  //newNode->next = curr->next;
	//curr = newNode;
  //pre->next = curr;
  pre->next = newNode;
  newNode->next = curr;
  (lst->size)++;
}

//전체 조회
void showAll(Node *head)
{
  if (head == NULL)
    return ;
  Node *curr = head->next;
  while (curr)
  {
    if (curr == head->next)
      printf("(%d, %d) ", curr->x, curr->y);
    else
      printf("<- (%d, %d) ", curr->x, curr->y);
    curr = curr->next;
  }
}

//노드삭제
void  delOne(Linkedlist *lst, Node *node)
{
  free(node);
  (lst->size)--;
}

//첫번째 노드삭제
void  delFront(Linkedlist *lst)
{
  Node *curr;

  if (lst == NULL)
    return ;
  curr = lst->head->next;
  if (curr)
  {
    lst->head->next = curr->next;
    delOne(lst, curr);
  }
}

//마지막 노드삭제
void  delLast(Linkedlist *lst)
{
  Node *prev;
  Node *curr;

  prev = lst->head;
  curr = lst->head->next;
  while (curr && curr->next)
  {
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  delOne(lst, curr);
}

void  delAll(Linkedlist *lst)
{
  Node *tmp;
  Node *curr;

  curr = lst->head;
  while (curr)
  {
    tmp = curr->next;
    delOne(lst, curr);
    curr = tmp;
  }
  lst->head = NULL;
}

int myMaze[8][8] = {
  {0, 0, 1, 1, 1, 1, 1, 1}, 
  {1, 0, 0, 0, 0, 0, 0, 1}, 
  {1, 1, 1, 0, 1, 1, 1, 1}, 
  {1, 1, 1, 0, 1, 1, 1, 1}, 
  {1, 0, 0, 0, 0, 0, 0, 1}, 
  {1, 0, 1, 1, 1, 1, 1, 1}, 
  {1, 0, 0, 0, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 1, 0} // end
};

int DirOff[4][2] ={
  {0, -1}, // 위쪽으로 이동.
  {1, 0}, // 오른쪽으로 이동.
  {0, 1}, // 아래쪽으로 이동.
  {-1, 0} // 왼쪽으로 이동.
};

// 좌표에 해당하는 맵 값 반환
int checkMaze(int x, int y)
{
  return myMaze[y][x];
}

// 맵 값에 따라 갈 수 있는지 유무
int checkCanGo(Linkedlist *lst)
{
  for (int i = 0; i < 4; i++)
  {
    int tmpX = lst->curX + DirOff[i][0];
    int tmpY = lst->curY + DirOff[i][1];
    if ((tmpX >= 0 && tmpX <= 7) && (tmpY >= 0 && tmpY <= 7))
    {
      int value = checkMaze(tmpX, tmpY);
      myMaze[lst->curY][lst->curX] = 2;
      if (value == 0)
      {
        lst->curX += DirOff[i][0];
        lst->curY += DirOff[i][1];
        return (1);
      }
    }
  }
  return (0); // 1 or 2
}

void showMap()
{
  int i;
  int j;

  i = 0;
  printf("\n");
  while (i < 8)
  { 
    j = 0;
    while (j < 8)
    {
      printf(" %d ", myMaze[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}

void showPath(Linkedlist *lst)
{
  printf("\n");
  printf(" 출구는 (%d, %d) 입니다.\n", lst->curX, lst->curY);
  showMap();
  printf("\n");
  showAll(lst->head);
}

int main(void) {
  Linkedlist lst;

  lstInit(&lst);
  while (!((lst.curX == 7) && (lst.curY == 7)))
  {
    if (checkCanGo(&lst))
      addFront(&lst, lstNew(lst.curX, lst.curY));
    else
    {
      delFront(&lst);
      lst.curX = lst.head->next->x;
      lst.curY = lst.head->next->y;
    }
  }
  showPath(&lst);

  return (0);
}