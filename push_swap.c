/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:44:13 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/12 16:11:47 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*find_biggest(t_ps_list *stack)
{
	t_ps_list	*biggest;
	int			max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->n_value > max)
		{
			max = stack->n_value;
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}

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

static void	find_closest_smaller(t_ps_list *a, t_ps_list *b)
{
	long		min;
	t_ps_list	*temp;
	t_ps_list	*target;

	while (a)
	{
		min = LONG_MIN;
		temp = b;
		while (temp)
		{
			if (a->n_value > temp->n_value && temp->n_value > min)
			{
				min = temp->n_value;
				target = temp;
			}
			temp = temp->next;
		}
		if (min == LONG_MIN)
			a->target = find_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	real_sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int			args_a;
	t_ps_list	*smallest;
	int			args_b;

	args_a = ft_lstsize_ps(*stack_a);
	args_b = 0;
	while (args_b++ < 2 && args_a-- > 3 && !already_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (args_a-- > 3 && !already_sorted(*stack_a))
	{
		set_index(*stack_a, *stack_b);
		find_closest_smaller(*stack_a, *stack_b);
		find_cost(*stack_b, *stack_a);
		args_b = ft_lstsize_ps(*stack_b);
		move_cheapest_a_to_b(stack_a, stack_b, args_b);
	}
	simple_sort(stack_a);
	while (*stack_b)
	{
		args_a = ft_lstsize_ps(*stack_a);
		populate_list(*stack_a, *stack_b);
		move_cheapest(stack_a, stack_b, args_a);
	}
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
