#include "push_swap.h"
/*
#include <stdlib.h>
#include <stdio.h>

typedef struct s_ps_list
{
	int 				n_value;
	struct s_ps_list	*next;
}	t_ps_list;

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
*/
void swap(t_ps_list **a)
{
	t_ps_list	*temp;

	if (!a || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}
/*
int main()
{
	t_ps_list *a;
	t_ps_list *temp;

	a = NULL;
	temp = NULL;
	a = ft_lstnew_ps(6);
	a->next = ft_lstnew_ps(5);
	a->next->next = ft_lstnew_ps(7);
	a->next->next->next = ft_lstnew_ps(8);
	temp = a;
	while (temp)
	{
		printf("%d ", temp->n_value);
		temp = temp->next;
	}
	printf("\n");
	swap(&a);
	while (a)
	{
		printf("%d ", a->n_value);
		a = a->next;
	}
	printf("\n");
}
*/
