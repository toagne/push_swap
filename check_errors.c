/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:28:06 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/31 16:44:09 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *str)
{
	int	c;

	c = 0;
	if (str[c] == '-')
		c++;
	while (str[c])
	{
		if (!(ft_isdigit(str[c])))
			return (0);
		c++;
	}
	return (1);
}

int	ft_isdup(long n, char**argv, int c)
{
	int		c1;
	long	n1;

	c1 = c + 1;
	while (argv[c])
	{
		n1 = ft_atoi(argv[c]);
		if (n == n1)
			return (0);
		c++;
	}
	return (1);
}

int	check_errors(char **argv)
{
	long	n;
	int		c;
//	char	**new_argv;

	c = 1;
//	if (argc == 2)
//		new_argv = ft_split(argv[1], ' ');
//	else
//		new_argv == argv;
	while (argv[c])
	{
		n = ft_atol(argv[c]);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		if (!(ft_isnum(argv[c])))
			return (0);
		if (!(ft_isdup(n, argv, c + 1)))
			return (0);
		c++;
	}
	return (1);
}
/*
int main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (!(check_errors(argv)))
	{
		ft_putendl_fd("error", 2);
		return (-1);
	}
}
*/
