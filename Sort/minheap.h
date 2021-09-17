#ifndef _MIN_HEAP_
# define _MIN_HEAP_

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int *arr;
	int	size;
}             Heap;

Heap	*createHeap(int size);

void	print_heap(Heap *heap);

// 노드 추가될 때 일어나는 부모노드 자식노드 교환
void	p_recursive(Heap *heap, int index);

//heap 에 int x 노드 추가
void	insertElement(Heap *heap, int key);

// 노드 삭제될 때 일어나는 부모노드 자식노드 교환
void	exchange(Heap *heap, int parent, int child);
// 노드 삭제할 때 노드 체크(왼, 오)하고 필요하면 부모노드 자식노드 교환(exchange)
void	m_recursive(Heap *heap, int index);

// 루트 노드 삭제하고 m_recursive 돌려서 힙 맞추기, 삭제된 루트 노드 값 반환
int	deleteElement(Heap *heap);

#endif
