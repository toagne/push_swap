#include "push_swap.h"

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
