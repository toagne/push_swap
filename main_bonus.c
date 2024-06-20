/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:33:14 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/20 14:33:16 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

void	read_cmd(t_ps_list **a, t_ps_list **b)
{
	char	*cmd;

	while ((cmd = get_next_line(STDIN_FILENO)) != NULL)
	{
		if (ft_strcmp(cmd, "sa\n") == 0)
			bonus_sa(a);
		else if (ft_strcmp(cmd, "sb\n") == 0)
			bonus_sb(b);
		else if (ft_strcmp(cmd, "ss\n") == 0)
			bonus_ss(a, b);
		else if (ft_strcmp(cmd, "pa\n") == 0)
			bonus_pa(a, b);
		else if (ft_strcmp(cmd, "pb\n") == 0)
			bonus_pb(b, a);
		else if (ft_strcmp(cmd, "ra\n") == 0)
			bonus_ra(a);
		else if (ft_strcmp(cmd, "rb\n") == 0)
			bonus_rb(b);
		else if (ft_strcmp(cmd, "rr\n") == 0)
			bonus_rr(a, b);
		else if (ft_strcmp(cmd, "rra\n") == 0)
			bonus_rra(a);
		else if (ft_strcmp(cmd, "rrb\n") == 0)
			bonus_rrb(b);
		else if (ft_strcmp(cmd, "rrr\n") == 0)
			bonus_rrr(a, b);
		else
		{
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			free(cmd);
			exit(1);
		}
		free(cmd);
		cmd = NULL;
	}
	if (already_sorted(*a) && *b == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (argv[1][0] == '\0')
	{
		write (2, "Error\n", 6);
		exit (-1);
	}
	else if (argc == 2)
		argv = split_for_argc_2(argv);
	create_list(argv, &stack_a, argc);
	read_cmd(&stack_a, &stack_b);
	free_stack(&stack_a);
}
