/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:32:00 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 16:34:35 by mpellegr         ###   ########.fr       */
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

static void	final_rot(t_ps_list **s, t_ps_list *cheapest, char c, int args_s)
{
	while (*s != cheapest)
	{
		if (c == 'a')
		{
			if (cheapest->index <= args_s / 2)
				ra(s);
			else
				rra(s);
		}
		else if (c == 'b')
		{
			if (cheapest->index <= args_s / 2)
				rb(s);
			else
				rrb(s);
		}
	}
}

void	move_cheapest_b_to_a(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*cheapest;
	int			n_a;
	int			n_b;

	n_a = ft_lstsize_ps(*a);
	n_b = ft_lstsize_ps(*b);
	cheapest = find_cheapest(*b);
	if (cheapest->target->index <= n_a / 2 && cheapest->index <= n_b / 2)
	{
		while (*b != cheapest && *a != cheapest->target)
			rr(a, b);
		set_index(*a, *b);
	}
	else if (cheapest->target->index > n_a / 2 && cheapest->index > n_b / 2)
	{
		while (*b != cheapest && *a != cheapest->target)
			rrr(a, b);
		set_index(*a, *b);
	}
	final_rot(b, cheapest, 'b', n_b);
	final_rot(a, cheapest->target, 'a', n_a);
	pa(a, b);
}

void	move_cheapest_a_to_b(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*cheapest;
	int			n_a;
	int			n_b;

	n_a = ft_lstsize_ps(*a);
	n_b = ft_lstsize_ps(*b);
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
	final_rot(a, cheapest, 'a', n_a);
	final_rot(b, cheapest->target, 'b', n_b);
	pb(b, a);
}
