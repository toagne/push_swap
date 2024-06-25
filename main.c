/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:30:19 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/24 12:11:52 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argv[1][0] == '\0')
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	else if (argc == 2)
		argv = split_for_argc_2(argv);
	create_list(argv, &stack_a, argc);
	if (!(already_sorted(stack_a)))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
}
