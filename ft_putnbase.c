/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguir <kmarguir@learner.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:19:43 by kmarguir          #+#    #+#             */
/*   Updated: 2026/11/22 11:47:07 by kmarguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbase(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len += ft_putnbase(nbr / 16, base);
	len += ft_putchar(base[nbr % 16]);
	return (len);
}
