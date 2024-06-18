/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:08:40 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/18 10:57:43 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "push_swap.h"

typedef struct s_ps_list
{
	int					n_value;
	int					index;
	int					cost;
	struct s_ps_list	*target;
	struct s_ps_list	*next;
}	t_ps_list;

long		ft_atol(const char *str);
char		**split_for_argc_2(char **str);
int			already_sorted(t_ps_list *a);
void		create_list(char **argv, t_ps_list **a, int argc);

int			check_errors(char **argv);
void		free_stack(t_ps_list **stack);
void		free_argv(char **str);

t_ps_list	*ft_lstnew_ps(int n);
t_ps_list	*ft_lstlast_ps(t_ps_list *lst);
void		ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new_node);
t_ps_list	*ft_second_to_last(t_ps_list *lst);
int			ft_lstsize_ps(t_ps_list *lst);
t_ps_list	*find_smallest(t_ps_list *stack);

void		checker_sa(t_ps_list **stack);
void		checker_sb(t_ps_list **stack);
void		checker_ss(t_ps_list **a, t_ps_list **b);
void		checker_ra(t_ps_list **stack);
void		checker_rb(t_ps_list **stack);
void		checker_rr(t_ps_list **a, t_ps_list **b);
void		checker_rra(t_ps_list **stack);
void		checker_rrb(t_ps_list **stack);
void		checker_rrr(t_ps_list **a, t_ps_list **b);
void		checker_pa(t_ps_list **a, t_ps_list **b);
void		checker_pb(t_ps_list **b, t_ps_list **a);

#endif
