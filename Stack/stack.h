#ifndef STACK_H
# define STACK_H

#include <stdio.h>
#include <stdlib.h>

//node 용
typedef struct node {
	int   x;
  int   y;
	struct node  *next;
} Node;

//링크드리스트 전체
typedef struct linkedlist{
	struct node *head;
    int curX;
    int curY;
		int size;
} Linkedlist;

#endif