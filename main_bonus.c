#include "push_swap_bonus.h"
#include <stdio.h>
/*
void ft_printf_a(t_ps_list *a)
{
	t_ps_list *temp;

	temp = a;
	while (temp)
	{
		printf("%d ", temp->n_value);
		temp = temp->next;
	}
}
*/
void	read_cmd(t_ps_list **a, t_ps_list **b)
{
	char	*cmd;

//	cmd = get_next_line(STDIN_FILENO);
	while ((cmd = get_next_line(STDIN_FILENO)) != NULL)
	{
//		len = 0;
//		while (str[len] != '\n')
//			len++;
//		cmd = (char *)malloc(sizeof(char) * (len + 1));
//		if (!cmd)
//			return ;
//		c1 = 0;
//		while (str[c] != '\n')
//		{
//			cmd[c1] = str[c];
//			c++;
//			c1++;
//		}
//		printf("%s", cmd);
		if (ft_strncmp(cmd, "sa\n", ft_strlen(cmd)) == 0)
			checker_sa(a);
		else if (ft_strncmp(cmd, "sb\n", ft_strlen(cmd)) == 0)
			checker_sb(b);
		else if (ft_strncmp(cmd, "ss\n", ft_strlen(cmd)) == 0)
                       checker_ss(a, b);
		else if (ft_strncmp(cmd, "pa\n", ft_strlen(cmd)) == 0)
                        checker_pa(a, b);
		else if (ft_strncmp(cmd, "pb\n", ft_strlen(cmd)) == 0)
                        checker_pb(b, a);
		else if (ft_strncmp(cmd, "ra\n", ft_strlen(cmd)) == 0)
                        checker_ra(a);
		else if (ft_strncmp(cmd, "rb\n", ft_strlen(cmd)) == 0)
                        checker_rb(b);
		else if (ft_strncmp(cmd, "rr\n", ft_strlen(cmd)) == 0)
                        checker_rr(a, b);
		else if (ft_strncmp(cmd, "rra\n", ft_strlen(cmd)) == 0)
                        checker_rra(a);
		else if (ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)) == 0)
                        checker_rrb(b);
		else if (ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)) == 0)
                        checker_rrr(a, b);
		else
		{
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			exit(1);
		}
//		cmd = get_next_line(STDIN_FILENO);
		free(cmd);
	}
//	ft_printf_a(*a);
	if (already_sorted(*a) && *b == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
	
	
int main(int argc, char **argv)
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
