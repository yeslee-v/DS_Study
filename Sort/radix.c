#include "sort.h"

int *radixDequere(LLQ **llqArr, int *result)
{
    int j = 0;
    for (int i = 0; i < 10; i++)
		while (llqArr[i]->curCount)
        {
			result[j] = Dequeue(llqArr[i]);
			j++;
        }
    return (result);
}

int *radixSort(Info origin)
{
    int *result;
    int size = origin.size;

    result = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        result[i] = origin.arr[i];

	LLQ	**llqArr = calloc(sizeof(LLQ *), 10);
	for (int i = 0; i < 10; i++)
		llqArr[i] = initqueue();
    for (int j = 0; j < size; j++)
    {
        int n = result[j] % 10;
        Enqueue(llqArr[n], result[j]);
    }
    result = radixDequere(llqArr, result);
	for (int j = 0; j < size; j++)
    {
        int n = (result[j] / 10);
        Enqueue(llqArr[n], result[j]);
    }
    result = radixDequere(llqArr, result);
	free(llqArr);
    return (result);
}