#include "sort.h"

int *selectionSort(Info origin)
{
    int *result;
    int size = origin.size;
    int min;
    int minIdx;

    result = malloc(sizeof(int) * size);
    for (int i = 0; i < origin.size; i++)
        result[i] = origin.arr[i];
        
    for (int i = 0; i < size - 1; i++)
    {
        min = result[i];
        minIdx = i; 
        for (int j = i + 1; j < size; j++)
        {
            if (min > result[j])
            {
                min = result[j];
                minIdx = j;
            }
        }
		// printf("minIdx : %d, min : %d\n", minIdx, min);
        result[minIdx] = result[i];
        result[i] = min;
        // printArray(origin, result);
    }
    return (result);
}
