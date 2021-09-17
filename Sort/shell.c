#include "sort.h"

int *shellSort(Info origin)
{
    int *result;
    int size = origin.size;
	int	distance = size / 2; // 4
	Info temp;

    result = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        result[i] = origin.arr[i];
	while (distance > 1)
	{
		for (int i = 0; distance + i < size; i++) // 4 + 3 / 2 + 5
		{
			if (result[i] > result[distance + i])
				swap(&result[i], &result[distance + i]);
		}
        distance = distance / 2; // 4, 2 ,1
	}
	temp.arr = result;
	temp.size = size;
	result = insertSort(temp); // 1 + 6
	free(temp.arr);
    return (result);
}
