/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:39:33 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/18 10:58:56 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	checker_sa(t_ps_list **stack)
{
	swap(stack);
//	ft_putendl_fd("sa", 1);
}

void	checker_sb(t_ps_list **stack)
{
	swap(stack);
//	ft_putendl_fd("sb", 1);
}

void	checker_ss(t_ps_list **a, t_ps_list **b)
{
	swap(a);
	swap(b);
//	ft_putendl_fd("ss", 1);
}
