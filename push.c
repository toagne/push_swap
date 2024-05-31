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

void push(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*temp;

	if (!*a)
		return;
	if (*b == NULL)
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		temp = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = temp;
	}
}

int main()
{
	t_ps_list *a;
	t_ps_list *b;
	t_ps_list *temp;

	a = NULL;
	temp = NULL;
	b = NULL;
//	a = ft_lstnew_ps(1);
//	a->next = ft_lstnew_ps(2);
//	a->next->next = ft_lstnew_ps(3);
	b = ft_lstnew_ps(4);
//	b->next = ft_lstnew_ps(5);
//	b->next->next = ft_lstnew_ps(6);
	temp = a;
	printf("stack_a was: ");
	while (temp)
	{
		printf("%d ", temp->n_value);
		temp = temp->next;
	}
	if (b)
	{
		printf("\nstack_b was: ");
		temp = b;
		while (temp)
    	{
        	printf("%d ", temp->n_value);
        	temp = temp->next;
    	}
	}
	else
		printf("\nstack_b was empty");
	printf("\nstack_a is: ");
	push(&a, &b);
	while (a)
	{
		printf("%d ", a->n_value);
		a = a->next;
	}
	printf("\nstack_b is: ");
	while (b)
	{
		printf("%d ", b->n_value);
		b = b->next;
	}
	printf("\n");
}
