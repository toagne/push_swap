/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:00:22 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 15:15:14 by mpellegr         ###   ########.fr       */
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

void	find_target(t_ps_list *a, t_ps_list *b, char c)
{
	if (c == 'a')
		find_closest_smaller(a, b);
	else if (c == 'b')
		find_smallest_bigger(a, b);
}
