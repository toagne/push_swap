#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_ps_list
{
    int                 n_value;
	int					cost;
    struct s_ps_list    *target;
    struct s_ps_list    *next;
}   t_ps_list;

int ft_lstsize_ps(t_ps_list *lst)
{
    int n;

    n = 0;
    while (lst)
    {   
        lst = lst->next;
        n++;
    }   
    return (n);
}

t_ps_list   *ft_lstnew_ps(int n)
{
    t_ps_list   *new_node;

    new_node = (t_ps_list *)malloc(sizeof(t_ps_list));
    if (!new_node)
        return (NULL);
    new_node->n_value = n;
    new_node->next = NULL;
    return (new_node);
}

t_ps_list   *find_smallest(t_ps_list *stack)
{
    t_ps_list *smallest;
    int min;

    min = INT_MAX;
    while (stack)
    {   
        if (min > stack->n_value)
        {   
            min = stack->n_value;
            smallest = stack;
        }   
        stack = stack->next;
    }   
    return (smallest);
}

void    fsb(t_ps_list *a, t_ps_list *b) 
{
    int max;
    t_ps_list *temp;
    t_ps_list *target;

    while (b) 
    {   
        max = INT_MAX;
        temp = a;
        while (temp)
        {   
            if (temp->n_value > b->n_value && max > temp->n_value)
            {   
                max = temp->n_value;
                target = temp;
            }   
            temp = temp->next;
        }   
        if (max == INT_MAX)
            b->target = find_smallest(a);
        else
            b->target = target;
        b = b->next;
    }   
}

void	find_cost(t_ps_list *a, t_ps_list *b)
{
	int args;
	int	c;

	c = 0;
	args = ft_lstsize_ps(a);
	while (a)
	{
		if (c <= args / 2)
			a->cost = c;
		else
			a->cost = args - c;
		c++;
		a = a->next;
	}
	c = 0;
	args = ft_lstsize_ps(b);
	while (b)
	{
		if (c <= args / 2)
			b->cost = b->target->cost + c;
		else
			b->cost = args - c + b->target->cost;
		c++;
		b = b->next;
	}
}

t_ps_list	*find_cheapest(t_ps_list *stack)
{
    t_ps_list *cheapest;
    int min;

    min = INT_MAX;
    while (stack)
    {   
        if (min > stack->cost)
        {   
            min = stack->cost;
            cheapest = stack;
        }   
        stack = stack->next;
    }   
    return (cheapest);
}

void	move_cheapest(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*cheapest;
	int			c;
	int			args;

	c = 0;
	args = ft_lstsize_ps(a);
	while (b != cheapest || a != b->target)
	{
		if (c <= args / 2)
			rr(a, b);
		else
			rrr(a, b);
		c++;
	}

}

int main(void)
{
    t_ps_list *a; 
    t_ps_list *b; 

    a = ft_lstnew_ps(1);
    a->next = ft_lstnew_ps(2);
    a->next->next = ft_lstnew_ps(4);
    b = ft_lstnew_ps(3);
    b->next = ft_lstnew_ps(5);
	b->next->next = ft_lstnew_ps(684);
	b->next->next->next = ft_lstnew_ps(-9);
	fsb(a, b);
	find_cost(a, b);
	move_cheapest(*a, *b);
	while (b)
	{
		printf("the target of %d is %d and the cost is %d\n", b->n_value, b->target->n_value, b->cost);
		b = b->next;
	}
}
