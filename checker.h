/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:08:40 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/24 12:31:24 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "push_swap.h"

void		bonus_sa(t_ps_list **stack);
void		bonus_sb(t_ps_list **stack);
void		bonus_ss(t_ps_list **a, t_ps_list **b);
void		bonus_ra(t_ps_list **stack);
void		bonus_rb(t_ps_list **stack);
void		bonus_rr(t_ps_list **a, t_ps_list **b);
void		bonus_rra(t_ps_list **stack);
void		bonus_rrb(t_ps_list **stack);
void		bonus_rrr(t_ps_list **a, t_ps_list **b);
void		bonus_pa(t_ps_list **a, t_ps_list **b);
void		bonus_pb(t_ps_list **b, t_ps_list **a);

#endif
