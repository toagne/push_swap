/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:34:00 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/11 16:34:21 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_ps_list *a, t_ps_list *b)
{
	int	c;

	c = 0;
	while (a)
	{
		a->index = c;
		c++;
		a = a->next;
	}
	if (!b)
		return ;
	set_index(b, NULL);
}

t_ps_list	*find_smallest(t_ps_list *stack)
{
	t_ps_list	*smallest;
	int			min;

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

static void	find_smallest_bigger(t_ps_list *a, t_ps_list *b)
{
	long		max;
	t_ps_list	*temp;
	t_ps_list	*target;

	while (b)
	{
		max = LONG_MAX;
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
		if (max == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	find_cost(t_ps_list *a, t_ps_list *b)
{
	int	args;
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

void	populate_list(t_ps_list *a, t_ps_list *b)
{
	set_index(a, b);
	find_smallest_bigger(a, b);
	find_cost(a, b);
}
