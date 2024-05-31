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
static t_ps_list	*ft_lstlast_ps(t_ps_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new_node)
{
	t_ps_list	*last_node;

	if (*lst == NULL)
	{
		*lst = new_node;
	}
	else
	{
		last_node = ft_lstlast_ps(*lst);
		last_node->next = new_node;
	}
}

void	rotate(t_ps_list **stack)
{
	t_ps_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back_ps(stack, temp);
}
/*
int main()
{
	t_ps_list *a;
	t_ps_list *temp;

	a = NULL;
	temp = NULL;
	a = ft_lstnew_ps(4);
	a->next = ft_lstnew_ps(1);
	a->next->next = ft_lstnew_ps(2);
	a->next->next->next = ft_lstnew_ps(3);
	temp = a;
	while (temp)
	{
		printf("%d ", temp->n_value);
		temp = temp->next;
	}
	printf("\n");
	rotate(&a);
	while (a)
	{
		printf("%d ", a->n_value);
		a = a->next;
	}
	printf("\n");
}
*/
