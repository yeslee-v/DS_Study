#include "sort.h"

LLQ	*mergeQueue(LLQ	*a, LLQ *b)
{
	LLQ	*result;

	result = initqueue();
	while (a->curCount > 0 && b->curCount > 0)
	{
		if (a->front->element > b->front->element)
			Enqueue(result, Dequeue(b));
		else if (a->front->element < b->front->element)
			Enqueue(result, Dequeue(a));
	}
	while (a->curCount)
		Enqueue(result, Dequeue(a));
	while (b->curCount)
		Enqueue(result, Dequeue(b));
	free(a);
	free(b);
	return (result);
}

int *mergeSort(Info origin)
{
 
    int size = origin.size;
	int *result = calloc(sizeof(int), size);
   	int	LLQcount = size;

	LLQ	**llqArr = calloc(sizeof(LLQ *), 8);
	for (int i = 0; i < 8; i++)
		llqArr[i] = initqueue();
	for (int i = 0; i < size; i++)
		Enqueue(llqArr[i], origin.arr[i]);
	while (LLQcount > 1)
	{
		int j = 0;
		for (int i = 0; i < LLQcount - 1; i+= 2)
		{
			llqArr[j] = mergeQueue(llqArr[i], llqArr[i + 1]);
			j++;
		}
		LLQcount = j;
	}
	for (int i = 0; i < 8; i++)
		result[i] = Dequeue(llqArr[0]);
	free(llqArr[0]);
	free(llqArr);
	return (result);
}
