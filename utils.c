/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:04:03 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/05 15:00:18 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*ft_lstnew_ps(int n)
{
	t_ps_list	*new_node;

	new_node = (t_ps_list *)malloc(sizeof(t_ps_list));
	if (!new_node)
		return (NULL);
	new_node->n_value = n;
	new_node->next = NULL;
	return (new_node);
}

t_ps_list	*ft_lstlast_ps(t_ps_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new_node)
{
	t_ps_list	*last_node;

	if (*lst == NULL)
	{
		*lst = new_node;
	}
	else
	{
		last_node = ft_lstlast_ps(*lst);
		last_node->next = new_node;
	}
}

t_ps_list	*ft_second_to_last(t_ps_list *lst)
{
	t_ps_list	*temp;

	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	temp = ft_lstlast_ps(lst);
	lst->next = NULL;
	return (temp);
}

int	ft_lstsize_ps(t_ps_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}
