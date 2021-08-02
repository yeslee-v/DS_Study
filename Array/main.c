#include "array.h"

/* 
배열

i번째 값 읽기 0
i번째 삽입하기 [1, 2, 3, 5] -> [1,2,3,4,5] 
i번째 저장된 값(contents) 대체하기.  [1, 2, 3, 5] -> [1, 4, 3, 5] 0
	i번째 삭제하기 [1, 2, 3, 5] -> [1, 2, 5, 0] -> [1, 2, 5 0]
	node	node	node	node	node
	cont	cont	cont	cont	cont
	NULL	1		NULL	NULL	NULL
 */

t_node	*init_node_array(int size)
{
	t_node	*arr;

	arr = calloc(size, sizeof(t_node *));
	if (!arr)
		exit(1);
	return (arr);
}

void	ft_arrpush_content(t_node *arr, int i, void *content)
{
	t_node	*tmp;
	int		idx;

	idx = SIZE - 1;
	// tmp = arr;
	// arr = realloc(arr, (SIZE + 1) * sizeof(t_node));
	// free(tmp);
	// tmp = NULL;
	while (idx > i)
	{
		arr[idx].content = arr[idx - 1].content;
		idx--;
	}
	arr[i].content = content;
}

void	ft_arrinsert_content(t_node *arr, int i, void *content) 
{
	arr[i].content = content;
}

void	ft_print_lst(t_node *arr)
{
	int i;

	i = -1;
	while(++i < SIZE)
		printf("%s\n", arr[i].content);
}

void	*ft_arrpopcontent(t_node *arr, int i)
{
	void	*ret;
	int		idx;

	ret = arr[i].content;
	idx = i;
	while(idx <= SIZE - 2) 
	{
		arr[idx].content = arr[idx + 1].content;
		idx++;
	}
	arr[SIZE - 1].content = NULL;
	return (ret);
}

int	main(void)
{
	int 	new;
	t_node  *arr;

	arr = init_node_array(SIZE); // init array
	int i = -1;
	while(++i < SIZE)
		ft_arrinsert_content(arr, i, "a"); // insert initial contents ['a', 'a', 'a', 'a', 'a']
	scanf("%d", &new);
	if ((new < 0) || (SIZE <= new))
		return (1);
    ft_arrinsert_content(arr, new, "b"); // ['a', 'a', 'a', 'b', 'a']
	// ft_print_lst(arr);
}