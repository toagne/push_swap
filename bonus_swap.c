/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:39:33 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 14:14:35 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_ps_list **a)
{
	t_ps_list	*temp;

	if (!a || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
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
