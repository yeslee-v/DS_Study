#ifndef QUEUE_H
# define QUEUE_H

# define true 1
# define false 0

# include <stdio.h>
# include <stdlib.h>

typedef struct linkedlistqueue LLQ;
typedef struct linkedlistnode LLN;

struct linkedlistqueue
{
	int curCount;
	LLN *front;
	LLN *rear;
};

struct linkedlistnode
{
	int	element;
	LLN *prev;
	LLN *next;
};

int		Dequeue(LLQ *queue);
void	Enqueue(LLQ *queue, int c);
LLQ		*initqueue(void);
LLN	 	*initnode(LLN *tmp, int c);
void 	printQueue(LLQ *queue);

#endif