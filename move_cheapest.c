/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:32:00 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/12 16:11:13 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps_list	*find_cheapest(t_ps_list *stack)
{
	t_ps_list	*cheapest;
	int			min;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->cost)
		{
			min = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

void	move_cheapest(t_ps_list **a, t_ps_list **b, int n_a)
{
	t_ps_list	*cheapest;
	int			n_b;

	n_b = ft_lstsize_ps(*b);
	cheapest = find_cheapest(*b);
	if (cheapest->target->index <= n_a / 2 && cheapest->index <= n_a / 2)
	{
		while (*b != cheapest && *a != cheapest->target)
			rr(a, b);
		set_index(*a, *b);
	}
	else if (cheapest->target->index > n_a / 2 && cheapest->index > n_a / 2)
	{
		while (*b != cheapest && *a != cheapest->target)
			rrr(a, b);
		set_index(*a, *b);
	}
	while (*b != cheapest)
	{
		if (cheapest->index <= n_b / 2)
			rb(b);
		else
			rrb(b);
	}
	while (*a != cheapest->target)
	{
		if (cheapest->target->index <= n_a / 2)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}

void	move_cheapest_a_to_b(t_ps_list **a, t_ps_list **b, int n_b)
{
	t_ps_list	*cheapest;
	int			n_a;

	n_a = ft_lstsize_ps(*a);
	cheapest = find_cheapest(*a);
	if (cheapest->target->index <= n_b / 2 && cheapest->index <= n_a / 2)
	{
		while (*a != cheapest && *b != cheapest->target)
			rr(a, b);
		set_index(*a, *b);
	}
	else if (cheapest->target->index > n_b / 2 && cheapest->index > n_a / 2)
	{
		while (*a != cheapest && *b != cheapest->target)
			rrr(a, b);
		set_index(*a, *b);
	}
	while (*a != cheapest)
	{
		if (cheapest->index <= n_a / 2)
			ra(a);
		else
			rra(a);
	}
	while (*b != cheapest->target)
	{
		if (cheapest->target->index <= n_b / 2)
			rb(b);
		else
			rrb(b);
	}
	pb(b, a);
}
