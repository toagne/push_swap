#include "push_swap.h"

static void swap(t_ps_list **a)
{
	t_ps_list	*temp;

	if (!a || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	sa(t_ps_list **stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1); 
}

void	sb(t_ps_list **stack)
{
	swap(stack);
	ft_putendl_fd("sb", 1);
}

void    ss(t_ps_list **a, t_ps_list **b)
{
    swap(a);
	swap(b);
    ft_putendl_fd("ss", 1);
}
