/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:33:32 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/31 16:32:31 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps_list **stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1);
}

void	ra(t_ps_list **stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	rra(t_ps_list **stack)
{
	rev_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	sort(t_ps_list **a, t_ps_list **b, int args)
{
	if (args == 3 && !*b)
	{
		if ((*a)->next->next->n_value > (*a)->n_value && (*a)->n_value > (*a)->next->n_value)
			sa(a);
		else if ((*a)->n_value > (*a)->next->n_value && (*a)->n_value > (*a)->next->next->n_value)
		{
			if ((*a)->next->n_value < (*a)->next->next->n_value)
				ra(a);
			else
			{
				ra(a);
				sa(a);
			}
		}
		else
		{
			if ((*a)->next->next->n_value < (*a)->next->n_value && (*a)->next->next->n_value < (*a)->n_value)
				rra(a);
			else
			{
				rra(a);
				sa(a);
			}
		}
	}
}
