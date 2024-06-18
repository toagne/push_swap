/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:37:01 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/18 10:59:22 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_ps_list **dest, t_ps_list **src)
{
	t_ps_list	*temp;

	if (!*src)
		return ;
	if (*dest == NULL)
	{
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = NULL;
	}
	else
	{
		temp = *dest;
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = temp;
	}
}

void	checker_pa(t_ps_list **a, t_ps_list **b)
{
	push(a, b);
//	ft_putendl_fd("pa", 1);
}

void	checker_pb(t_ps_list **b, t_ps_list **a)
{
	push(b, a);
//	ft_putendl_fd("pb", 1);
}
