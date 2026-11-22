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

int	ft_unsigned_putnbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_unsigned_putnbr(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}
