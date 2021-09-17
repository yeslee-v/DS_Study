#include "sort.h"

int *heapSort(Info origin)
{
    int *result;
    int size = origin.size;
	Heap *heap;
	
    result = calloc(sizeof(int), size);
	heap = createHeap(size);
	for (int i = 0; i < size; i++)
		insertElement(heap, origin.arr[i]);
	for (int i = 0; i < size; i++)
	{
		result[i] = deleteElement(heap);
	}
	free(heap->arr);
	free(heap);
    return (result);
}
