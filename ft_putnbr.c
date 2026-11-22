/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguir <kmarguir@learner.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:05:21 by kmarguir          #+#    #+#             */
/*   Updated: 2026/11/22 11:49:46 by kmarguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		num = -num;
	}
	if (num > 9 && ft_putnbr(num / 10) == -1)
		return (-1);
	if (ft_putchar(num % 10 + '0') == -1)
		return (-1);
	return (ft_nbrlen(n));
}
