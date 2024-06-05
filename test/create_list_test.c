/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:46:37 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/05 10:00:34 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	create_list(char **argv, t_ps_list **a)
{
	t_ps_list	*new_lst;

	while (*argv)
	{
		new_lst = ft_lstnew_ps(ft_atoi(*argv));
		ft_lstadd_back_ps(a, new_lst);
		argv++;
	}
}
