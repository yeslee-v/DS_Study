#include "sort.h"

void    swap(int *a, int *b)
{
    int tmp = 0;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int *bubbleSort(Info origin)
{
    int tmp = 0;
    int *result;
    int size = origin.size;
    
    result = malloc(sizeof(int) * size);
    for (int i = 0; i < origin.size; i++)
        result[i] = origin.arr[i];
        
    for (int i = size - 1; i >= 0; i--) // 전체 횟수
    {
        for (int j = 0; j < i; j++) // 실질적 비교
        {
            if (result[j] > result[j + 1])
                swap(&result[j], &result[j+ 1]);
        }
    }
    // printArray(origin, result);

    return (result);
}
