/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:38:49 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/25 12:08:39 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_ps_list **stack)
{
	t_ps_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back_ps(stack, temp);
}

void	bonus_ra(t_ps_list **stack)
{
	if (*stack)
		rotate(stack);
}

void	bonus_rb(t_ps_list **stack)
{
	if (*stack)
		rotate(stack);
}

void	bonus_rr(t_ps_list **a, t_ps_list **b)
{
	if (*a)
		rotate(a);
	if (*b)
		rotate(b);
}
