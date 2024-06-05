#include "push_swap.h"

void	real_sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	args_a;

	args_a = ft_lstsize_ps(*stack_a);
	while (args_a != 3)
	{
		pb(stack_a, stack_b);
		args_a--;
	}
	simple_sort(a);

}
