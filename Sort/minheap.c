#include "minheap.h"

Heap	*createHeap(int size)
{
	Heap	*heap;

	heap = malloc(sizeof(Heap));
	if (!heap)
		return (0);
	heap->size = 0;
	heap->arr = calloc(size + 3, sizeof(int));
	return (heap);
}

void	print_heap(Heap *heap)
{
	int	*arr = heap->arr;

	for (int i = 1; i <= heap->size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// 노드 추가될 때 일어나는 부모노드 자식노드 교환
void	p_recursive(Heap *heap, int index)
{
	int	*arr = heap->arr;
	int tmp;

	if (arr[index/2] > arr[index] && index != 1)
	{
		tmp = arr[index/2];
		arr[index/2] = arr[index];
		arr[index] = tmp;
		p_recursive(heap, index/2);
	}
}

//heap 에 int x 노드 추가
void	insertElement(Heap *heap, int key)
{
	int	*arr = heap->arr;

	arr[++(heap->size)] = key;
	p_recursive(heap, heap->size);
}

// 노드 삭제될 때 일어나는 부모노드 자식노드 교환
void	exchange(Heap *heap, int parent, int child)
{
	int	*arr = heap->arr;
	int tmp;

	if (parent > heap->size || child > heap->size)
		return ;
	if (arr[parent] > arr[child])
	{
		tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
	}
}

// 노드 삭제할 때 노드 체크(왼, 오)하고 필요하면 부모노드 자식노드 교환(exchange)
void	m_recursive(Heap *heap, int index)
{
	int	*arr = heap->arr;
	int leftChild = arr[index * 2];
	int rightChild = arr[index * 2 + 1];
	int nextIndex;
	
	if (heap->size == 2)
    	exchange(heap, 1, 2);
	if (!(index <= heap->size))
		return ;
	if (leftChild <= rightChild)
		nextIndex = index * 2;
	else
		nextIndex = index * 2 + 1;
	if (arr[index] > arr[nextIndex])
	{
		exchange(heap, index, nextIndex);
		m_recursive(heap, nextIndex);
	}
}

// 루트 노드 삭제하고 m_recursive 돌려서 힙 맞추기, 삭제된 루트 노드 값 반환
int	deleteElement(Heap *heap)
{
	int	*arr = heap->arr;
	int	root;

	if (heap->size == 0)
		return (0);
	root = arr[1];
	arr[1] = arr[heap->size];
	arr[heap->size] = 0;
	(heap->size)--;
	m_recursive(heap, 1);
	return (root);
}

