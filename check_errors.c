/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:28:06 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/05 10:03:19 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(char *str)
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

static int	ft_isdup(long n, char**argv, int c)
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

	c = 1;
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
