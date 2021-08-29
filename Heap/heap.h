#ifndef HEAP_H
# define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct heap
{
    int arr[MAX_SIZE];
    int size;
}   Heap;

#endif