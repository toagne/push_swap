/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:30 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/05 09:57:54 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_real_atol(const char *str, int m, long long int n)
{
	long	check;

	while (*str >= 48 && *str <= 57)
	{
		check = n * 10 + (*str - '0');
		if (check / 10 != n && m == 0)
			return (-1);
		else if (check / 10 != n && m == 1)
			return (0);
		str++;
		n = check;
	}
	return (n);
}

long	ft_atol(const char *str)
{
	long long int	n;
	int				m;

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
	n = ft_real_atol(str, m, n);
	if (m == 1)
		return (-n);
	else
		return (n);
}
