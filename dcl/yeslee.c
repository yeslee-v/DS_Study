typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_lst
{
	t_node			*head;
	t_node			*tail;
	int				cnt;
}					t_lst;

typedef struct		s_val
{
	int				piv1;
	int				piv2;
}					t_val;

typedef	struct		s_stack
{
	t_lst			*a;
	t_lst			*b;
	t_val			val;
	int				is_push_swap;
}					t_stack;

void	ft_del(t_lst *lst)
{
	t_node *tmp;

	if (!lst)
		return ;
	tmp = NULL;
	if (lst->cnt != 1)
	{
		tmp = lst->head;
		lst->head = tmp->next;
		lst->head->prev = tmp->prev;
		lst->tail->next = lst->head;
		free(tmp);
	}
	else if (lst->cnt == 1)
	{
		tmp = lst->head;
		free(tmp);
		lst->head = NULL;
		lst->tail = NULL;
	}
}

int		ft_count_element(t_lst *stack)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = stack->head;
	while (node)
	{
		cnt++;
		node = node->next;
		if (node == stack->head)
			break ;
	}
	return (cnt);
}

int			ft_lstcnt(t_lst *lst)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = lst->head;
	while (node)
	{
		cnt++;
		node = node->next;
		if (node == lst->head)
			break ;
	}
	return (cnt);
}

int			ft_find_num(t_stack *stack, int num)
{
	int		i;
	int		node_cnt;
	t_node	*tmp;

	i = 0;
	tmp = stack->a->head;
	while (++i <= ft_lstcnt(stack->a))
	{
		if (tmp->data == num)
		{
			node_cnt = i;
			return (node_cnt);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		ft_node_init(t_lst *lst, int value)
{
	t_node	*node;

	node = NULL;
	node = ft_get_node(node);
	node->data = value;
	if (!(lst->head) && !(lst->tail))
	{
		node->next = node;
		node->prev = node;
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		node->prev = lst->tail;
		lst->tail = node;
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
	}
}

t_node		*ft_get_node(t_node *node) // nodenew
{
	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_lst		*ft_init_list(t_lst *lst)
{
	if (!(lst = malloc(sizeof(t_lst))))
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->cnt = 0;
	return (lst);
}

void		ft_init_val(t_val *val)
{
	val->piv1 = 0;
	val->piv2 = 0;
}

