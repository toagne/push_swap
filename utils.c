/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:06:37 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/10 16:17:26 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	n;
	int		m;

	n = 0;
	m = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
	{
		str++;
		m++;
	}
	else if (*str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	if (m == 1)
		return (-n);
	else
		return (n);
}

char	**split_for_argc_2(char **str)
{
	int		c;
	char	**temp;

	temp = NULL;
	c = 0;
	temp = ft_split(str[1], ' ');
	while (temp[c])
		c++;
	str = (char **)malloc(sizeof(char *) * (c + 2));
	if (!str)
		return (NULL);
	str[0] = (char *)malloc(sizeof(char));
	if (!str[0])
		return (NULL);
	str[0][0] = '\0';
	str[c + 1] = NULL;
	while (c--)
		str[c + 1] = temp[c];
	free(temp);
	return (str);
}

int	already_sorted(t_ps_list *a)
{
	while (a->next)
	{
		if (a->n_value > a->next->n_value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	create_list(char **argv, t_ps_list **a, int argc)
{
	t_ps_list	*new_lst;
	int			c;

	if (!(check_errors(argv)))
	{
		free_stack(a);
		if (argc == 2)
			free_argv(argv);
		ft_putendl_fd("Error", 2);
		exit (1);
	}
	c = 1;
	while (argv[c])
	{
		new_lst = ft_lstnew_ps(ft_atoi(argv[c]));
		ft_lstadd_back_ps(a, new_lst);
		c++;
	}
	if (argc == 2)
		free_argv(argv);
}
