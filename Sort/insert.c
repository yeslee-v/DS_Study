#include "sort.h"

int *insertSort(Info origin)
{
    int *result;
    int size = origin.size;
	int tmp;

    result = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        result[i] = origin.arr[i];
	for	(int i = 1; i < size; i++) // 비교할 애 1 2
	{
		for (int j = 0; j < i; j++) // 비교당할 애 0 01
		{
			if (result[j] > result[i])
			{
				tmp = result[i];
				for (int k = i - 1; k >= j; k--)
					result[k + 1] = result[k];
				result[j] = tmp;
				break ;
			}
		}
	}

    return (result);
}

// 쭈압쭈압 <- ji-kim <- -_-? <- 이거쓴사람 바보