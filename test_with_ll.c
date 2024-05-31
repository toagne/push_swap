#include "push_swap.h"
#include <stdio.h>

char    **split_for_argc_2(char **str,char **new_str, int argc)
{
    int     c;  
    char    **temp;

    temp = NULL;
    c = 0;
    if (argc == 2)
    {   
        temp = ft_split(str[1], ' ');
        while (temp[c])
            c++;
        new_str = (char **)malloc(sizeof(char *) * (c + 1));
        new_str[0] = NULL;
        new_str[c + 1] = NULL;
        while (c--)
            new_str[c + 1] = temp[c];
    }   
    else
        new_str = str;
    free(temp);
    return (new_str);
}

int main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
	char		**new_argv;
	t_ps_list	*temp;

	if (argc < 2 || argv[1][0] == '\0')
		return (-1);
	new_argv = NULL;
	new_argv = split_for_argc_2(argv, new_argv, argc); 
	if (!(check_errors(new_argv)))
	{
		ft_putendl_fd("error", 2);
		return (-1);
	}
	stack_a = NULL;
	stack_b = NULL;
	create_list(new_argv + 1, &stack_a);
	temp = stack_a;
	while (temp)
	{
		printf("%d ", temp->n_value);
		temp = temp->next;
	}
	printf("\n");
	if (already_sorted(stack_a))
	{
		free(stack_a);
		free(stack_b);
		return (1);
	}
	else
		sort(&stack_a, &stack_b, argc-1);
	while (stack_a)
	{
		printf("%d ", stack_a->n_value);
		stack_a = stack_a->next;
	}
	printf("\n");
}
