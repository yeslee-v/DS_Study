#include "sort.h"

void    printQuickArr(int size, int *arr)
{
    printf("================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void	sorting(int *arr, int left, int right, int pivot)
{
	if (left < 0 || right < 0 || left == pivot || pivot <= 0)
		return ;
	while (left < right)
	{
		while (arr[left] < arr[pivot] && left < right)
			left++;
		while (arr[right] >= arr[pivot] && left < right)
			right--;
		if (left == right)
		{
			swap(&arr[left], &arr[pivot]);
			sorting(arr, 0, right - 1, left - 1);
			sorting(arr, right + 1, pivot, pivot);
		}
		else if (arr[left] > arr[right])
			swap(&arr[left], &arr[right]);
	}
}

int *quickSort(Info origin)
{
    int *result;
    int size = origin.size;
	int	pivotIdx = size - 1;
	int	left = 0;

    result = malloc(sizeof(int) * size);
    for (int i = 0; i < origin.size; i++)
        result[i] = origin.arr[i];

    sorting(result, left, pivotIdx, pivotIdx);

    return (result);
}

// igo nan moreugetda <- yeslee