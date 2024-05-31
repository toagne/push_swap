#include "push_swap.h"
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct s_ps_list
{
	int 				n_value;
	struct s_ps_list	*next;
}	t_ps_list;
*/
int	already_sorted(t_ps_list *a)
{
	while (a->next)
	{
		if (a->n_value > a->next->n_value)
			return(0);
		a = a->next;
	}
	return (1);
}
/*
t_ps_list	*ft_lstnew_ps(int n)
{
	t_ps_list	*new_node;

	new_node = (t_ps_list *)malloc(sizeof(t_ps_list));
	if (!new_node)
		return (NULL);
	new_node->n_value = n;
	new_node->next = NULL;
	return (new_node);
}

int main()
{
	t_ps_list	*stack_a;

	stack_a = ft_lstnew_ps(-9);
	stack_a->next = ft_lstnew_ps(3);
	stack_a->next->next = ft_lstnew_ps(5);
	if (already_sorted(stack_a))
	{
		free(stack_a);
		printf("sorted");
	}
	else
		printf("to be sorted");
}
*/
