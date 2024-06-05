#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_ps_list
{
    int                 n_value;
    struct s_ps_list    *target;
    struct s_ps_list    *next;
}   t_ps_list;

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

t_ps_list	*find_smallest(t_ps_list *stack)
{
	t_ps_list *smallest;
	int	min;

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

void	find_smallest_bigger(t_ps_list *a, t_ps_list *b)
{
	int	max;
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

int main(void)
{
	t_ps_list *a;
	t_ps_list *b;

	a = ft_lstnew_ps(1);
	a->next = ft_lstnew_ps(2);
	a->next->next = ft_lstnew_ps(4);
	b = ft_lstnew_ps(3);
	b->next = ft_lstnew_ps(5);
	find_smallest_bigger(a, b);
	printf("target of %d is %d\n", b->n_value, b->target->n_value);
    printf("target of %d is %d\n", b->next->n_value, b->next->target->n_value);
}
