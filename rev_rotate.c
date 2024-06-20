/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:38:17 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 14:23:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_ps_list **stack)
{
	t_ps_list	*temp;

	temp = *stack;
	*stack = ft_second_to_last(*stack);
	(*stack)->next = temp;
}

void	rra(t_ps_list **stack)
{
	rev_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_ps_list **stack)
{
	rev_rotate(stack);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_ps_list **a, t_ps_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("rrr", 1);
}
