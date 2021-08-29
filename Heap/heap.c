#include "heap.h"

void    Swap(int *p, int *c)
{
    int tmp;

    tmp = *p;
    *p = *c;
    *c = tmp;
}

void    initializeHeap(Heap *heap)
{
    for (int i = 0; i < MAX_SIZE; i++)
        heap->arr[i] = 0;
    heap->size = 0;
}

void    Insert(Heap *heap, int key)
{
    int index;

    heap->size += 1;
    index = heap->size;
    while (index != 1 && key < heap->arr[index / 2])
    {
        heap->arr[index] = heap->arr[index / 2];
        index /= 2;
    }
    heap->arr[index] = key;
}

int    Delete(Heap *heap)
{
    int root;
    int parent;
    int child;

    parent = 1;
    if (heap->size == 0)
        return (-1);
    root = heap->arr[1];
    heap->arr[1] = heap->arr[heap->size--];
    while (1)
    {
        child = parent * 2;
        if ((child + 1 <= heap->size) && (heap->arr[child] > heap->arr[child + 1]))
            child++;
        if ((child > heap->size) || (heap->arr[child] > heap->arr[parent]))
            break;
        Swap(&heap->arr[parent], &heap->arr[child]);
        parent = child;
    }
    heap->arr[heap->size + 1] = 0;
    return(root);
}

int main()
{
    Heap heap;

    initializeHeap(&heap);
    Insert(&heap, 33);
    Insert(&heap, 22);
    Insert(&heap, 44);
    Insert(&heap, 11);
    Insert(&heap, 55);
    for (int i = 0; i < 10; i++)
        printf("%d ", heap.arr[i]);
    printf("\n");

    printf("%d\n", Delete(&heap));

    for (int i = 0; i < 10; i++)
        printf("%d ", heap.arr[i]);
    printf("\n");
    return 0;
}