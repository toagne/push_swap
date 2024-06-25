/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:39:33 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/25 10:04:03 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_ps_list **stack)
{
	t_ps_list	*temp;

	if (!*stack || (*stack)->next == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	bonus_sa(t_ps_list **stack)
{
	swap(stack);
}

void	bonus_sb(t_ps_list **stack)
{
	swap(stack);
}

void	bonus_ss(t_ps_list **a, t_ps_list **b)
{
	swap(a);
	swap(b);
}
