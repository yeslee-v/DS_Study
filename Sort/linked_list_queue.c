#include "queue.h"

LLQ	*initqueue(void)
{
	LLQ *queue;
	queue = malloc(sizeof(LLQ));
	if (!queue)
		return (0);
	queue->curCount = 0;
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

LLN	 *initnode(LLN *tmp, int c)
{
	tmp = malloc(sizeof(LLN));
	if (!tmp)
		return NULL;
	tmp->element = c;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	Enqueue(LLQ *queue, int c)
{
	LLN *tmp;

	tmp = initnode(tmp, c);
	if (!queue->curCount)
	{
		queue->front = tmp;
		queue->rear = tmp;
	}
	else
	{
		tmp->prev = queue->rear;
		queue->rear->next = tmp;
		tmp->next = NULL;
		queue->rear = tmp;
	}
	queue->curCount++;
}

int Dequeue(LLQ *queue)
{
	LLN *tmp;

	int i;
	
	if (!queue->curCount)
	{
		// printf("Queue is Empty\n");
		return 0;
	}
	i = queue->front->element;
	if (queue->curCount == 1)
	{
		free(queue->front);
		queue->front = NULL;
		queue->rear = NULL;
		// printf("Now queue is Empty\n");
		queue->curCount--;
		return i;
	}
	else
	{
		tmp = queue->front;
		queue->front->next->prev = NULL;
		queue->front = queue->front->next;
		free(tmp);
	}
	queue->curCount--;
	return i;
}

int Peek(LLQ *queue)
{
	if (!queue->curCount)
	{
		// printf("Queue is Empty\n");
		return 0;
	}
	return queue->front->element;
}

int	Queuesize(LLQ *queue)
{
	return queue->curCount;
}

void printQueue(LLQ *queue)
{
	LLN *tmp;
	tmp = queue->front;
	int i = 0;
	while (tmp)
	{
		printf("node[%d]: %d\n", i, tmp->element);
		i++;
		tmp = tmp->next;
	}
}

// int main()
// {
// 	LLQ *queue;

// 	queue = initqueue();
// 	Enqueue(queue, 1);
// 	printQueue(queue);
// 	printf("delete:%d\n", Dequeue(queue));
// 	Enqueue(queue, 3);
// 	Enqueue(queue, 4);
// 	Enqueue(queue, 5);
// 	printf("peek:%d\n", Peek(queue));
// 	printQueue(queue);
// 	printf("curcount:%d\n", Queuesize(queue));
// 	return (0);
// }