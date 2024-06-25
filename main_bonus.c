/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:33:14 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/25 12:01:46 by mpellegr         ###   ########.fr       */
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

static void	cmd_error(t_ps_list **a, t_ps_list **b)
{
	free_stack(a);
	free_stack(b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	find_cmd(t_ps_list **a, t_ps_list **b, char *cmd)
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
		cmd_error(a, b);
}

void	read_cmd(t_ps_list **a, t_ps_list **b)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		find_cmd(a, b, cmd);
		free(cmd);
		cmd = NULL;
		cmd = get_next_line(STDIN_FILENO);
	}
	if (!*a)
	{
		ft_putendl_fd("KO", 2);
		free_stack(b);
		exit (1);
	}
	if (already_sorted(*a) && *b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argv[1][0] == '\0' || argv[1][0] == ' ')
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	else if (argc == 2)
		argv = split_for_argc_2(argv);
	create_list(argv, &stack_a, argc);
	read_cmd(&stack_a, &stack_b);
	free_stack(&stack_a);
}
