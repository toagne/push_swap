/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:34:00 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 15:23:43 by mpellegr         ###   ########.fr       */
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

void	populate_list(t_ps_list *a, t_ps_list *b, char c)
{
	set_index(a, b);
	find_target(a, b, c);
	if (c == 'b')
		find_cost(a, b);
	else if (c == 'a')
		find_cost(b, a);
}
