#include "push_swap.h"

static void	push(t_ps_list **dest, t_ps_list **src)
{
	t_ps_list	*temp;

	if (!*src)
		return;
	if (*dest == NULL)
	{
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = NULL;
	}
	else
	{
		temp = *dest;
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = temp;
	}
}

void	pa(t_ps_list **a, t_ps_list **b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_ps_list **b, t_ps_list **a)
{
    push(b, a); 
    ft_putendl_fd("pb", 1); 
}
