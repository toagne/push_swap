/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:38:49 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 14:23:31 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_ps_list **stack)
{
	t_ps_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back_ps(stack, temp);
}

void	ra(t_ps_list **stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_ps_list **stack)
{
	rotate(stack);
	ft_putendl_fd("rb", 1);
}

void	rr(t_ps_list **a, t_ps_list **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
