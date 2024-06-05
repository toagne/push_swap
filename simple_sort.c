/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:33:32 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/05 13:29:38 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest(t_ps_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->n_value > max)
			max = stack->n_value;
		stack = stack->next;
	}
	return (max);
}

void	simple_sort(t_ps_list **a)
{
	int	biggest;

	biggest = find_biggest(*a);
	if ((*a)->n_value == biggest)
		ra(a);
	else if ((*a)->next->n_value == biggest)
		rra(a);
	if ((*a)->n_value > (*a)->next->n_value)
		sa(a);
}
