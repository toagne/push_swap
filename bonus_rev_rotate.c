/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:38:17 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/25 12:08:57 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rev_rotate(t_ps_list **stack)
{
	t_ps_list	*temp;

	temp = *stack;
	*stack = ft_second_to_last(*stack);
	(*stack)->next = temp;
}

void	bonus_rra(t_ps_list **stack)
{
	if (*stack)
		rev_rotate(stack);
}

void	bonus_rrb(t_ps_list **stack)
{
	if (*stack)
		rev_rotate(stack);
}

void	bonus_rrr(t_ps_list **a, t_ps_list **b)
{
	if (*a)
		rev_rotate(a);
	if (*b)
		rev_rotate(b);
}
