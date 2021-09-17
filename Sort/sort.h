#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "minheap.h"

typedef struct  info
{
    int     size;
    int     *arr;
}               Info;

void    swap(int *a, int *b);
void    printArray(Info origin, int *arr);
int *selectionSort(Info origin);
int *bubbleSort(Info origin);
int *quickSort(Info origin);
int *insertSort(Info origin);
int *shellSort(Info origin);
int *mergeSort(Info origin);
int *radixSort(Info origin);
int *heapSort(Info origin);


#endif