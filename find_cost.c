#include "push_swap.h"

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
