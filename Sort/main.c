#include "sort.h"


void    printArray(Info origin, int *arr)
{
    int size = origin.size;

    printf("================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    Info    origin;   
    int     *orig;
    int     *select;
    int     *bubble;
    int     *quick;
    int     *insert;
    int     *shell;
    int     *merge;
    int     *radix;
    int     *heap;

    orig = malloc(sizeof(int) * 8);
    orig[0] = 80;
    orig[1] = 50;
    orig[2] = 70;
    orig[3] = 10;
    orig[4] = 60;
    orig[5] = 20;
    orig[6] = 40;
    orig[7] = 30;
    origin.size = 8;
    origin.arr = orig;
    
    printf("\norigin info\n");
    printArray(origin, orig);

    select = selectionSort(origin);
    printf("\nselection sort\n");
    printArray(origin, select);

    bubble = bubbleSort(origin);
    printf("\nbubble sort\n");
    printArray(origin, bubble);
 
  
    quick = quickSort(origin);
    printf("\nquick sort\n");
    printArray(origin, quick);

    insert = insertSort(origin);
    printf("\ninsert sort\n");
    printArray(origin, insert);
    
    shell = shellSort(origin);
    printf("\nshell sort\n");
    printArray(origin, shell);

    merge = mergeSort(origin);
    printf("\nmerge sort\n");
    printArray(origin, merge);

    heap = heapSort(origin);
    printf("\nheap sort\n");
    printArray(origin, heap);

    orig[0] = 42;
    orig[1] = 60;
    orig[2] = 75;
    orig[3] = 81;
    orig[4] = 10;
    orig[5] = 23;
    orig[6] = 12;
    orig[7] = 18;

    radix = radixSort(origin);
    printf("\nradix sort\n");
    printArray(origin, radix);
}