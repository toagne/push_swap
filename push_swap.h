/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:08:40 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/05 14:27:01 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
# include "libft/libft.h"

typedef struct s_ps_list
{
	int 				n_value;
	struct s_ps_list	*target;
	struct s_ps_list    *next;
}	t_ps_list;

long	ft_atol(const char *str);
int		check_errors(char **argv);
void	simple_sort(t_ps_list **a);

t_ps_list	*ft_lstnew_ps(int n);
t_ps_list	*ft_lstlast_ps(t_ps_list *lst);
void	ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new_node);
t_ps_list	*ft_second_to_last(t_ps_list *lst);
int	ft_lstsize_ps(t_ps_list *lst);

void	sa(t_ps_list **stack);
void	sb(t_ps_list **stack);
void    ss(t_ps_list **a, t_ps_list **b);
void	ra(t_ps_list **stack);
void	rb(t_ps_list **stack);
void	rr(t_ps_list **a, t_ps_list **b);
void	rra(t_ps_list **stack);
void	rrb(t_ps_list **stack);
void	rrr(t_ps_list **a, t_ps_list **b);

#endif
