/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:44:13 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 16:34:49 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simple_sort(t_ps_list **a)
{
	t_ps_list	*biggest;

	biggest = find_biggest(*a);
	if (*a == biggest)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->n_value > (*a)->next->n_value)
		sa(a);
}

static void	move_a_to_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	args_a;
	int	args_b;

	args_a = ft_lstsize_ps(*stack_a);
	args_b = 0;
	while (args_b++ < 2 && args_a-- > 3 && !already_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (args_a-- > 3 && !already_sorted(*stack_a))
	{
		populate_list(*stack_a, *stack_b, 'a');
		move_cheapest_a_to_b(stack_a, stack_b);
	}
}

static void	move_b_to_a(t_ps_list **stack_a, t_ps_list **stack_b)
{
	while (*stack_b)
	{
		populate_list(*stack_a, *stack_b, 'b');
		move_cheapest_b_to_a(stack_a, stack_b);
	}
}

static void	real_sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int			args_a;
	t_ps_list	*smallest;

	move_a_to_b(stack_a, stack_b);
	simple_sort(stack_a);
	move_b_to_a(stack_a, stack_b);
	args_a = ft_lstsize_ps(*stack_a);
	set_index(*stack_a, NULL);
	smallest = find_smallest(*stack_a);
	if (smallest->index <= args_a / 2)
	{
		while (*stack_a != smallest)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != smallest)
			rra(stack_a);
	}
}

void	push_swap(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (ft_lstsize_ps(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize_ps(*stack_a) == 3)
		simple_sort(stack_a);
	else
		real_sort(stack_a, stack_b);
}
