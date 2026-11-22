/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguir <kmarguir@learner.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 11:39:57 by kmarguir          #+#    #+#             */
/*   Updated: 2026/11/22 11:42:45 by kmarguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_length(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	if (n > 9 && ft_unsigned_putnbr(n / 10) == -1)
		return (-1);
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (ft_unsigned_length(n));
}
