/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:08:40 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/31 17:01:58 by mpellegr         ###   ########.fr       */
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
	struct s_ps_list	*next;
}	t_ps_list;

long	ft_atol(const char *str);
int		check_errors(char **argv);
void	create_list(char **argv, t_ps_list **a);
void	rotate(t_ps_list **stack);
void    swap(t_ps_list **stack);
void	sort(t_ps_list **a, t_ps_list **b, int args);
int		already_sorted(t_ps_list *a);
void	rev_rotate(t_ps_list **stack);

#endif
